import time

fibCache = {}
fibCache[0] = 0

def fib(n):
    if n in fibCache:
        return fibCache[n]
    if n == 1 or n == 2:
        return 1
    temp = fib(n-1) + fib(n-2)
    fibCache[n] = temp
    return temp

# for x in range(0, 5000):
#     print('%d: %d' %(x, fib(x)))

tribCache = {}
tribCache[0] = 0

def trib(n):
    if n in tribCache:
        return tribCache[n]
    if n >= 1 and n <= 3:
        return 1
    temp = trib(n-1) + trib(n-2) + trib(n-3)
    tribCache[n] = temp
    return temp

# for x in range(0, 5000):
#     print('%d: %d' %(x, trib(x)))

# Get a custom fibonacci number
while True:
    try:
        inputValue = int(input('Enter desired fibonnaci number: '))
    except:
        continue
    break

startTime = time.time();
for x in range(0, inputValue+1):
    fib(x)
endTime = time.time();
duration = endTime - startTime
print('Took %d seconds to get %d fibonnaci numbers!' %(duration, inputValue))
print('[%d]:%d' %(inputValue, fib(inputValue)))


