# generator for fibonacci
from time import sleep

def fib(n):
    x = 1
    y = 1
    for _ in range(n):
        value = x
        x = y
        y += value
        sleep(.5)
        yield value

for i in fib(20):
    print(i)
        