#!/usr/bin/python3

from App import App
from Vector import Vector
from TransformObject import TransformObject
from TransformObject import PathTransformObject
from Colours import colour

def main():
    app = App()
    # adding moving box
    movingBox = PathTransformObject(
        startPos = Vector(0, 0),
        endPos = app.resolution/2,
        startSize = Vector(100, 100),
        endSize = Vector(10, 10),
        time = 1,
        colour = colour["white"],
        repeat = False,
    )
    movingBox.addLocations(
        {"endPos": app.resolution/3, "endSize": Vector(100, 20), "time": 2,},
        {"endPos": Vector(500, 200), "endSize": Vector(8, 5), "time": 0.3,},
        {"endPos": app.resolution/2, "endSize": Vector(20, 100), "time": 1,},
    )
    app.addObjects(movingBox=movingBox, rainbow=colour["rainbow"])
    while app.run():
        print("time: {:.02f}".format(app.timeElapsed), end="\r", flush=True)

if __name__ == "__main__":
    main() 