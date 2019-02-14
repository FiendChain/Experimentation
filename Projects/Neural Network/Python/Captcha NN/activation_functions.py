import numpy as np
from math import pi

def sigmoid(x, deriv=False):
    x = np.clip(x, -500, 500)       # Clip to prevent overflow in np.exp(x)
    sigmoid_val = 1/(1+np.exp(-x))  
    if(deriv == True):              
        return sigmoid_val*(1-sigmoid_val)
    return sigmoid_val

def relu(x, deriv=False):
    x = np.copy(x)
    if(deriv == True):
        x[x<0]  = 0
        x[x>=0] = 1
    else:
        x[x<0] = 0
    return x

def leaky_relu(x, deriv=False):
    x = np.copy(x)
    if(deriv == True):
        x[x<0]  = 0.1
        x[x>=0] = 1
    else:
        x[x<0] *= 0.1
    return x

def softmax(x):
    logistic_exp = np.exp(x)
    return logistic_exp / np.sum(logistic_exp, axis = 1, keepdims = True)

def inverse_tan(x, deriv=False):    # constant used to make 0<=out<=1
    if(deriv == True):
        return 1/(pi*(1 + x**2))    
    return (np.arctan(x) + pi/2.0) / pi