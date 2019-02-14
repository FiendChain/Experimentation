# Math module
import math

# Module for complex numbers
class ComplexClass:
    def __init__(self, real, imaginary):
        self.real = real
        self.imaginary = imaginary
    def angle(self):
        self.radian = math.atan(self.imaginary/self.real)
        self.degree  = (180/math.pi) * self.radian
    def itself(self):
        string = str(self.real) + ' + ' + str(self.imaginary) + 'i'
        return string