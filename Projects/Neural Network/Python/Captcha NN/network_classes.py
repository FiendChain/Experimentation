# System imports
import logging as log
import matplotlib.pyplot as plt
import numpy as np
import os
import traceback
# Custom imports
from check_network_output import check_output
from network_creation import create_synapses
from network_training import Network_Layers
from network_training import train_synapses 

'''
    Main class used for neural network construction, training and testing
    Neural_Network class supports: 
        * selectable directory
            - load and save trained synapses
            - save data for loss history during training
            - store results for testing phase
            - heatmap of each neuron
            
        * selectable training and testing data => Data_Package
            - data will be collected from specialised class
            - will include original dimensions for input before reshape
            - includes neuron counts for input and output 
            
        * configurable training setup => Training_Config class
            - selectable epochs
            - debugging error from each epoch
            - target error
            - type of activation function
            - learning rate
            
        * configurable archeitecture
            - can select total hidden layers
            - can determine number of hidden neurons in each hidden layer
            
    Classes that this class depends on includes:
        * Network_Layers
            - used when training and testing
            - includes methods to feed forward input neurons for training and testing
            - has batch gradient descent and backprop for training
            
        * Neuron_Count
            - updated when synapse is loaded => selects input, output and hidden 
            - updated when training data is provided => select input and output
            - when the neuron count is determined, it checks data to see if 
              archeitecture is compatible, including:
                - loading synapses then trying to train with incorrectly sized data
                - loading synapses then trying to test with incorrectly sized data
                - training network then testing with incorrectly sized data
                
        * Training_Config
            - contains information used to determine type of training
            - selectable activation functions including:
                - sigmoid
                - inverse_tan
                - relu (not working)
                - leaky_relu (not working)
            - NOTE: Can be replaced with a dictionary for higher performance, but
                    less aesthetic code syntax
'''
class Neural_Network:
    def __init__(self, directory='./default_dir'):
        self.training_config = Training_Config()        
        self.neuron_count = Neuron_Count(None,None,[])  
        self.synapses_built = False                     
        self.input_dimensions = None                    
        self.error_history = []         
        self.set_directory(directory)               

    '''
        set_training_cycles = Accepts a dictionary and configures the training
                              configuration of the network
        set_hidden_layer = Determining the hidden section of the network, by
                           specifying the number of hidden neurons for each layer
        train = Accepts training data and trains the synapses
        validate_synapse = If a synapse was preloaded, determine if it fits the
                           provided training data
    '''
    def set_training_config(self, **options):
        self.training_config.set(**options)

    def set_hidden_layer(self, *hidden_neurons):
        self.neuron_count.hidden = list(hidden_neurons)

    def train(self, training_data):
        if(self.synapses_built == False):
            self.neuron_count.input = training_data.total_input_neurons
            self.neuron_count.output = training_data.total_output_neurons
            self.synapses = create_synapses(self.neuron_count)
            self.synapses_built = True
        elif(self.validate_synapse(training_data) == False):
            log.error("Aborting training of neural network!")
            return
        self.input_dimensions = training_data.input_dimensions  # train if data is suitable
        train_synapses(training_data, self.synapses, self.training_config, self.error_history)

    def validate_synapse(self, data):
        synapse_match = True
        if(data.total_input_neurons != self.neuron_count.input):
            synapse_match = False
        if(data.total_output_neurons != self.neuron_count.output):
            synapse_match = False
        if(synapse_match == False):
            log.error("Provided synapses have mismatching dimensions!")
            log.error("For inputs, expected: {0}, got: {1}".format(self.neuron_count.input, data.total_input_neurons))
            log.error("For outputs: expected {0}, got: {1}".format(self.neuron_count.input, data.total_output_neurons))
        return synapse_match

    '''
        set_directory = Sets the directory to save and load files from
        load_synapses = Gets the synapses from a filename, and updates the
                        neuron_count class to configure the network
        save_synapses = Saves the synapses to a filename
        get_neuron_count_from_synapse = Update neuron count for a differently
                                        structured set of synapses
    '''
    def set_directory(self, directory):
        self.folders = {
            "root":     "{0}".format(directory),
            "training": "{0}/training".format(directory),
            "synapses": "{0}/synapses".format(directory),
            "testing":  "{0}/testing".format(directory),
            "hidden":   "{0}/hidden_neurons".format(directory)
        } 
        for folder in self.folders: # Create folders if they dont exist      
            folder_path = self.folders[folder]
            if not os.path.exists(folder_path):
                os.makedirs(folder_path)
                log.info("Generated: {0}".format(folder_path))

    def load_synapses(self, filename):
        try:
            load_path = "{0}/{1}".format(self.folders["synapses"], filename)
            self.synapses = np.load(load_path)
            log.info("Loaded synapses from: {0}".format(load_path))
            self.synapses_built = True
            self.get_neuron_count_from_synapses()
        except Exception as e:
            log.error(traceback.format_exc())
            log.error("Couldn't load synapses from: {0}".format(load_path))

    def save_synapses(self, filename):
        if(self.synapses_built == False):
            log.error("Cannot save since synapses have not been built!")
            return
        save_path = "{0}/{1}.npy".format(self.folders["synapses"], filename)
        np.save(save_path, self.synapses)
        log.info("Saved to: " + filename + ".npy")

    def get_neuron_count_from_synapses(self):
        self.neuron_count.input = self.synapses[0].shape[0]
        self.neuron_count.output = self.synapses[-1].shape[1]
        self.neuron_count.hidden = []
        for i in range(len(self.synapses)-1):
            self.neuron_count.hidden.append(self.synapses[i].shape[1])

    
    '''
        show_synapses = Give a standard numpy output of the synapses
        show_c_synapses = Give a c-formattd output of the synapses
    '''

    def show_synapses(self):
        if(self.synapses_built == False):
            log.error("Cannot show since synapses have not been built!")
            return
        for i in range(len(self.synapses)):
            log.info("[Synapse Layer %d]", i)
            log.info(self.synapses[i])

    def show_c_synapses(self, filename="c_synapses.txt"):
        if(self.synapses_built == False):
            log.error("Cannot show since synapses have not been built!")
            return
        save_path = "{0}/{1}".format(self.folders["synapses"], filename)
        file = open(save_path, "w")
        for index, synapse in enumerate(self.synapses):
            file.write("[Synapse Layer {0}]\n".format(index))
            file.write("double m[{0}][{1}] = ".format(synapse.shape[0], synapse.shape[1]))
            file.write("{\n")
            for row in range(synapse.shape[0]):
                file.write("\t{")
                for col in range(synapse.shape[1]):
                    file.write("{0}".format(synapse[row][col]))
                    if col is not synapse.shape[1]-1:
                        file.write(",")
                    
                file.write("},\n")
            file.write("}\n")

    '''
        test_data = Give it test data to check the error of the network
        get_output = Give it input data and get the output from the network
    '''
    def test(self, test_data, **options):
        if(self.synapses_built == False):
            log.error("Cannot test, synapses not built")
            return
        elif(self.validate_synapse(test_data) == False):
            log.error("Aborting testing of neural network!")
            return
        elif(self.input_dimensions != test_data.input_dimensions):
            if(self.input_dimensions == None):
                log.warn("Input dimensions not specified, but input neurons match")
                log.warn("Substituting input dimensions from test data")
                self.input_dimensions = test_data.input_dimensions
            else:
                log.warn("Testing data has different dimensions to network, continuing...")
        given_output = self.get_output(test_data.input) # get test data and compare
        check_output(given_output, test_data, self.folders["testing"], **options)

    def get_output(self, test_input_data):
        if(self.synapses_built == False):
            log.error("Cannot get sample output, synapses not built")
            return
        total_layers = len(self.synapses)+1
        layers = Network_Layers(total_layers, function=self.training_config.function)
        layers.initialise_input(test_input_data)
        layers.apply_feed_forward(self.synapses)
        return layers.values[-1]    #

    ''' 
        get_hidden_neuron_heatmap:
            Gets a heatmap of each hidden neuron in each layer of the network, 
            and shows how each pixel of the input contributes to its final weight
        graph_loss_history: Produces and saves a plot of the loss
    '''
    def get_hidden_neuron_heatmaps(self):
        if(self.synapses_built == False):
            log.error("Can't generate heatmap without building synapses!")
            return
        if(self.input_dimensions == None):
            log.error("Dimensions of input not specified. Cannot show heatmap!")
            return
        layer_weights = self.synapses[0]    # at least one for input to output
        save_path = self.folders["hidden"]  
        for layer in range(len(self.synapses)):
            if(layer != 0):
                layer_weights = np.dot(layer_weights, self.synapses[layer])
            # Get weights as a dot product chain of previous layers
            for neuron in range(layer_weights.shape[1]):
                hidden_weights = layer_weights[:,neuron]
                hidden_matrix = hidden_weights.reshape(*self.input_dimensions)
                plt.title("Layer {0}, Neuron {1}".format(layer, neuron))
                plt.imshow(hidden_matrix, cmap='Spectral', interpolation='nearest')
                plt.colorbar()
                plt.savefig("{0}/{1}_{2}.png".format(save_path, layer, neuron)) 
                plt.close()

    def graph_loss_history(self, filename='loss'):
        if(len(self.error_history) == 0):
            log.warn("Loss history has not been created yet!")
            return
        plt.plot(np.array(self.error_history).T)
        plt.ylabel("Training loss")
        plt.xlabel("Epoch")
        plt.savefig("{0}/{1}.png".format(self.folders["training"], filename))   
        plt.close() 

    '''
        describe = Show the number of neurons in each layer
        help = Explain the functions available in the class
    '''
    def describe(self):
        log.info("[Description of neural network]") 
        log.info("input_neurons  = {0}".format(self.neuron_count.input))  
        log.info("output_neurons = {0}".format(self.neuron_count.output))
        log.info("hidden_neurons = {0}".format(self.neuron_count.hidden))


class Neuron_Count:
    def __init__(self, input_count, output_count, hidden_count):
        self.input = input_count
        self.output = output_count
        self.hidden = hidden_count


class Data_Package:
    def __init__(self, module, shuffle=False):
        if(shuffle == True):
            rng_state = np.random.get_state()
            np.random.shuffle(module.input_data)
            np.random.set_state(rng_state)
            np.random.shuffle(module.output_data)
        self.input = module.input_data
        self.output = module.output_data
        self.input_dimensions = module.dimensions
        self.total_sets = self.input.shape[0]
        self.total_input_neurons = self.input.shape[1]
        self.total_output_neurons = self.output.shape[1]


class Training_Config:
    def __init__(self, **options):
        # Default training config
        self.epochs = 1000
        self.debug = True
        self.target_error = 0   # Default target is no error
        self.learning_rate = 1
        self.function = 'sigmoid'
        self.valid_options = ['epochs', 'debug', 'target_error', 
                              'learning_rate', 'function']
        self.set(**options)
    
    def set(self, **options):
        for key in options:
            if(key in self.valid_options):
                setattr(self, key, options[key])
            else:
                log.warn("class Training_Config has no attribute: " + key)

    def describe(self):
        log.info("[Training configuration]")
        for key in self.valid_options:
            log.info("{0} = {1}".format(key, getattr(self, key)))

    
