import collections
import functools

class memoized(object):
    '''Decorator. Caches a function's return value each time it is called.
       If called later with the same arguments, the cached value is returned
       (not reevaluated).
    '''
    def __init__(self, func):
        self.func = func
        self.cache = {}
    def __call__(self, *args):
        if not isinstance(args, collections.Hashable):
            # uncacheable. a list, for instance.
            # better to not cache than blow up.
            return self.func(*args)
        if args in self.cache:
            return self.cache[args]
        else:
            value = self.func(*args)
            self.cache[args] = value
            return value
    def __repr__(self):
        '''Return the function's docstring.'''
        return self.func.__doc__
    def __get__(self, obj, objtype):
        '''Support instance methods.'''
        return functools.partial(self.__call__, obj)
 
@memoized
def ackerman(m, n):
	if m == 0:
		return n+1
	elif n == 0:
		return ackerman(m-1, 1)
	else:
		return ackerman(m-1, ackerman(m, n-1))

max_i = 6
max_j = 6

for i in range(max_i):
	for j in range(max_j):
		print("ackerman({0},{1}) = {2}\n".format(i, j, ackerman(i,j)))








