from App import App
from Vector import Vector
from Ball import Ball
import pygame
import collections

def main():
    app = App(resolution=Vector(1300, 700), fps=144)
    app.addObjects(ball=Ball(pos=Vector(0, app.resolution.y), vel=Vector(-10, -50)))
    mouseKey = collections.namedtuple("mouseKey", "left middle right")(1, 2, 3)
    while app.run():
        ball = app.objects["ball"]
        ball.applyForce(Vector(0, 3))
        ball.vel *= 1.0001
        for event in app.events:
            if event.type == pygame.MOUSEBUTTONDOWN:
                if event.button == mouseKey.left:
                    ball.size *= 1.5
                elif event.button == mouseKey.right:
                    ball.size *= 0.66

if __name__ == "__main__":
    main()