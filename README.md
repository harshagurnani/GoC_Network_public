# GoC_Network_public
 Biophysical model of Golgi network - NeuroML2 description


## Biophysical Mechanisms

### Ion Channels
- Based on mod files from [Solinas et al, 2007](https://github.com/OpenSourceBrain/SolinasEtAl-GolgiCell/). Original publication: Solinas S, Forti L, Cesana E, Mapelli J, De Schutter E, D’Angelo E. Computational reconstruction of pacemaking and intrinsic electroresponsiveness in cerebellar Golgi cells. [Front Cell Neurosci. 2007;1:2](http://www.ncbi.nlm.nih.gov/pubmed/18946520)
- NeuroML2 implementation verified against OSB version of [Vervaeke et al. 2010](https://www.zenodo.org/badge/latestdoi/4960822). Original publication: Rapid Desynchronization of an Electrically Coupled Interneuron Network with Sparse Excitatory Synaptic Input, [Neuron 2010](http://www.sciencedirect.com/science/article/pii/S089662731000512X).

### Morphology
- Currently has reduced morphology in [GoC.cell.nml](https://github.com/harshagurnani/GoC_Network_public/blob/master/Golgi.cell.nml)

## Running simulations
Using NEURON for simulation (via pyneuroml)


From NML2 descriptions:

```python
python build_GoC_network.py   #
```
Generates:
- [NeuroML2 document for network](gocNetwork.nml)
- [LEMS simulation file](LEMS_sim_gocnetGoCl.xml)
- NML->mod file, hoc file for cell
- [NEURON-python simulation file](LEMS_sim_gocnetGoCl_nrn.py)

And compiles Mod files and runs the Nrn-python simulation if run==True

I'm currently editing the nrn-python file for random number generator seed initialisation in Python 3,x, and then running as:
```python
python LEMS_sim_gocnetGoCl_nrn.py 
```
