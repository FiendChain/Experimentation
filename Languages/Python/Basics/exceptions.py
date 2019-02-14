''' When an error occurs in your code, exceptions can be used to handle it
    try:
        __Code you want__
    except:
        __If something went wrong, do this__
'''

# Using exceptions to get continuous input
inputList = []
while True:
    # Try get a string
    try:
        string = input('Enter you input: ')
    # If string is not given (ctrl+d), exit
    except:
        print(end = '\n')
        break
    # Append to list
    if(len(string) > 0):
        inputList.append(string)
print(inputList)

# Having specific exceptions
numberList = []
while True:
    # Try get a number
    try:
        integer = int(input('Enter a number: '))
    # If EOF character, exit
    except EOFError:
        print(end = '\n')
        break
    # If there is a value error
    except ValueError:
        print('Not a valid number!')
        continue
    # Append number to list
    numberList.append(integer)
print(numberList)