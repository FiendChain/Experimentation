from Colours import colour
from Vector import Vector
import pygame

"""
    Will be give a start and end location
    Will be given a start and end size
    Dimensions will be specified with the Vector class, and for each
    game cycle there will be a specific transform that occurs
    Will use the centre mode for all dimensions
"""
class TransformObject:
    def __init__(self, **kwargs):
        self.__default__(**kwargs)

    # must specify the parameters
    def __default__(self, **kwargs):
        requiredParam = {
            "startPos": None,
            "endPos": None,
            "startSize": None,
            "endSize": None,
            "time": 1,   # total number of seconds for transition
            "colour": colour["rainbow"],
            "repeat": True,
        }
        requiredParam.update(kwargs)
        self.applyParameters(requiredParam)

    # change to a new location
    def changeLocation(self, **kwargs):
        newParam = {
            "startPos": self.pos.getCopy(),     # for transition from current location
            "endPos": self.pos.getCopy(),
            "startSize": self.size.getCopy(),   # for transition from current size
            "endSize": self.size.getCopy(),
        }
        newParam.update(kwargs)
        self.applyParameters(newParam)

    # add kwargs to a default dict, and raise if parameter/s is not supplied
    def applyParameters(self, options, emptyValue=None):
        missingParam = []
        for param, value in options.items():
            setattr(self, param, value)
            if value is emptyValue:
                missingParam.append(param)
        if len(missingParam) > 0:
            raise NameError("Missing parameters {0}".format(missingParam))
        self.applyChanges()

    # determine transform deltas
    def getIncrement(self):
        posDiff = self.endPos-self.startPos
        self.posIter = posDiff/self.time
        sizeDiff = self.endSize-self.startSize
        self.sizeIter = sizeDiff/self.time

    # apply with new parameters
    def applyChanges(self):
        self.getIncrement()
        self.reset()

    # update the transform
    def update(self, dt=1, **kwargs):
        # if not paused
        if not self.paused:
            self.pos += self.posIter*dt
            self.size += self.sizeIter*dt
            self.timeRemain -= dt
            # if finished
            if self.checkFinished():
                if self.repeat:  # repeating resets
                    self.reset()
                else:       # no repeating means pause
                    self.paused = True
    
    # render a box
    def render(self, display):
        box = (
            self.pos.x-self.size.x/2, self.pos.y-self.size.y/2,
            self.size.x, self.size.y
        )
        pygame.draw.rect(display, self.colour, box)

    # check if the tranform has finished
    def checkFinished(self):
        return (self.timeRemain <= 0)
    
    # reset everything
    def reset(self):
        self.pos = self.startPos.getCopy()
        self.size = self.startSize.getCopy()
        self.timeRemain = self.time
        self.paused = False

"""
    Transform object that will follow a path that is specified
"""
class PathTransformObject:
    def __init__(self, **kwargs):
        self.__default__(**kwargs)
    
    # default init
    def __default__(self, **kwargs):
        self.object = TransformObject(**kwargs)
        self.locations = [
            {"endPos": self.object.startPos.getCopy(), "endSize": self.object.startSize.getCopy()},
            {"endPos": self.object.endPos.getCopy(), "endSize": self.object.endSize.getCopy()},
        ]
        self.delay = self.object.time

    # add location history
    def addLocations(self, *locations):
        self.currentLocation = len(locations)-1
        self.locations.extend(locations)

    # interface for objects
    def update(self, dt=1, **kwargs):
        self.object.update(dt=dt, **kwargs)
        if self.object.checkFinished():
            self.delay -= dt
            if self.delay <= 0:
                self.cycle()

    def render(self, display):
        self.object.render(display)

    # cycle through locations
    def cycle(self):
        if self.currentLocation >= len(self.locations):
            self.currentLocation = 0
        self.object.changeLocation(**self.locations[self.currentLocation])
        self.currentLocation += 1
        self.delay = self.object.time


    
