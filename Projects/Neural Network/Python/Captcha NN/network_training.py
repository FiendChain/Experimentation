import numpy as np                          # For matrix math
import logging as log
import activation_functions

'''
    Network_Layers class used for training and testing a neural network
    The following class supports:
    
        * intermediate layer created for training and testing
            - layers contain neuron values in the hidden layer for all sets
              of a given input data
            - an input matrix is seeded using initialise_input method
            - the apply_feed_forward method can propagate the input matrix to
              get all the respective neuron values

        * training using batch gradient descent
            - given output is compared to expected output to get error
            - this is then multiplied to the gradient descent of the layer value
            - delta = error * derivative(value) 
                => error weighted sum
                => the use of the derivative is called gradient descent
            - error_prev = delta.dot(value_prev.Transpose)
                => getting error in previous layer using calculated delta
            - this process of getting delta to get error in prev layer is called backprop

        * selectable training rate
            - to adjust weights, we multiply each layer by their calculated delta
            - weights_new = weights_old * delta * training_rate
            - training rate determines how quickly the weights are changed
                => high training rate might cause the network to skip over the
                   minimum error loss
                => low training rate will cause slow training times, and possibly
                   cause the network to fall into a suboptimal local minima
                => itermediate training rate will result in normal training times
                   and reduce likelyhood of falling into a local minima

        * selectable activation function
            - supports: sigmoid, inverse tan, relu, leaky relu
            - NOTE: relu and leaky_relu do not work
            - relu and leaky_relu have softmax applied to the final output neurons
            - inverse tan activation function is scaled horizontally and
              vertically so that neuron values fall within 0 and 1 to match
              network archeitecture

        * stores the loss history of the network as it is trained
            - the loss history will be appended to the provided array in arguments
            - this can later be graphed using the show_loss_history() method in
              the Neural_Network class in network_classes.py

'''
class Network_Layers:
    def __init__(self, total_layers, function='sigmoid'):
        self.values = [0] * total_layers
        self.deltas = [0] * total_layers
        self.errors = [0] * total_layers
        self.total_layers = total_layers
        self.input_init = False
        self.valid_functions = {'sigmoid':    activation_functions.sigmoid, 
                                'relu':       activation_functions.relu,
                                'leaky_relu': activation_functions.leaky_relu,
                                'inverse_tan':activation_functions.inverse_tan}
        self.apply_softmax = False
        self.select_function(function)
    
    def select_function(self, function):
        if(function in self.valid_functions):
            self.activation_function = self.valid_functions[function]
            if(function == 'relu' or function == 'leaky_relu'):
                self.apply_softmax = True
            log.debug("function = {0}".format(function))
            log.debug("softmax = {0}".format(self.apply_softmax))
        else:
            self.activation_function = self.valid_functions["sigmoid"]
            log.warn("{0} is not a valid function, defaulting to sigmoid".format(function))

    def initialise_input(self, input_data): # Seed the input neurons
        self.values[0] = input_data
        self.input_init = True

    def apply_feed_forward(self, synapses):
        for i in range(1, self.total_layers):
            self.values[i] = self.activation_function(np.dot(self.values[i-1], synapses[i-1]))
        if(self.apply_softmax == True):
            self.values[-1] = activation_functions.softmax(self.values[-1])

    def get_output_error(self, output_data):
        self.errors[-1] = output_data - self.values[-1] # index -1 is last index

    def get_mean_error(self):
        error_val = np.mean(np.abs(self.errors[-1]))
        return error_val    

    def get_delta_using_gradient_descent(self, synapses):
        for i in range(self.total_layers-1, 0, -1):
            self.deltas[i] = self.errors[i] * self.activation_function(self.values[i], deriv=True)  # Error weighted derivative
            self.errors[i-1] = self.deltas[i].dot(synapses[i-1].T)

    def back_propagate(self, synapses, learning_rate):
        for i in range(self.total_layers-1):
            synapses[i] += self.values[i].T.dot(self.deltas[i+1]) * learning_rate

    def perform_training_cycle(self, synapses, expected_output, learning_rate):
        self.apply_feed_forward(synapses)    
        self.get_output_error(expected_output)
        self.get_delta_using_gradient_descent(synapses)
        self.back_propagate(synapses, learning_rate)


def train_synapses(training_data, synapses, training_config, error_history):
    log.info('[Training neural network]')
    total_layers = len(synapses)+1
    layers = Network_Layers(total_layers, function=training_config.function)
    layers.initialise_input(training_data.input)
    for epoch in range(training_config.epochs):
        layers.perform_training_cycle(synapses, 
                                        training_data.output, 
                                        training_config.learning_rate)
        error_val = layers.get_mean_error()
        error_history.append(error_val)
        if(training_config.debug == True):
            log.debug("Epoch {0}: {1}".format(epoch, error_val))
        if(error_val <= training_config.target_error):
            log.info("Target error reached: {0}".format(error_val))
            break
