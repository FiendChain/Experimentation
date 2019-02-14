class Vector:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y
        self.components = ("x", "y")
    
    # vector operations
    def __add__(self, vector):
        return Vector(self.x+vector.x, self.y+vector.y)

    def __sub__(self, vector):
        return Vector(self.x-vector.x, self.y-vector.y)

    def __mul__(self, scalar):
        return Vector(self.x*scalar, self.y*scalar)

    def __truediv__(self, scalar):
        return Vector(self.x/float(scalar), self.y/float(scalar))

    # access like named tuple
    def __getitem__(self, index):
        return getattr(self, self.components[index])

    def __setitem__(self, index, value):
        setattr(self, self.components[index], value)

    # total components
    def __len__(self):
        return len(self.components)

    # representation
    def __str__(self):
        values = tuple([getattr(self, component) for component in self.components])
        return "Vector{}".format(values)

    def __repr__(self):
        return self.__str__()

    # return a copy of it
    def getCopy(self):
        return Vector(self.x, self.y)