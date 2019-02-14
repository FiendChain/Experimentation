from functools import wraps

def decorator(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        return func(*args, **kwargs)
    return wrapper

@decorator
def logger(msg):
    """
    Docstring for a logger function
    @args
        msg: print message
    @returns
        None
    """
    print(msg)

logger('testing logger')

print(logger.__name__)
print(logger.__doc__)


