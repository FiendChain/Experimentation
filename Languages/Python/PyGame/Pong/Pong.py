from Ball import Ball
from Paddle import Paddle
from PaddleBot import PaddleBot
from Vector import Vector
import pygame

import sys
from Colour import *

class Pong:
    def __init__(self, width=1300, height=700, fps=144, name="Pong"):
        self.name = name
        self.setSize(width, height)
        self.setFPS(fps)
        self.initPyGame()
        self.initObjects()
        self.isOpen = True

    '''
        ==INITIATE ALL GAME PARAMETERS==
        setSize = sets resolution and object sizes
        setFPS = sets fps, timescale, dt
        initPyGame = creates pygame objects to render on
    '''
    # set the resolution of the game
    def setSize(self, width, height, size=None):
        self.res = Vector(width, height)
        self.bounds = (0, 0, self.res.x, self.res.y)
        if size is None:
            self.size = self.res.x/50
        else:
            self.size = size

    # set the physics timescale of game
    def setFPS(self, fps, tickrate=50):
        self.fps = fps
        self.tickrate = tickrate
        self.dt = self.tickrate/float(self.fps)

    # init pygame objects
    def initPyGame(self):
        pygame.init()
        self.clock = pygame.time.Clock()
        self.display = pygame.display.set_mode((self.res.x, self.res.y))
        pygame.display.set_caption(self.name)

    '''
        ==INSTANTIATE ALL GAME OBJECTS==
        initObjects = inits all game objects in correct order
        makeBall = makes ball
        makeLeftPaddle/makeRightPaddle = makes the paddles
        makePaddleBots = makes the ai
    '''
    # init game objects
    def initObjects(self):
        self.makeBall()
        self.makeLeftPaddle()
        self.makeRightPaddle()
        self.makePaddleBots()

    # make game objects individually
    def makeBall(self):
        self.ball = Ball(
            self.display, 
            colour=white, 
            pos=Vector(self.res.x/2, self.res.y/2), 
            radius=self.size/2, 
            bounds=self.bounds, 
            dt=self.dt
        )
    
    def makeLeftPaddle(self):
        self.leftPaddle = Paddle(
            self.display, 
            colour=white, 
            speed=20, 
            pos=Vector(self.size, self.res.y/2), 
            size=(self.size, 5*self.size), 
            bounds=self.bounds, 
            dt=self.dt
        )

    def makeRightPaddle(self):
        self.rightPaddle = Paddle(
            self.display, 
            colour=white, 
            speed=20, 
            pos=Vector(self.res.x-self.size, self.res.y/2), 
            size=(self.size, 5*self.size), 
            bounds=self.bounds, 
            dt=self.dt
        )

    def makePaddleBots(self):
        self.rightPaddleBot = PaddleBot(
            self.ball, 
            self.rightPaddle, 
            skill=10
        )
        self.leftPaddleBot = PaddleBot(
            self.ball, 
            self.leftPaddle, 
            skill=10
        )

    '''
        ==GAME EXECUTION FUNCTIONS==
        run = update and render the game
        getKeyPress = recieve user input
        render = draw all objects
        update = update all physics
    '''
    # run through game
    def run(self):
        if self.isOpen:
            self.clock.tick(self.fps)
            self.getKeyPress()
            self.update()
            self.render()
            # if game has quit after update
            if not self.isOpen:
                pygame.quit()
    
    # get key press
    def getKeyPress(self):
        # pump and check all game events
        pygame.event.pump()
        for event in pygame.event.get(): 
            if event.type == pygame.QUIT:
                self.isOpen = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_DOWN: 
                    self.leftPaddle.move("down")
                elif event.key == pygame.K_UP:
                    self.leftPaddle.move("up")
            else:
                self.leftPaddle.move()
        
    # render the game
    def render(self):
        self.display.fill(black)
        self.ball.show()
        self.leftPaddle.show()
        self.rightPaddle.show()
        pygame.display.update()

    # update game object physics
    def update(self):
        # update paddle velocity
        #self.leftPaddleBot.movePaddle()         
        self.rightPaddleBot.movePaddle()
        # update positions
        self.ball.update()                      
        self.leftPaddle.update()
        self.rightPaddle.update()
        # bounce ball
        self.ball.bounce(self.leftPaddle)
        self.ball.bounce(self.rightPaddle)
