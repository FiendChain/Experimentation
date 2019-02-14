# This is a comment
''' This is also a comment
    That encapsulates multiple lines
    Such as this
'''

# Python doesn't need a declaration for specifying datatype
var1 = 20   # This is an integer
var2 = 20.5 # This is a float
var3 = []   # This is a list -> similar to an array (mutable)
var4 = ()   # This is a tuple -> Like a list but fixed (immutable)
var5 = {}   # This is a dictionary -> More about it below

'''
    Mutable: It can be modified -> altered, deleted (numbers, lists, dictionary)
    Immutable: It cannot be modified -> constant, fixed (tuples)
'''

# Dictionary usage
friendAge = {
    'Gary'  : 20,
    'Arthur': 50,
    'Jesus' : 15
}

print(friendAge['Gary']) # This will print 20

''' How it works
    1. The dictionary accepts a 'key' similar to an index
    2. This key is then hashed, and then assigned the value
    3. You access the value by providing the correct key
    Dictionary: key --> HASH --> content
'''

