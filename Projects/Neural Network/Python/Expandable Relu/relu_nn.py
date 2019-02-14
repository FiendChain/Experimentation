import numpy as np
import training
import logging as log

def softmax(x):
    logits_exp = np.exp(x)
    return logits_exp / np.sum(logits_exp, axis = 1, keepdims = True)

def relu_activation(data_array):
    return np.maximum(data_array, 0)

# config
log.basicConfig(filename="./debug.log", filemode='w', level=log.DEBUG)
np.random.seed()
printFormatter={"float": "{:0.2f}".format}
np.set_printoptions(formatter=printFormatter, precision=2, suppress=True) 

training_data = training.input_data
training_labels = training.output_data

hidden_nodes = 30
num_labels = training_labels.shape[1]
num_features = training_data.shape[1]
learning_rate = 0.2
reg_lambda = 0.01

# Weights and Bias Arrays, just like in Tensorflow
layer1_weights_array = np.random.normal(0, 1, [num_features, hidden_nodes]) 
layer2_weights_array = np.random.normal(0, 1, [hidden_nodes, num_labels]) 

layer1_biases_array = np.zeros((1, hidden_nodes))
layer2_biases_array = np.zeros((1, num_labels))

output_probs = 0

for step in range(1000):
    input_layer = np.dot(training_data, layer1_weights_array)
    hidden_layer = relu_activation(input_layer + layer1_biases_array)
    output_layer = np.dot(hidden_layer, layer2_weights_array) + layer2_biases_array
    output_probs = softmax(output_layer)
    loss = np.mean(np.abs(output_probs-training_labels))

    error_output = (output_probs - training_labels) / output_probs.shape[0]
    
    delta_layer2_weights = np.dot(hidden_layer.T, error_output)
    delta_layer2_bias = np.sum(error_output, axis = 0, keepdims = True)
    

    error_hidden = np.dot(error_output, layer2_weights_array.T) 
    error_hidden[hidden_layer <= 0] = 0
    delta_layer1_weights = np.dot(training_data.T, error_hidden)
    delta_layer1_bias = np.sum(error_hidden, axis = 0, keepdims = True)

    delta_layer2_weights += reg_lambda * layer2_weights_array
    delta_layer1_weights += reg_lambda * layer1_weights_array

    layer1_weights_array -= learning_rate * delta_layer1_weights
    layer1_biases_array -= learning_rate * delta_layer1_bias
    layer2_weights_array -= learning_rate * delta_layer2_weights
    layer2_biases_array -= learning_rate * delta_layer2_bias
    
    log.debug("Epoch {0}: {1}".format(step, loss))

for i in range(training_labels.shape[0]):
    loss = np.mean(np.abs(output_probs[i]-training_labels[i]))
    log.debug("{0}={1}: {2}".format(training_labels[i], output_probs[i], loss))


