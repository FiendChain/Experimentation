# Check the output of a trained network
import logging as log
import matplotlib.pyplot as plt
import numpy as np
import os

# Compares expected and given outputs from neural network, and logs it
# Saves it to directory specified in arguments
def check_output(given_output, test_data, directory, **options):
    if(given_output.shape != test_data.output.shape):
        log.error("Mismatch in given_output and expected_output dimensions!")
        return
    valid_options = {"threshold": 0.05, "test_type": "default", 
                     "debug": False, "graph": False}
    for option in options:
        if(option in valid_options):
            valid_options[option] = options[option]
    log.info("[Starting testing]")
    for option in valid_options:
        log.info("{0}={1}".format(option, valid_options[option]))
    test_functions = {
        "default": test_default,
        "digits" : test_digits
    }
    test_type = valid_options["test_type"]
    if(test_type in test_functions):
        test_functions[test_type](given_output, test_data, directory, **valid_options)
    else:
        log.warn("test_type={0} is not supported, selecting default!".format(test_type))
        test_functions["default"](given_output, test_data, directory, **valid_options)
        
def test_default(given_output, test_data, directory, **options):
    threshold = options["threshold"]
    debug = options["debug"]
    expected_output = test_data.output
    total_sets = expected_output.shape[0]
    total_correct = 0
    for i in range(total_sets):
        mean_error = get_mean_error(expected_output[i], given_output[i])
        print_string = "{0}={1}: {2}".format(given_output[i], expected_output[i], mean_error)
        if(mean_error <= threshold):
            total_correct += 1
            if(debug == True):
                log.debug("[x]:" + print_string)
        elif(debug == True):
            log.debug("[ ]:" + print_string)
    print_summary(total_correct, total_sets)

def test_digits(given_output, test_data, directory, **options):
    threshold = options["threshold"]
    debug = options["debug"]
    graph = options["graph"]
    expected_output = test_data.output
    if(expected_output.shape[1] != 10):
        log.error("Output data doesn't represent digits 0-9. Performing default test!")
        test_default(given_output, test_data, directory, threshold)
        return
    total_sets = expected_output.shape[0]
    total_correct = 0
    digit_count = [0] * 10
    correct_digit_count = [0] * 10
    folders = {
        "correct"  : "{0}/correct".format(directory),
        "incorrect": "{0}/incorrect".format(directory)
    }
    for folder in folders:
        folder_path = folders[folder]
        if not os.path.exists(folder_path):
            os.makedirs(folder_path)
            log.info("Generated: {0}".format(folder_path))
    for i in range(total_sets):
        mean_error = get_mean_error(expected_output[i], given_output[i])
        error_string = get_error_string(given_output[i], mean_error)
        digit = get_digit(expected_output[i])
        title = "{0}_{1}".format(digit, digit_count[digit])
        digit_count[digit] += 1
        print_string = "{0}=>{1}={2}: {3}".format(title, given_output[i], expected_output[i], mean_error)
        save_path = directory
        if(mean_error <= threshold):
            total_correct += 1
            if(debug == True):
                log.debug("[x]:" + print_string)
            save_path = folders["correct"]
            correct_digit_count[digit] += 1
        else:
            if(debug == True):
                log.debug("[ ]:" + print_string)
            save_path = folders["incorrect"]
        if(graph == True):
            save_input_sample(test_data.input[i], test_data.input_dimensions, title, error_string, save_path)
    print_summary(total_correct, total_sets)
    save_digit_error(correct_digit_count, digit_count, directory)

def get_mean_error(expected_output, given_output):
    error_vector = expected_output - given_output
    absolute_error = np.abs(error_vector)
    mean_error = np.mean(absolute_error)
    return mean_error

def print_summary(total_correct, total_sets):
    correct_rate = round(total_correct / float(total_sets) * 100, 2)
    log.info("[Summary of testing]")  
    log.info("correct={0}".format(total_correct)) 
    log.info("tested={0}".format(total_sets))    
    log.info("rate={0}".format(correct_rate) + "%")

def save_input_sample(input_sample, dimensions, title, error_string, save_path):
    input_copy = np.copy(input_sample)
    input_matrix = input_copy.reshape(*dimensions)
    plt.imshow(input_matrix, cmap="binary", interpolation="nearest")
    plt.colorbar()
    plt.figtext(0, 0, error_string)
    plt.title(title)
    plt.savefig("{0}/{1}.png".format(save_path,title))   # save the figure to file
    plt.close() 

def save_digit_error(correct, total, save_path):
    x_axis = [i for i in range(10)]
    y_axis = []
    for i in range(10):
        rate = correct[i] / float(total[i]) * 100
        y_axis.append(rate)
    correct_sets = sum(correct)
    total_sets = sum(total)
    correct_rate = correct_sets / float(total_sets) * 100
    figtext_string = "correct={0}\ntotal={1}\nrate={2}%".format(correct_sets, total_sets, round(correct_rate, 2))
    plt.bar(x_axis, y_axis, align='center', alpha=0.5)
    plt.xticks(x_axis)
    plt.xlabel("Digits")
    plt.ylabel("Percentage correct %")
    plt.figtext(0, 0, figtext_string)
    plt.savefig("{0}/digit_errors.png".format(save_path))   
    plt.close() 

def get_error_string(given_output, mean_error):
    error_string = ""
    for i in range(len(given_output)):
        error_string += "{0}={1}%,".format(i, round(given_output[i]*100,1))
    error_string += "\n"
    error_string += "Mean error = {0}".format(mean_error)
    return error_string

def get_digit(expected_output):
    for i in range(len(expected_output)):
        if(expected_output[i] != 0):
            return i
    return 0

    
    
    
