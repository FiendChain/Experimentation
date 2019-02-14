# a bouncy ball for testing
from Vector import Vector
from Colours import colour
import pygame

class Ball:
    def __init__(self, *args, **kwargs):
        self.__default__(**kwargs)
    
    def __default__(self, **kwargs):
        self.defaultParams = {
            "pos": Vector(0, 0),
            "vel": Vector(0, 0),
            "acc": Vector(0, 0),
            "size": Vector(5, 5),
            "mass": 1,
            "colour": colour["white"],
            "res": Vector(1300, 700),
        }
        self.defaultParams.update(kwargs)
        for param, value in self.defaultParams.iteritems():
            setattr(self, param, value)

    def bounce(self):
        # bound x
        if self.pos.x-self.size.x < 0:
            self.pos.x = self.size.x
            self.vel.x = abs(self.vel.x)
        elif self.pos.x+self.size.x > self.res.x:
            self.pos.x = self.res.x-self.size.x
            self.vel.x = -abs(self.vel.x)
        # bound y
        if self.pos.y-self.size.y < 0:
            self.pos.y = self.size.y
            self.vel.y = abs(self.vel.y)
        elif self.pos.y+self.size.y > self.res.y:
            self.pos.y = self.res.y-self.size.y
            self.vel.y = -abs(self.vel.y)

    def update(self, dt=1):
        self.vel += self.acc * dt
        self.pos += self.vel * dt
        self.acc *= 0
        self.bounce()

    def applyForce(self, force):
        # f = ma
        # a = f/m
        self.acc = force/float(self.mass)

    def render(self, display):
        box = (self.pos.x-self.size.x, self.pos.y-self.size.y,
               2*self.size.x, 2*self.size.y)
        pygame.draw.rect(display, self.colour, box)
    