import numpy as np

# Train a neural network and return the synapses
# Takes in a neuron count class and creates synapse matrix to fit 
# the defined neural network structure
def create_synapses(neuron_count, random_seed=1):         
    np.random.seed(random_seed)                          
    return create_random_synapses(neuron_count) 

# Create random synapses for training
def create_random_synapses(neuron_count):
    synapses = []
    neuron_count = [neuron_count.input]+list(neuron_count.hidden)+[neuron_count.output]
    total_layers = len(neuron_count)
    for i in range(total_layers-1):
        synapses.append(create_random_matrix(neuron_count[i], neuron_count[i+1]))
    return synapses

# Random matrix of given size
def create_random_matrix(row, col):
    return np.random.uniform(low=-1, high=1, size=(row, col))
