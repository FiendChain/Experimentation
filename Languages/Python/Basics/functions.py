# Creating functions
def square(x):
    return x**2
squaredNumbers = [square(x) for x in range(0, 10)]
print(squaredNumbers) # Prints out squared numbers 0 to 81

# Iterative function
def fibonacci():
    x = 1
    y = 1
    fibSequence = [1,1]
    for i in range(2, 10):
        temp = x
        x = x + y
        y = temp
        fibSequence.append(x)
    print(fibSequence)
fibonacci() # Prints out first 10 fibonacci numbers

# Recursive function (calls itself)
fibSequence = [1,1]
def recursiveFibonacci(x, y, list, start, end):
    # Limit total recursions
    if(start > end):
        return
    # Otherwise continue appending
    list.append(x + y)
    ''' Old sequence: ... , y, x
        New sequence: ... , y, x, x+y
    '''
    # Increment the recursion parameters
    recursiveFibonacci(x + y, x, list, start + 1, end)
# Creating starting values for recursive function 
recursiveFibonacci(x = 1, y = 1, list = fibSequence, start = 3, end = 10)
print(fibSequence) # Prints out first 10 fibonnaci numbers
