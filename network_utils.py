import numpy as np
from scipy.spatial import distance
import math

'''
 Helpers:
	- Distributing GoC in space
	- Setting up GJ coupling probability and conductance
'''

def GoC_locate( N=1, x=350,y=350,z=80):
	# Randomly distribute 'N' Golgi Cells in [0,x) X [0, y) X [0,z)
	GoC_pos = np.random.random( [N,3] ) * [x,y,z]  #in um
	#id = np.argsort( GoC_pos[:,1]+GoC_pos[:,2] )
	return GoC_pos

def GoC_density_locate( density=4607, x=350,y=350,z=80):
	# Randomly distribute Golgi Cells in [0,x) X [0, y) X [0,z) based on density
	# Density in cells/mm3, dimensions [x,y,z] in um
	N = int( density * 1e-9*x*y*z  ) # units um->mm
	GoC_pos = np.random.random( [N,3] ) * [x,y,z]  #in um
	#id = np.argsort( GoC_pos[:,1]+GoC_pos[:,2] )
	return GoC_pos

def GJ_conn( GoC_pos, prob_type='Boltzmann', GJw_type='Vervaeke2010' ):
	# modelling as single Gap junction between cells/mm3
	N_goc = GoC_pos.shape[0]
	radDist= distance.pdist( GoC_pos, 'euclidean' )
	
	if prob_type=='Boltzmann':
		isconn = connProb_Boltzmann( radDist )
	GJ_pairs = np.asarray(np.nonzero(isconn))
	GJ_pairs = np.asarray([GJ_pairs[:,jj] for jj in range(GJ_pairs.shape[1]) if GJ_pairs[0,jj]<GJ_pairs[1,jj]])	# N_pairs x 2 array = [cell1, cell2] of each pair
	
	radDist = distance.squareform(radDist)
	
	# Gap junction conductance as a function of distance
	if GJw_type == 'Vervaeke2010':
		GJ_cond = set_GJ_strength_Vervaeke2010( np.asarray([ radDist[GJ_pairs[jj,0], GJ_pairs[jj,1]] for jj in range(GJ_pairs.shape[0]) ]) ) #list of gj conductance for corresponding pair
	elif GJw_type == 'Szo16_oneGJ':
		GJ_cond = set_GJ_strength_Szo2016_oneGJ( np.asarray([ radDist[GJ_pairs[jj,0], GJ_pairs[jj,1]] for jj in range(GJ_pairs.shape[0]) ]) )
	return GJ_pairs, GJ_cond

def connProb_Boltzmann( radDist ):
	# Coupling prob as Boltzmann function - from Vervaeke 2010
	connProb = 1e-2 * (-1745 +  1836/( 1+np.exp((radDist-267)/39) ))
	connGen = np.random.random( radDist.shape )
	isconn = distance.squareform( (connProb - connGen)>0 ) # symmetric boolean matrix with diag=0 -> GJ or not
	return isconn
	
	
def set_GJ_strength_Vervaeke2010( radDist ):
	# Exponential fall-off of coupling coefficient, convert to GJ_cond
	CC = -2.3 + 29.7*np.exp(-radDist/70.4)	#Coupling coefficient

	GJw = 0.576 * np.exp(CC/12.4) + 0.00059 * np.exp(CC/2.79) - 0.564
	return GJw

def set_GJ_strength_Szo2016_oneGJ( radDist ):
	# Exponential fall-off of coupling coefficient, convert to GJ_cond as linear scaling
	CC = -2.3 + 29.7*np.exp(-radDist/70.4)	#Coupling coefficient
	#print(CC.shape)
	GJw = 2*np.around(CC/5)
	return GJw
	
def randdist_MF_syn( nMF, nGoC, pConn=0.1, nConn=0 ):
	''' 
	Randomly connect a population of nMF mossy fibres to nGoC Golgi cells, wither with probability of connection pConn with iid draws (default if pConn>0). Otherwise by choosing (without replacement) nConn fibres for each GoC i.e. same number of synapses for each GoC.
	'''
	if pConn > 0:
		connGen = np.random.random( (nMF, nGoC) )
		isconn = connGen < pConn

	else:
		isconn = np.zeros( (nMF, nGoC) )
		for goc in range(nGoC):
			isconn[np.random.permutation(nMF)[0:nConn], goc] = 1
	
	MF_Syn_list = np.asarray(np.nonzero(isconn))	
	return MF_Syn_list
	