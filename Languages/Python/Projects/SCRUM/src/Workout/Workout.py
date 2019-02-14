from sqlobject import SQLObject
import sqlobject

from . import conn

class Workout(SQLObject):
    _connection = conn

    name = sqlobject.StringCol('name', length=100)
    description = sqlobject.StringCol('description', default=None)
    estimated_time = sqlobject.TimeCol('estimated_time', default=None)
    exercises = sqlobject.MultipleJoin('Exercise')

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def add_exercise(self, *args, **kwargs):
        from .Exercise import Exercise
        kwargs.setdefault('workout', self)
        Exercise(*args, **kwargs)

Workout.createTable(ifNotExists=True)
