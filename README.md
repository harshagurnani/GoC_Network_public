# GoC_Network_public
 Biophysical model of Golgi network - NeuroML2 description


## Biophysical Mechanisms

### Ion Channels
- Based on mod files from [Solinas et al, 2007](https://github.com/OpenSourceBrain/SolinasEtAl-GolgiCell/). Original publication: Solinas S, Forti L, Cesana E, Mapelli J, De Schutter E, D’Angelo E. Computational reconstruction of pacemaking and intrinsic electroresponsiveness in cerebellar Golgi cells. [Front Cell Neurosci. 2007;1:2](http://www.ncbi.nlm.nih.gov/pubmed/18946520)
- NeuroML2 implementation verified against OSB version of [Vervaeke et al. 2010](https://www.zenodo.org/badge/latestdoi/4960822). Original publication: Rapid Desynchronization of an Electrically Coupled Interneuron Network with Sparse Excitatory Synaptic Input, [Neuron 2010](http://www.sciencedirect.com/science/article/pii/S089662731000512X).

### Morphology
- Currently has reduced morphology in [GoC.cell.nml](https://github.com/harshagurnani/GoC_Network_public/blob/master/Golgi.cell.nml)


## Cells
- GoC.cell.nml has a single calcium pool to which both calcium currents write (slower spike rate due to more KAHP)
- GoC_2Pools.cell.nml has 2 Calcium pools, one of which is shielded from KAHP
- GoC_00XXX.cell.nml are 2Pool cells with different channel densities and spontaneous firing rate between 7 +/- 2 Hz

## Running simulations
Using NEURON for simulation (via pyneuroml)

Parameters can be initialised and stored in a separate file (default=10 parameter sets)
```bash
python initialize_network_params.py
```

The new network generator can load the params.pkl file to read network construction parameters (with an optional ID), or use the ID to make a call to the same parameter generation function:
```bash
python generate_network.py
python generate_network.py 2
```
This generates all mod files, network scripts, and Neuron-python simulation scripts.

I'm currently editing the nrn-python file for random number generator seed initialisation in Python 3,x {just change the function below as copied),
```python
#######
    # Hash function to use in generation of random value
    # This is copied from NetPyNE: https://github.com/Neurosim-lab/netpyne/blob/master/netpyne/simFuncs.py
    ###############################################################################
    def _id32 (self,obj): 
        return int(hashlib.md5(obj.encode('utf-8')).hexdigest()[0:8],16)  # convert 8 first chars of md5 hash in base 16 to int
```
Or directly use Python 2.7

To run simulation::
```bash
python LEMS_sim_gocnetGoCl_nrn.py 
python LEMS_sim_gocnet_GoCl_run_2_nrn.py 
```
