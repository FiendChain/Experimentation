from flask import request, abort, jsonify

from . import scrum_app, system

from .forms import scrum_form, epic_form, story_form

@scrum_app.route(methods=['POST'])
def modify_scrum(scrum_id):
    scrum = system.get_scrum_by_id(scrum_id)
    if not scrum:
        abort(404)
    try:
        form = scrum_form.readForm(request.form)
    except Exception as ex:
        return jsonify(message=str(ex), category='danger')
    else:
        scrum.set(**form)
        return jsonify(message='Modified scrum successfully', category='success', refresh=True)

@scrum_app.route(methods=['POST'])
def modify_epic(epic_id):
    epic = system.get_epic_by_id(epic_id)
    if not epic:
        abort(404)
    try:
        form = epic_form.readForm(request.form)
    except Exception as ex:
        return jsonify(message=str(ex), category='danger')
    else:
        epic.set(**form)
        return jsonify(message='Modified epic successfully', category='success', refresh=True)

@scrum_app.route(methods=['POST'])
def modify_story(story_id):
    story = system.get_story_by_id(story_id)
    if not story:
        abort(404)
    try:
        form = story_form.readForm(request.form)
    except Exception as ex:
        return jsonify(message=str(ex), category='danger')
    else:
        story.set(**form)
        return jsonify(message='Modified story successfully', category='success', refresh=True)