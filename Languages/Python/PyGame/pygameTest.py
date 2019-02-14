import pygame
import sys

class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def add(self, vector):
        self.x += vector.x
        self.y += vector.y

    def sub(self, vector):
        self.x -= vector.x
        self.y -= vector.y

    def mult(self, scalar):
        self.x *= scalar
        self.y *= scalar

    def getMult(self, scalar):
        x = self.x * scalar
        y = self.y * scalar
        return Vector(x, y)

class Ball:
    def __init__(self, display, dt, colour=(255, 0, 0), size=(10, 10), pos=Vector(0,0), vel=Vector(0,0)):
        self.display = display
        self.pos = pos
        self.vel = vel
        self.dt = dt
        self.width = size[0]
        self.height = size[1]
        self.colour = colour

    def applyForce(self, force):
        self.vel.add(force.getMult(self.dt))
    
    def update(self):
        self.pos.add(self.vel.getMult(self.dt))
        self.bound()
    
    def show(self):
        box = (self.pos.x - self.width/2, self.pos.y - self.height/2, 
               self.width, self.height)
        pygame.draw.rect(self.display, self.colour, box)

    def bound(self):
        if self.pos.y > 900:
            self.pos.y = 0
        elif self.pos.y < 0:
            self.pos.y = 900
            pygame.quit()
            sys.exit()

        if self.pos.x > 1200:
            self.pos.x = 0
        elif self.pos.x < 0:
            self.pos.x = 1200


def renderGame():
    fps = 200
    dt = 3.0/fps
    pygame.init()
    clock = pygame.time.Clock()
    resolution = (1200, 900)
    display = pygame.display.set_mode(resolution, 0, 32)
    ball = Ball(display, dt, vel=Vector(100, 50))

    white = (255, 255,255)  
    blue = (0, 0, 255)  

    display.fill(white)

    while True:
        clock.tick(fps)
        pressed = pygame.key.get_pressed()
        if pressed[pygame.QUIT]:
            pygame.quit()
            sys.exit()
        display.fill(white)
        ball.applyForce(Vector(0, -9.8))
        ball.update()
        ball.show()
        pygame.display.update()
        pygame.event.pump()

renderGame()
