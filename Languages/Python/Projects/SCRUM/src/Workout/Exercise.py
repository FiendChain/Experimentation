from sqlobject import SQLObject
import sqlobject

from . import conn

class Exercise(SQLObject):
    _connection = conn

    name = sqlobject.StringCol('name', length=100)
    reps = sqlobject.IntCol('reps', unsigned=True)
    sets = sqlobject.IntCol('sets', unsigned=True)
    rest = sqlobject.IntCol('rest', unsigned=True)
    description = sqlobject.StringCol('description', default=None)
    workout = sqlobject.ForeignKey('Workout')

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

Exercise.createTable(ifNotExists=True)
    