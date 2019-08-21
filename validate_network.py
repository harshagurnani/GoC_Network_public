import numpy as np
from scipy.spatial import distance
import math


'''
Check ntwork connectivity measures
'''

def gapJuncAnalysis( GJ_pairs, GJ_wt, nGoC=0 ):
	if nGoC==0:
		nGoC = np.amax( GJ_pairs)
	
	nGJ_per_cell = np.zeros(nGoC)
	net_GJ = np.zeros( nGoC )
	for goc in range( nGoC ):
		nGJ_per_cell[ goc ]= (GJ_pairs == goc).sum()
		net_GJ[ goc ] = GJ_wt[ GJ_pairs[:,0] == goc ].sum() + GJ_wt[ GJ_pairs[:,1] == goc ].sum()
		
	return nGJ_per_cell, net_GJ