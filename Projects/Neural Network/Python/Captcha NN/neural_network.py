import logging as log
import numpy as np
import os
# Data imports
import training
import testing
# Relevant class imports 
from network_classes import Neural_Network
from network_classes import Data_Package

def main():
    np.set_printoptions(precision=1,suppress=True)
    # Configure directory of neural network files
    function = "sigmoid"
    directory = "./captcha_nn_{0}".format(function)
    if not os.path.exists(directory):
        os.makedirs(directory)
    # Logging options
    log_path = "{0}/{1}.log".format(directory, "debug")
    log.basicConfig(filename=log_path, filemode='w', level=log.ERROR)
    # Set training configuration for neural network
    training_config = {"epochs": 10000, "target_error": 0.0,
                       "debug": True, "learning_rate": 1,
                       "function": function}
    # Get training and testing data
    training_data = Data_Package(training, shuffle=True)
    testing_data = Data_Package(testing)
    # Create neural network
    neural_network = Neural_Network(directory=directory)
    neural_network.set_hidden_layer(32)
    neural_network.set_training_config(**training_config)
    neural_network.training_config.describe()
    neural_network.load_synapses("synapses-0.npy")
    # neural_network.train(training_data)
    neural_network.describe()
    neural_network.graph_loss_history()
    # neural_network.save_synapses("synapses-0")
    neural_network.test(testing_data, test_type='digits', debug=True, graph=True)
    neural_network.show_synapses()
    neural_network.get_hidden_neuron_heatmaps()

    # just print out
    # neural_network.load_synapses("synapses-0.npy")
    # neural_network.show_c_synapses()


if(__name__ == "__main__"):
    main()
