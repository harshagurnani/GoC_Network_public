# Generates file binetwork_params.pkl -> parameters for full model og Golgi network with ON/OFF MF and PF inputs
# Run as: python initialize_bimodal_network_params.py
# Or load module and call get_simulation_params() withh different arguments

import numpy as np
from numpy.core import multiarray
import pickle as pkl

import sys
sys.path.append('../PythonUtils')
import network_utils as nu


def get_simulation_params(simid,
						  sim_durn = 8000,
                          nGoC=0,
						  nGoC_pop = 5,
						  densityParams = 'useParams_FI_14_25.pkl',
                          volume=[350,350,80],
						  GoC_loc_type='Density',
						  GoC_density=4607,
						  GJ_dist_type='Boltzmann',
						  GJ_wt_type='Szo16_oneGJ',
						  nGJ_dend =3,
						  input_types = ["MF_ON", "MF_OFF", "MF_bg", "PF_ON", "PF_OFF", "PF_bg", "Burst"],
						  nInputs_max = { "MF_ON": 60, "MF_OFF": 60, "MF_bg": 60, "PF_ON" : 300, "PF_OFF": 300, "PF_bg" : 300, "Burst" : 4 },
						  nInputs_frac = { "MF_ON": .55, "MF_OFF": .35, "MF_bg": .10, "PF_ON" : .45, "PF_OFF": .20, "PF_bg" : .35, "Burst" : 0 },
						  Input_density = { "MF_ON": 0, "MF_OFF": 0, "MF_bg": 0, "PF_ON" : 0, "PF_OFF": 0, "PF_bg" : 0, "Burst" : 0 },
						  Input_nRosette = { "MF_ON": 0, "MF_OFF": 0, "MF_bg": 0, "PF_ON" : 0, "PF_OFF": 0, "PF_bg" : 0, "Burst" : 0 },
						  Input_loc  = { "MF_ON" : 'random', 
										 "MF_OFF": 'random', 
										 "MF_bg" : 'random', 
										 "PF_ON" : 'random', 
										 "PF_OFF": 'random', 
										 "PF_bg" : 'random', 
										 "Burst" : 'random' 
									   },
						  Input_type = { "MF_ON" : 'transientPoisson', 
										 "MF_OFF": 'transientPoisson', 
										 "MF_bg" : 'poisson', 
										 "PF_ON" : 'transientPoisson', 
										 "PF_OFF": 'transientPoisson', 
										 "PF_bg" : 'poisson', 
										 "Burst" : 'transient' 
									   },
						  Input_rate = { "MF_ON" : [5, 100], 
										 "MF_OFF": [25, 2], 
										 "MF_bg" : [5], 
										 "PF_ON" : [2, 30], 
										 "PF_OFF": [20,1], 
										 "PF_bg" : [2], 
										 "Burst" : [100] 
									   },
						  Input_delay= { "MF_ON" : 2000, 
										 "MF_OFF": 2000, 
										 "MF_bg" : 0, 
										 "PF_ON" : 2000, 
										 "PF_OFF": 2000, 
										 "PF_bg" : 0, 
										 "Burst" : 2000 
									   },
						  Input_durn = { "MF_ON" : 2000, 
										 "MF_OFF": 2000, 
										 "MF_bg" : 0, 
										 "PF_ON" : 2000, 
										 "PF_OFF": 2000, 
										 "PF_bg" : 0, 
										 "Burst" : 2000 
									   },
						  Input_syn  = { "MF_ON" : 'MF_GoC_Syns.nml', 
										 "MF_OFF": 'MF_GoC_Syn.nml', 
										 "MF_bg" : 'MF_GoC_Syn.nml', 
										 "PF_ON" : 'PF_GoC_Syn.nml', 
										 "PF_OFF": 'PF_GoC_Syn.nml', 
										 "PF_bg" : 'PF_GoC_Syn.nml', 
										 "Burst" : 'MF_GoC_Syn.nml' 
									   },
						  Input_conn = { "MF_ON" : 'random_prob', 
										 "MF_OFF": 'random_prob', 
										 "MF_bg" : 'random_prob', 
										 "PF_ON" : 'random_prob', 
										 "PF_OFF": 'random_prob', 
										 "PF_bg" : 'random_prob', 
										 "Burst" : 'random_sample' 
									   },
						  Input_prob = { "MF_ON" : 0.3, 
										 "MF_OFF": 0.3, 
										 "MF_bg" : 0.3, 
										 "PF_ON" : 0.3, 
										 "PF_OFF": 0.8, 
										 "PF_bg" : 0.8, 
										 "Burst" : 0
									   },
						  Input_nGoC = { "MF_ON" : 0, 
										 "MF_OFF": 0, 
										 "MF_bg" : 0, 
										 "PF_ON" : 0, 
										 "PF_OFF": 0, 
										 "PF_bg" : 0, 
										 "Burst" : 0
									   },
						  Input_wt   = { "MF_ON" : 1, 
										 "MF_OFF": 1, 
										 "MF_bg" : 1, 
										 "PF_ON" : 1, 
										 "PF_OFF": 1, 
										 "PF_bg" : 1, 
										 "Burst" : 4
									   },
						  Input_maxD = { "MF_ON" : [300], 
										 "MF_OFF": [300], 
										 "MF_bg" : [300], 
										 "PF_ON" : [350, 2000, 500], 
										 "PF_OFF": [350, 2000, 500], 
										 "PF_bg" : [350, 2000, 500], 
										 "Burst" : [0] 
									   }
						  
						 ):


	params={}
	
	# 1. Golgi Population - Type, Location and Electrical Coupling

	params["nGoC"], params["GoC_pos"] = nu.locate_GoC( nGoC, volume, GoC_loc_type, GoC_density, seed=simid)

	params["nPop"] = nGoC_pop
	params["GoC_ParamID"], params["nGoC"] = nu.get_hetero_GoC_id( params["nGoC"], nGoC_pop, densityParams, seed=simid )
	popsize = params["nGoC"]/params["nPop"]
	params["nGoC_per_pop"] = popsize
	params["nGoC"], params["GoC_pos"] = nu.locate_GoC( params["nGoC"], volume, GoC_loc_type, GoC_density, seed=simid)
	
	usedID = np.unique( np.asarray( params["GoC_ParamID"]))
	# Get connectivity and sort into populations:
	params["econn_pop"] = [ [{} for post in range(nGoC_pop-pre)] for pre in range(nGoC_pop)]
	gj, wt, loc = nu.GJ_conn( params["GoC_pos"], GJ_dist_type, GJ_wt_type, nDend=nGJ_dend, seed=simid )
	
	for pre in range( nGoC_pop):
		for post in range(pre,nGoC_pop):
			pairid = [x for x in range(gj.shape[0]) if ((np.floor_divide(gj[x,1],popsize)==post) & (np.floor_divide(gj[x,0],popsize)==pre)) ]
			params["econn_pop"][pre][post-pre] = { "GJ_pairs": np.mod( gj[pairid,:], popsize), "GJ_wt": wt[pairid], "GJ_loc": loc[pairid,:] }
		
	
	params["Inputs"] = {}
	
	for input in input_types:
		Inp = { "type" : Input_type[input], "rate": Input_rate[input], "delay": Input_delay[input], "duration": Input_durn[input], "syn_type": Input_syn[input] }
		Inp["nInp"], Inp["pos"], Inp["conn_pairs"], Inp["conn_wt"] = nu.connect_inputs( maxn=nInputs_max[input], frac= nInputs_frac[input], density=Input_density[input], volume=volume, mult=Input_nRosette[input], loc_type=Input_loc[input], connType=Input_conn[input], connProb=Input_prob[input], connGoC=Input_nGoC[input], connWeight=Input_wt[input], connDist=Input_maxD[input], GoC_pos=params["GoC_pos"], seed=simid)
	
		tmp={ "conn_pairs": [], "conn_wt" : [] }
		if Inp["nInp"]>0:
			for pid in usedID:
				pairid = [x for x in range(Inp["conn_pairs"].shape[1]) if params["GoC_ParamID"][Inp["conn_pairs"][1,x]]==pid ]
				tmp["conn_pairs"].append( Inp["conn_pairs"][:,pairid] )
				tmp["conn_wt"].append( Inp["conn_wt"][pairid] )
			for key in ["conn_pairs", "conn_wt"] :
				Inp[key] = tmp[key]
			for jj in range( nGoC_pop):     
				Inp["conn_pairs"][jj][1,:]=np.mod(Inp["conn_pairs"][jj][1,:], popsize)
		
		params["Inputs"][input] = Inp
	
	return params
	
	
    
if __name__ =='__main__':

	nSim = 1
	params_list = [ get_simulation_params(simid) for simid in range(nSim) ]
	
	file = open('net_params_file.pkl','wb')
	pkl.dump(params_list,file); file.close()