''' Iterating through iterable datatypes
    1. Lists
    2. Tuples
    3. Dictionary
'''

# For loop
friends = ['Zeus', 'Chronos', 'Hades']
ages = ['20', '50', '30']
friendAges = {} 

# Iterating using indexes
for i in range(0, 3):
    friendAges[friends[i]] = ages[i]
print(friendAges) # {'Zeus': '20', 'Hades': '30', 'Chronos': '50'}

# Iterating using items inside iterable datatype
for friend in friends:
    print(friend, 'is a friend!', sep = ' ')
'''
    This will print out:
    Zeus is a friend!
    Chronos is a friend!
    Hades is a friend!
'''

# Using a while loop
index = 0
while(index < 3):
    print(friends[index], 'is a friend!', sep = ' ')
    index += 1
'''
    This will print out:
    Zeus is a friend!
    Chronos is a friend!
    Hades is a friend!
'''

# List comprehension
friendList = [friend + ' is a friend!' for friend in friends]
print(friendList)
'''
    The list of strings will contain:
    ['Zeus is a friend!', 'Chronos is a friend!', 'Hades is a friend!']
    This method of creating a list by iterating through a sequence, is called
    list comprehension
'''

# More list comprehension
oddNumbers = [number for number in range(0, 20) if number % 2 is not 0]
print(oddNumbers) # This will print out all the odd numbers within 20
squareNumbers = [number **2 for number in range(0, 10)]
print(squareNumbers) # Prints out squares from 0 to 9
'''
    PYTHON:
    for x in range(0, 10):
        print(x)
    
    C:
    for(int x = 0, x < 10, x ++) {
        printf("%d\n", x);
    }
'''

# For loops in list comprehension
oddNumbersStep = [number for number in range(1, 20, 2)]
print(oddNumbersStep) # This will also print out all odd numbers within 20
'''
    range function parameters
    range(start, end, step):
        start = initial value of iterator (default is 0)
        end   = limit for the iterator    (needs to be specified)
        step  = amount of increment       (default is 1)
    Acceptable uses:
        for x in range(3)
        for x in range(0, 3)
        for x in range(0, 3, 1)
    These all do the same thing
'''



