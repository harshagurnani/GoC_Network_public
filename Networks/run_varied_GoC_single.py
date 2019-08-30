import neuroml as nml
from pyneuroml import pynml
from pyneuroml.lems import LEMSSimulation
import lems.api as lems

import numpy as np
import math
import pickle as pkl
import sys
from pathlib import Path

def create_GoC_network( duration = 2000, dt=0.025, seed = 123, runid=0, run=False, girk=False ):

	wGirk = ''
	### ---------- Component types
	gocID = 'GoC_'+format(runid, '05d')
	if girk:
		wGirk = '_wGirk'
		gocID = gocID+ wGirk
	goc_filename = '../Cells/Golgi/{}.cell.nml'.format(gocID)	
	goc_type = pynml.read_neuroml2_file( goc_filename ).cells[0]
	
	### --------- Populations

	# Build network to specify cells and connectivity
	net = nml.Network( id='GoCNet_'+format(runid,'05d')+ wGirk, type="networkWithTemperature" , temperature="23 degC" )
		
	# Create GoC population
	goc_pop = nml.Population( id=goc_type.id+"Pop", component = goc_type.id, type="populationList", size=1 )
	inst = nml.Instance( id=0 )
	goc_pop.instances.append( inst )
	inst.location = nml.Location( x=0, y=0, z=0 )
	net.populations.append( goc_pop )

	
	# Create NML document for network specification
	net_doc = nml.NeuroMLDocument( id=net.id )
	net_doc.networks.append( net )
	net_doc.includes.append( nml.IncludeType( href=goc_filename ) )
		
	### --------------  Write files
		
	net_filename = 'GoCNet_'+format(runid,'05d')+ wGirk+'.net.nml'
	pynml.write_neuroml2_file( net_doc, net_filename )

	simid = 'sim_gocnet_'+goc_type.id
	ls = LEMSSimulation( simid, duration=duration, dt=dt, simulation_seed=seed )
	ls.assign_simulation_target( net.id )
	ls.include_neuroml2_file( net_filename)
	ls.include_neuroml2_file( goc_filename )
	
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
	girk=False
	if len(sys.argv)>1:
		runid=int(sys.argv[1])
	if len(sys.argv)>2:
		girk=sys.argv[2]
	print('Generating network using parameters for runid=', runid)
	res = create_GoC_network( duration = 2000, dt=0.025, seed = 123, runid=runid, girk=girk)
	print(res)