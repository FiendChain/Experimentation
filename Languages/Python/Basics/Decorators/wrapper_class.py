class WrapperClass(object):
    def __init__(self, name):
        self.name = name
        super().__init__()

    def wrapper(self, message=None):
        def decorator(func):
            def wrapped(*args, **kwargs):
                print(self)
                print("Message: "+message)
                return func(*args, **kwargs)
            return wrapped
        return decorator

    def decorator(self, func):
        def wrapped(*args, **kwargs):
            print(self)
            print("Function name: "+func.__name__)
            return func(*args, **kwargs)
        return wrapped

    def __str__(self):
        return "class <WrapperClass:{name}>".format(name=self.name)

base = WrapperClass('base')

@base.wrapper(message='Logging function')
def logger(msg):
    print('Log: {}'.format(msg))

@base.decorator
def checker(msg):
    print('Checker: {}'.format(msg))

logger('Hello')
checker('There')

