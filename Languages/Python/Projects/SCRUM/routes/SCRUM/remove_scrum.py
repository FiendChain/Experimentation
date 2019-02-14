from flask import abort, jsonify

from . import scrum_app, system 

# remove scrum
@scrum_app.route(methods=['DELETE'])
def remove_scrum(scrum_id):
    scrum = system.get_scrum_by_id(scrum_id)
    if not scrum:
        return jsonify(message='Scrum doesnt exist', category='danger')
    else:
        system.remove_scrum(scrum)
        return jsonify(message='Removed scrum', category='success', refresh=True)

# remove an epic
@scrum_app.route(methods=['DELETE'])
def remove_epic(epic_id):
    epic = system.get_epic_by_id(epic_id)
    if not epic:
        return jsonify(message='Epic doesnt exist', category='danger')
    else:
        system.remove_epic(epic)
        return jsonify(message='Removed epic', category='success', refresh=True)

# remove a story
@scrum_app.route(methods=['DELETE'])
def remove_story(story_id):
    story = system.get_story_by_id(story_id)
    if not story:
        return jsonify(message='Story doesnt exist', category='danger')
    else:
        system.remove_story(story)
        return jsonify(message='Removed story', category='success', refresh=True)
