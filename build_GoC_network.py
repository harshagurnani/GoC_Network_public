import neuroml as nml
from pyneuroml import pynml
from pyneuroml.lems import LEMSSimulation
import lems.api as lems
import hashlib

import numpy as np
from scipy.spatial import distance
import math

import network_utils as nu
import validate_network as valnet

def create_GoC_network( duration, dt, seed, N_goc=0, N_mf=15, run=False, prob_type='Boltzmann', GJw_type='Vervaeke2010' ):

	### ---------- Component types
	goc_filename = 'GoC.cell.nml'							# Golgi cell with channels
	goc_file = pynml.read_neuroml2_file( goc_filename )
	goc_type = goc_file.cells[0]
	goc_ref = nml.IncludeType( href=goc_filename )

	MFSyn_filename = 'MF_GoC_Syn.nml'						# small conductance synapse for background inputs
	mfsyn_file = pynml.read_neuroml2_file( MFSyn_filename )
	MFSyn_type = mfsyn_file.exp_three_synapses[0]
	mfsyn_ref = nml.IncludeType( href=MFSyn_filename )
	
	MF20Syn_filename = 'MF_GoC_SynMult.nml'					# multi-syn conductance for strong/coincident transient input
	mf20syn_file = pynml.read_neuroml2_file( MF20Syn_filename )
	MF20Syn_type = mf20syn_file.exp_three_synapses[0]
	mf20syn_ref = nml.IncludeType( href=MF20Syn_filename )

	mf_type2 = 'spikeGeneratorPoisson'						# Spike source for background inputs
	mf_poisson = nml.SpikeGeneratorPoisson( id = "MF_Poisson", average_rate="5 Hz" )	# Not tuned to any data - qqq !
	
	mf_bursttype = 'transientPoissonFiringSynapse'			# Burst of MF input (as explicit input)
	mf_burst = nml.TransientPoissonFiringSynapse( id="MF_Burst", average_rate="100 Hz", delay="2000 ms", duration="500 ms", synapse=MF20Syn_type.id, spike_target='./{}'.format(MF20Syn_type.id) )

	gj = nml.GapJunction( id="GJ_0", conductance="426pS" )	# GoC synapse
	
	### --------- Populations

	# Build network to specify cells and connectivity
	net = nml.Network( id="gocNetwork", type="networkWithTemperature" , temperature="23 degC" )
	
	### Golgi cells
	if N_goc>0:
		GoC_pos = nu.GoC_locate(N_goc)
	else:
		GoC_pos = nu.GoC_density_locate()
		N_goc = GoC_pos.shape[0]
		
	# Create GoC population
	goc_pop = nml.Population( id=goc_type.id+"Pop", component = goc_type.id, type="populationList", size=N_goc )
	for goc in range(N_goc):
		inst = nml.Instance( id=goc )
		goc_pop.instances.append( inst )
		inst.location = nml.Location( x=GoC_pos[goc,0], y=GoC_pos[goc,1], z=GoC_pos[goc,2] )
	net.populations.append( goc_pop )


	### MF population
	MF_Poisson_pop = nml.Population(id=mf_poisson.id+"_pop", component=mf_poisson.id, type="populationList", size=N_mf)
	MF_pos = nu.GoC_locate( N_mf )
	for mf in range( N_mf ):
		inst = nml.Instance(id=mf)
		MF_Poisson_pop.instances.append( inst )
		inst.location = nml.Location( x=MF_pos[mf,0], y=MF_pos[mf,1], z=MF_pos[mf,2] )		
	net.populations.append( MF_Poisson_pop )
	
	# Create NML document for network specification
	net_doc = nml.NeuroMLDocument( id=net.id )
	net_doc.networks.append( net )
	net_doc.includes.append( goc_ref )
	net_doc.includes.append( mfsyn_ref )
	net_doc.includes.append( mf20syn_ref )
	net_doc.spike_generator_poissons.append( mf_poisson )	
	net_doc.transient_poisson_firing_synapses.append( mf_burst )
	net_doc.gap_junctions.append(gj)
	
	
	### ------------ Connectivity

	### background excitatory inputs: 	MF to GoC populations
	MFProjection = nml.Projection(id="MFtoGoC", presynaptic_population=MF_Poisson_pop.id, postsynaptic_population=goc_pop.id, synapse=MFSyn_type.id)
	net.projections.append(MFProjection)

	#Get list of MF->GoC synapse
	mf_synlist = nu.randdist_MF_syn( N_mf, N_goc, pConn=0.3)		# Not tuned to any data - qqq!
	nMFSyn = mf_synlist.shape[1]
	for syn in range( nMFSyn ):
		mf, goc = mf_synlist[:, syn]
		conn2 = nml.Connection(id=syn, pre_cell_id='../{}/{}/{}'.format(MF_Poisson_pop.id, mf, mf_poisson.id), post_cell_id='../{}/{}/{}'.format(goc_pop.id, goc, goc_type.id), post_segment_id='0', post_fraction_along="0.5")	#on soma
		MFProjection.connections.append(conn2)

	
	### Add few burst inputs
	n_bursts = 4
	gocPerm = np.random.permutation( N_goc )		# change to central neurons later -qqq !!!
	ctr = 0
	for gg in range(4):
		goc = gocPerm[gg]
		for jj in range( n_bursts ):
			inst = nml.ExplicitInput( id=ctr, target='../{}/{}/{}'.format(goc_pop.id, goc, goc_type.id), input=mf_burst.id, synapse=MF20Syn_type.id, spikeTarget='./{}'.format(MF20Syn_type.id))
			net.explicit_inputs.append( inst )
			ctr += 1

	### Electrical coupling between GoCs

	# get GJ connectivity
	GJ_pairs, GJWt = nu.GJ_conn( GoC_pos, prob_type, GJw_type )
	#tmp1, tmp2 = valnet.gapJuncAnalysis( GJ_pairs, GJWt )
	#print("Number of gap junctions per cell: ", tmp1)
	#print("Net GJ conductance per cell:", tmp2)
		
	# Add electrical synapses
	GoCCoupling = nml.ElectricalProjection( id="gocGJ", presynaptic_population=goc_pop.id, postsynaptic_population=goc_pop.id )
	nGJ = GJ_pairs.shape[0]
	for jj in range( nGJ ):
		conn = nml.ElectricalConnectionInstanceW( id=jj, pre_cell='../{}/{}/{}'.format(goc_pop.id, GJ_pairs[jj,0], goc_type.id), pre_segment='1', pre_fraction_along='0.5', post_cell='../{}/{}/{}'.format(goc_pop.id, GJ_pairs[jj,1], goc_type.id), post_segment='1', post_fraction_along='0.5', synapse=gj.id, weight=GJWt[jj] )
		GoCCoupling.electrical_connection_instance_ws.append( conn )
	net.electrical_projections.append( GoCCoupling )	
		
		
	### --------------  Write files
		
	net_filename = 'gocNetwork.nml'
	pynml.write_neuroml2_file( net_doc, net_filename )
	#lems_filename = 'instances.xml'
	#pynml.write_lems_file( lems_inst_doc, lems_filename, validate=False )

	simid = 'sim_gocnet'+goc_type.id
	ls = LEMSSimulation( simid, duration=duration, dt=dt, simulation_seed=seed )
	ls.assign_simulation_target( net.id )
	
	ls.include_neuroml2_file( net_filename)
	ls.include_neuroml2_file( goc_filename)
	ls.include_neuroml2_file( MFSyn_filename)
	ls.include_neuroml2_file( MF20Syn_filename)
	#ls.include_lems_file( lems_filename, include_included=False)
	
	
	# Specify outputs
	eof0 = 'Events_file'
	ls.create_event_output_file(eof0, "%s.v.spikes"%simid,format='ID_TIME')
	for jj in range( goc_pop.size):
		ls.add_selection_to_event_output_file( eof0, jj, '{}/{}/{}'.format( goc_pop.id, jj, goc_type.id), 'spike' )
		
	of0 = 'Volts_file'
	ls.create_output_file(of0, "%s.v.dat"%simid)
	for jj in range( goc_pop.size ):
		ls.add_column_to_output_file(of0, jj, '{}/{}/{}/v'.format( goc_pop.id, jj, goc_type.id))
		
	#Create Lems file to run
	lems_simfile = ls.save_to_file()


	if run:
		res = pynml.run_lems_with_jneuroml_neuron( lems_simfile, max_memory="2G", nogui=True, plot=False)
	else:
		res = pynml.run_lems_with_jneuroml_neuron( lems_simfile, max_memory="2G", only_generate_scripts = True, compile_mods = False, nogui=True, plot=False)
	
	
	return res

	
if __name__ =='__main__':
	res = create_GoC_network( duration = 5000, dt=0.025, seed = 123, GJw_type = 'Szo16_oneGJ')
	print(res)