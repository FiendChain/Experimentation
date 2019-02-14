def fibonacci(total):
    x = 1
    y = 1
    fibList = [1,1]
    for iter in range(2, total):
        temp = x
        x = x + y
        y = temp
        fibList.append(x)
    return fibList

def tribonacci(total):
    x = 1
    y = 1
    z = 1
    triList = [1,1,1]
    for iter in range(3, total):
        temp = x
        x = x + y + z
        z = y
        y = temp
        triList.append(x)
    return triList

def powers(total, power):
    powerList = [x**power for x in range(total)]
    return powerList