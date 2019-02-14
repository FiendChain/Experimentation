from . import JSONEncoder

from src.SCRUM import Scrum, Epic, Story, CATEGORIES

DATE_FORMAT = '%Y-%m-%d'

@JSONEncoder.add_type(Scrum)
def jsonify_scrum(scrum):
    return {
        'id': scrum.id,
        'name': scrum.name,
        'description': scrum.description,
        'epics': scrum.epics,
        'categories': CATEGORIES,
    }

@JSONEncoder.add_type(Epic)
def jsonify_epic(epic):
    return {
        'id': epic.id,
        'name': epic.name,
        'description': epic.description,
        'stories': epic.stories,
    }

@JSONEncoder.add_type(Story)
def jsonify_story(story):
    def dateToString(date, format=DATE_FORMAT):
        try:
            return date.strftime(format)
        except:
            return None
    return {
        'id': story.id,
        'name': story.name,
        'date': dateToString(story.date),
        'description': story.description,
        'category': story.category,   
    }

