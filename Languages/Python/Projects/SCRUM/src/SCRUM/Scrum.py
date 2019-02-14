from sqlobject import SQLObject
import sqlobject

from . import conn
from .Epic import Epic

class Scrum(SQLObject):
    _connection = conn

    name = sqlobject.StringCol('name')
    description = sqlobject.StringCol('description', default=None)
    epics = sqlobject.MultipleJoin('Epic')

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def add_epic(self, **kwargs):
        kwargs.setdefault('scrum', self)
        Epic(**kwargs)

Scrum.createTable(ifNotExists=True)
