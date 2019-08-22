import neuroml as nml
from pyneuroml import pynml
from pyneuroml.lems import LEMSSimulation
import lems.api as lems
import hashlib

import numpy as np
from scipy.spatial import distance
import math
import pickle as pkl
import sys
from pathlib import Path
import initialize_network_params as inp

def create_GoC_network( duration, dt, seed, runid, run=False):

	### ---------- Load Params
	noPar = True
	pfile = Path('params_file.pkl')
	if pfile.exists():
		print('Reading parameters from file:')
		file = open('params_file.pkl','rb')
		params_list = pkl.load(file)
		if len(params_list)>runid:
			p = params_list[runid]
			file.close()
	if noPar:
		p = inp.get_simulation_params( runid )
    
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
		
	# Create GoC population
	goc_pop = nml.Population( id=goc_type.id+"Pop", component = goc_type.id, type="populationList", size=p["nGoC"] )
	for goc in range( p["nGoC"] ):
		inst = nml.Instance( id=goc )
		goc_pop.instances.append( inst )
		inst.location = nml.Location( x=p["GoC_pos"][goc,0], y=p["GoC_pos"][goc,1], z=p["GoC_pos"][goc,2] )
	net.populations.append( goc_pop )


	### MF population
	MF_Poisson_pop = nml.Population(id=mf_poisson.id+"_pop", component=mf_poisson.id, type="populationList", size=p["nMF"])
	for mf in range( p["nMF"] ):
		inst = nml.Instance(id=mf)
		MF_Poisson_pop.instances.append( inst )
		inst.location = nml.Location( x=p["MF_pos"][mf,0], y=p["MF_pos"][mf,1], z=p["MF_pos"][mf,2] )		
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

	### 1. Background excitatory inputs: 	MF to GoC populations
	MFProjection = nml.Projection(id="MFtoGoC", presynaptic_population=MF_Poisson_pop.id, postsynaptic_population=goc_pop.id, synapse=MFSyn_type.id)
	net.projections.append(MFProjection)

	# MF_> GoC synapses (with syn_count equivalent to integer scaling of Mf synapse strength)
	nMFSyn = p["MF_GoC_pairs"].shape[1]
	ctr=0
	for syn in range( nMFSyn ):
		mf, goc = p["MF_GoC_pairs"][:, syn]
		for syn_count in range(p["MF_GoC_wt"][ctr]):
			conn2 = nml.Connection(id=ctr, pre_cell_id='../{}/{}/{}'.format(MF_Poisson_pop.id, mf, mf_poisson.id), post_cell_id='../{}/{}/{}'.format(goc_pop.id, goc, goc_type.id), post_segment_id='0', post_fraction_along="0.5")	#on soma
			MFProjection.connections.append(conn2)
			ctr+=1

	### 2. Perturbation as High Freq MF Inputs
	ctr=0
	for goc in p["Burst_GoC"]:
		for jj in range( p["nBurst"] ):				# Each Perturbed GoC gets nBurst random Burst sources
			inst = nml.ExplicitInput( id=ctr, target='../{}/{}/{}'.format(goc_pop.id, goc, goc_type.id), input=mf_burst.id, synapse=MF20Syn_type.id, spikeTarget='./{}'.format(MF20Syn_type.id))
			net.explicit_inputs.append( inst )
			ctr += 1

	### 3. Electrical coupling between GoCs
		
	GoCCoupling = nml.ElectricalProjection( id="gocGJ", presynaptic_population=goc_pop.id, postsynaptic_population=goc_pop.id )
	net.electrical_projections.append( GoCCoupling )
	dend_id = [1,2,5]
	for jj in range( p["GJ_pairs"].shape[0] ):
		conn = nml.ElectricalConnectionInstanceW( id=jj, pre_cell='../{}/{}/{}'.format(goc_pop.id, p["GJ_pairs"][jj,0], goc_type.id), pre_segment=dend_id[p["GJ_loc"][jj,0]], pre_fraction_along='0.5', post_cell='../{}/{}/{}'.format(goc_pop.id, p["GJ_pairs"][jj,1], goc_type.id), post_segment=dend_id[p["GJ_loc"][jj,1]], post_fraction_along='0.5', synapse=gj.id, weight=p["GJ_wt"][jj] )
		GoCCoupling.electrical_connection_instance_ws.append( conn )
		
		
	### --------------  Write files
		
	net_filename = 'gocNetwork.nml'
	pynml.write_neuroml2_file( net_doc, net_filename )

	simid = 'sim_gocnet_'+goc_type.id+'_run_{}'.format(runid)
	ls = LEMSSimulation( simid, duration=duration, dt=dt, simulation_seed=seed )
	ls.assign_simulation_target( net.id )
	ls.include_neuroml2_file( net_filename)
	ls.include_neuroml2_file( goc_filename)
	ls.include_neuroml2_file( MFSyn_filename)
	ls.include_neuroml2_file( MF20Syn_filename)
	
	
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
	runid=0
	if len(sys.argv)>1:
		runid=int(sys.argv[1])
	print('Generating network using parameters for runid=', runid)
	res = create_GoC_network( duration = 5000, dt=0.025, seed = 123, runid=runid)
	print(res)