class Vector:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def mult(self, mag):
        self.x *= mag
        self.y *= mag

    def add(self, vector):
        self.x += vector.x
        self.y += vector.y

    def sub(self, vector):
        self.x -= vector.x
        self.y -= vector.y

    def getMult(self, mag):
        return Vector(self.x * mag, self.y * mag)