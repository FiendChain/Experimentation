class Vector:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y
        self.components = ("x", "y")
    
    def __add__(self, vector):
        return Vector(self.x+vector.x, self.y+vector.y)

    def __sub__(self, vector):
        return Vector(self.x-vector.x, self.y-vector.y)

    def __mul__(self, scalar):
        return Vector(self.x*scalar, self.y*scalar)

    def __div__(self, scalar):
        return Vector(self.x/float(scalar), self.y/float(scalar))

    def __getitem__(self, index):
        return getattr(self, self.components[index])

    def __setitem__(self, index, value):
        setattr(self, self.components[index], value)

    def __len__(self):
        return len(self.components)

    def getCopy(self):
        return Vector(self.x, self.y)