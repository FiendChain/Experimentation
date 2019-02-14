def repeat(n_times):
    def decorator(func):
        def wrapper(*args, **kwargs):
            for _ in range(n_times):
                return_value = func(*args, **kwargs)
            return return_value
        return wrapper
    return decorator

@repeat(3)
def sing(line='Hello baby'):
    print(line)

modern_music = repeat(10)(sing)





