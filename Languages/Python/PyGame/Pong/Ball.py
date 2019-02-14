import random
from Vector import Vector
import pygame
class Ball:
    def __init__(self, display, colour=(255,255,255), pos=(0,0), radius=10, speed=20, bounds=(0,0,1366,768), dt=1):
        self.display = display
        self.colour = colour
        self.pos = pos
        self.vel = Vector(0, 0)
        self.speed = speed
        self.radius = radius
        self.bounds = bounds    # bounds = (0, 0, 1366, 768)
        self.dt = dt
        self.score = {
            "left": 0,
            "right": 0
        }
        self._start()

    def update(self):
        self._limitSpeed()
        self.pos.add(self.vel.getMult(self.dt))
        self.checkBounds()

    def show(self):
        box = (self.pos.x - self.radius, self.pos.y - self.radius,
               2*self.radius, 2*self.radius)
        pygame.draw.rect(self.display, self.colour, box)

    def checkBounds(self):
        # Bounce off top and bottom boundary
        if self.pos.y - self.radius <= self.bounds[1]:
            self.vel.y = abs(self.vel.y)
        if self.pos.y + self.radius >= self.bounds[3]:
            self.vel.y = -abs(self.vel.y)
        # Reset if left or right boundaries
        if self.pos.x - self.radius <= self.bounds[0]:
            self.reset("left")
        if self.pos.x + self.radius >= self.bounds[2]:
            self.reset("right")

    # Takes paddle and bounces accordingly
    def bounce(self, paddle):
        # Bounce if collide left and right
        if(paddle._checkYInside(self.pos.y + self.radius) or
                paddle._checkYInside(self.pos.y - self.radius)):
            # Left side
            if paddle._checkXInside(self.pos.x + self.radius):
                self.vel.x = -abs(self.vel.x)
                self.vel.add(paddle.vel)
            # Right side
            elif paddle._checkXInside(self.pos.x - self.radius):
                self.vel.x = abs(self.vel.x)
                self.vel.add(paddle.vel)


    def reset(self, side):    
        self.pos.x = self.bounds[2]/2.0
        self.pos.y = self.bounds[3]/2.0
        if side == "left":
            self.score["right"] += 1
            self.vel = Vector(
                self.speed + random.randint(-2, 2), 
                self.speed + random.randint(0, 2)
            )
        elif side == "right":
            self.score["left"] += 1
            self.vel = Vector(
                self.speed + random.randint(-2, 2), 
                -self.speed - random.randint(0, 2)
            )
    
    # Resets the ball position and nulls the score
    def resetScore(self):
        self.reset("left")
        self.score = {
            "left": 0,
            "right": 0
        }

    # Cap the velocity if it goes above the maximum limit
    def _limitSpeed(self):
        if self.vel.x > self.speed:
            self.vel.x = self.speed
        if self.vel.y > self.speed:
            self.vel.y = self.speed

    # This will start the ball moving at a random direction
    def _start(self):
        if random.randint(0, 1) == 1:
            self.vel = Vector(
                self.speed,
                random.randint(-self.speed, self.speed),
            )
        else:
            self.vel = Vector(
                -self.speed,
                random.randint(-self.speed, self.speed),
            )
    
    

    
        


