from flask import abort, jsonify

from . import scrum_app, system

@scrum_app.route(methods=['GET'])
def get_scrums():
    return jsonify(system.scrums)

@scrum_app.route(methods=['GET'])
def get_scrum(scrum_id):
    scrum = system.get_scrum_by_id(scrum_id)
    if not scrum:
        abort(404)
    return jsonify(scrum)

@scrum_app.route(methods=['GET'])
def get_epic(epic_id):
    epic = system.get_epic_by_id(epic_id)
    if not epic:
        abort(404)
    return jsonify(epic)

@scrum_app.route(methods=['GET'])
def get_story(story_id):
    story = system.get_story_by_id(story_id)
    if not story:
        abort(404)
    return jsonify(story)
