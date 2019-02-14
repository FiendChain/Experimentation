''' Python is an object orientated programming language
    This means that it includes classes
    Classes contain the following things:
        1. Variables
        2. Functions
        3. Name (Name given to the instance of the class)
'''

# Creating a very basic class
class MyClass:
    # Variables inside the class
    mass    = 0
    gender  = 'Unknown'
    address = 'Unknown'
    # Function that doesn't access the class' variables
    def function(self, input): 
        print('You gave me:', input, sep = ' ')
    # Function that does access the class' variables
    def info(self):
        print('Mass:'   , self.mass)
        print('Gender:' , self.gender)
        print('Address:', self.address)

# Instantiating a class to create an object
person = MyClass()
# Accessing this object's variables
person.mass     = 20
person.gender   = 'Male'
person.address  = 'Earth'
# Accessing this object's functions
person.function('Hello World!') # Prints out: 'You gave me: Hello World!' 
person.info()
'''
    This custom function prints out information about the class:
    Mass: 20
    Gender: Male
    Address: Earth
'''

# Creating a class that self initiates
class BetterClass:
    # Creating initiating function
    def __init__(self, mass, gender, address):
        self.mass = mass
        self.gender = gender
        self.address = address
    # Prints out information about class
    def info(self):
        print('Mass:'   , self.mass)
        print('Gender:' , self.gender)
        print('Address:', self.address)

# Instantiating the class with parameters
betterPerson = BetterClass(mass = 20, gender = 'Female', address = 'Mars')
betterPerson.info()
'''
    Prints out:
    Mass: 20
    Gender: Female
    Address: Mars
'''

