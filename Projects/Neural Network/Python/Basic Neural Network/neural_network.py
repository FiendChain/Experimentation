import numpy as np

# Sigmoid function
def nonlin(x, deriv=False):
    # ???
    if(deriv == True):
        return x*(1-x)      
    
    # Sigmoid function turns a value into either a 1 or a 0
    return 1/(1+np.exp(-x)) 

# Input data
# 3 Inputs -> 1 Output
input_data = np.array([
    [0,0,1],    # Each row is an input sequence
    [0,1,1],
    [1,0,1],
    [1,1,1]
])

# Output data
output_data = np.array([
    [0],        # Each row is an output associated with an input sequence
    [0],
    [1],
    [1]
])

# Seed the random number generator
np.random.seed(1)

# Total neurons in hidden network
total_hidden_neurons = 4

# Synapse layers
synapse_0 = np.random.random((3,total_hidden_neurons))
synapse_1 = np.random.random((total_hidden_neurons,1))

# Training step
total_iter = 60000
debug_iter = 10000

for iteration in xrange(total_iter):
    # Get values of each layer after input is given
    layer_0 = input_data
    layer_1 = nonlin(np.dot(layer_0, synapse_0))    # Get the values of the hidden neurons for each sequence of inputs, and pass through sigmoid function
    layer_2 = nonlin(np.dot(layer_1, synapse_1))    # Get the values of the output neurons given hidden neurons, and pass through sigmoid function

    # Get error from expect
    layer_2_error = output_data - layer_2

    # Show debug for each nth step of the training
    if(iteration % debug_iter == 0):
        error_val = np.mean(np.abs(layer_2_error))  # Get average difference between output from NN and expected output
        print("Error:" + str(error_val))
    
    # 
    layer_2_delta = layer_2_error * nonlin(layer_2, deriv=True)

    # Get error of layer 1
    layer_1_error = layer_2_delta.dot(synapse_1.T)

    # 
    layer_1_delta = layer_1_error * nonlin(layer_1, deriv=True)

    # Update weights to reduce error
    # This is gradient descent
    synapse_0 += layer_0.T.dot(layer_1_delta)
    synapse_1 += layer_1.T.dot(layer_2_delta)

# Print out the output after training
print("Output after training:")
print(layer_2)