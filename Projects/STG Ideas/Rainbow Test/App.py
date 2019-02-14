import pygame
from Vector import Vector
from Colours import colour

class App:
    """
        Initialisation methods
        __init__ = initialisation of class
        __default__ = inputting default arguments
        initPygame = initialise the pygame instance
    """
    def __init__(self, *args, **kwargs):
        self.__default__(**kwargs)
        self.initPygame()
        self.isOpen = True

    def __default__(self, **kwargs):
        self.defaultParams = {
            "fps": 144,
            "tickrate": 50,
            "resolution": Vector(1200, 900),
        }
        # set params
        self.defaultParams.update(kwargs)
        for param, value in self.defaultParams.iteritems():
            setattr(self, param, value)
        # dt for game objects
        self.dt = self.tickrate/float(self.fps)

    def initPygame(self):
        pygame.init()
        self.clock = pygame.time.Clock()
        self.display = pygame.display.set_mode(self.resolution, 0, 32)
        self.display.fill(colour["white"])
        self.events = []
        self.objects = {}

    """
        addObjects = add game objects
        Must be a class with the following methods:
            render(self, display),
            update(self, dt),
    """
    def addObjects(self, **objectList):
        for name, gameObject in objectList.iteritems():
            if name in self.objects:
                raise NameError("Duplicate of object {0} at {1}".format(name, gameObject))
            self.objects[name] = gameObject

    """
        run = go through one game loop
        update = update all physics
        render = render everything
        getKeyPress = handle input
    """
    def run(self):
        try:
            # process events
            if self.isOpen:
                pygame.event.pump()
                self.events = pygame.event.get()
            # game loop
            for function in (self.getKeyPress, self.update, self.render):
                if self.isOpen:
                    function()
        # keyboard cancel
        except KeyboardInterrupt:
            self.isOpen = False
        # return game state
        return self.isOpen 

    def update(self):
        self.clock.tick(self.fps)
        for name, gameObject in self.objects.iteritems():
            gameObject.update(self.dt)
    
    def render(self):
        self.display.fill(colour["rainbow"])
        colour["rainbow"].cycle(self.dt)
        for name, gameObject in self.objects.iteritems():
            gameObject.render(self.display)
        pygame.display.update()

    def getKeyPress(self):
        for event in self.events:
            if event.type == pygame.QUIT:
                self.close()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    self.close()

    def close(self):
        pygame.quit()
        self.isOpen = False
            