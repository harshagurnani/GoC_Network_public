import neuroml as nml
from pyneuroml import pynml
from pyneuroml.lems import LEMSSimulation
import lems.api as lems

def create_test_goc1():
	simid = 'sim_goc2Pools'
	ls = LEMSSimulation( simid, duration=1500, dt=0.025, target='network' )
	
	#Load NeuroML components
	GoC_file_name = '..\Cells\Golgi\GoC_2Pools.cell.nml'
	ls.include_neuroml2_file( GoC_file_name )
	
	of0 = 'Volts_file'
	ls.create_output_file(of0, "%s.v.dat"%simid)
	ls.add_column_to_output_file(of0, 'v', "Golgi[0]/v")
	
	eof0 = 'Events_file'
	ls.create_event_output_file(eof0, "%s.v.spikes"%simid,format='ID_TIME')
	ls.add_selection_to_event_output_file(eof0, '0', "Golgi[0]", "spike")

	#Create Lems file to run
	lems_simfile = ls.save_to_file()

	#res = pynml.run_lems_with_jneuroml_neuron( lems_simfile, max_memory="1G", compile_mods =False, nogui=True, plot=False)
	res = pynml.run_lems_with_jneuroml_neuron( lems_simfile, max_memory="2G", only_generate_scripts = True, compile_mods = False, nogui=True, plot=False)

	return res

if __name__ =='__main__':
	res=create_test_goc1()
	print( res)