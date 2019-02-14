import numpy as np

# Sigmoid function
def nonlin(x, deriv=False):
    # Getting derivative???
    if(deriv == True):
        return x*(1-x)      
    
    # Sigmoid function turns a value into either a 1 or a 0
    return 1/(1+np.exp(-x)) 

# Input data
# 3 Inputs -> 1 Output
input_data = np.array([
    [0,0],      # Each row is an input sequence
    [0,1],
    [1,0],
    [1,1]
])

# Output data
output_data = np.array([
    [0],        # Each row is an output associated with an input sequence
    [1],
    [1],
    [0]
])

# Get total input and output neurons
total_sets = input_data.shape[0]
total_input_neurons = input_data.shape[1]
total_output_neurons = output_data.shape[1]

# Seed the random number generator
np.random.seed(1)

# Configure the hidden layers
total_hidden_layers = 2
total_hidden_neurons = 10

# Create synapses
synapses = []
# Syanpse to connect input to hidden layer = 0
new_synapse_layer = np.random.random((total_input_neurons, total_hidden_neurons))
synapses.append(new_synapse_layer)
# Synapses connecting hidden layers = 1...total_hidden_layers-1
for i in xrange(total_hidden_layers - 1):
    new_synapse_layer = np.random.random((total_hidden_neurons, total_hidden_neurons))
    synapses.append(new_synapse_layer)
# Syanpse to connect last hidden layer to output = total_hidden_layers
new_synapse_layer = np.random.random((total_hidden_neurons, total_output_neurons))
synapses.append(new_synapse_layer)

# Total training steps
total_iter = 30000
debug_iter = 10000

# Create layers matrix
layers = []
layers.append(input_data)               # Input layer = 0
for i in xrange(total_hidden_layers):   # Hidden neuron layers = 1...total_hidden_layers
    layers.append(np.zeros(shape=(total_sets, total_hidden_neurons)))
layers.append(np.zeros(shape=(total_sets, total_output_neurons)))   # Output layer = total_hidden_layers+1

# Layer deltas and errors
layer_deltas = [0]
layer_errors = [0]
for i in xrange(total_hidden_layers):
    new_layer = np.zeros(shape=(total_sets, total_hidden_neurons))
    layer_deltas.append(new_layer)
    layer_errors.append(new_layer)
new_layer = np.zeros(shape=(total_sets, total_output_neurons))
layer_deltas.append(new_layer)
layer_errors.append(new_layer)

# Start training the network
for iteration in xrange(total_iter):
    # Get all layer results
    for i in xrange(1, total_hidden_layers+2):
        layers[i] = nonlin(np.dot(layers[i-1], synapses[i-1]))
    
    # Get error from expected
    layer_errors[total_hidden_layers+1] = output_data - layers[total_hidden_layers+1]

    # Show debug for each nth step of the training
    if(iteration % debug_iter == 0):
        error_val = np.mean(np.abs(layer_errors[total_hidden_layers+1]))  # Get average difference between output from NN and expected output
        print("Error:" + str(error_val))

    # Get all layer deltas and errors
    for i in xrange(total_hidden_layers+1, 0, -1):
        layer_deltas[i] = layer_errors[i] * nonlin(layers[i], deriv=True)
        layer_errors[i-1] = layer_deltas[i].dot(synapses[i-1].T)
    
    # Apply deltas to the synapses
    for i in xrange(total_hidden_layers+1):
        synapses[i] += layers[i].T.dot(layer_deltas[i+1])

# Set DP of output
np.set_printoptions(precision=10, suppress=True)

# Print out the output after training
print("Output after training:")
print(layers[total_hidden_layers+1])

# Print out the synapse layers
for i in xrange(total_hidden_layers+1):
    print("Synapse Layer: " + str(i))
    print(synapses[i])

    
