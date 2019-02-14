from sqlobject import SQLObject
import sqlobject

from . import conn 
from .Story import Story

class Epic(SQLObject):
    _connection = conn

    name = sqlobject.StringCol('name')
    description = sqlobject.StringCol('description', default=None)
    scrum = sqlobject.ForeignKey('Scrum')
    stories = sqlobject.MultipleJoin('Story')

    def add_story(self, **kwargs):
        kwargs.setdefault('epic', self)
        Story(**kwargs)

Epic.createTable(ifNotExists=True)

    