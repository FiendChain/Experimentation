from sqlobject import SQLObject
import sqlobject

from . import conn

CATEGORIES = ['Pending', 'Emergency', 'In progress', 'Finished']
TOTAL_CATEGORIES = len(CATEGORIES)

class Story(SQLObject):
    _connection = conn

    name = sqlobject.StringCol('name')
    date = sqlobject.DateTimeCol('date')
    description = sqlobject.StringCol('description')
    category = sqlobject.EnumCol('category', enumValues=CATEGORIES, default=CATEGORIES[0])
    epic = sqlobject.ForeignKey('Epic')

    def get_category_index(self):
        return CATEGORIES.index(str(self.category))

    def can_move_category_left(self):
        return (self.get_category_index() > 0)
    
    def can_move_category_right(self):
        return (self.get_category_index() < TOTAL_CATEGORIES-1)
            
    def move_category_left(self):
        index = self.get_category_index()
        if self.can_move_category_left():
            self.category = CATEGORIES[index-1]
    
    def move_category_right(self):
        index = self.get_category_index()
        if self.can_move_category_right():
            self.category = CATEGORIES[index+1]

Story.createTable(ifNotExists=True)

    