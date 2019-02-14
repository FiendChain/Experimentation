from .Scrum import Scrum
from .Story import Story, CATEGORIES
from .Epic import Epic

class SCRUM_System(object):
    @property
    def scrums(self):
        return list(Scrum.selectBy())
    
    @property
    def categories(self):
        return CATEGORIES

    def get_scrum_by_id(self, scrum_id):
        return self.fetch_id(scrum_id, Scrum)
        
    def get_epic_by_id(self, epic_id):
        return self.fetch_id(epic_id, Epic)

    def get_story_by_id(self, story_id):
        return self.fetch_id(story_id, Story)

    def fetch_id(self, obj_id, sqlobject):
        try:
            obj_id = int(obj_id)
            objects = list(sqlobject.selectBy(id=obj_id))
            return objects.pop()
        except:
            return None

    def add_scrum(self, **kwargs):
        return Scrum(**kwargs)

    def remove_scrum(self, scrum):
        if isinstance(scrum, Scrum):
            Scrum.delete(id=scrum.id)

    def remove_story(self, story):
        if isinstance(story, Story):
            Story.delete(id=story.id)

    def remove_epic(self, epic):
        if isinstance(epic, Epic):
            Epic.delete(id=epic.id)
