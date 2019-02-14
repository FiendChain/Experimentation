from flask import request, abort, jsonify

from . import scrum_app, system 

from .forms import scrum_form, epic_form, story_form 

@scrum_app.route(methods=['POST'])
def add_scrum():
    try:
        form = scrum_form.readForm(request.form)
    except Exception as ex:
        return jsonify(message=str(ex), category='danger')
    else:
        system.add_scrum(**form)
        return jsonify(message='Added scrum', category='success', refresh=True)

@scrum_app.route(methods=['POST'])
def add_epic(scrum_id):
    scrum = system.get_scrum_by_id(scrum_id)  
    if not scrum:
        abort(404)
    try:
        form = epic_form.readForm(request.form)
    except Exception as ex:
        return jsonify(message=str(ex), category='danger')
    else:
        scrum.add_epic(**form)
        return jsonify(message='Added epic', category='success', refresh=True)

@scrum_app.route(methods=['POST'])
def add_story(epic_id):
    epic = system.get_epic_by_id(epic_id)
    if not epic:
        abort(404)
    try:
        form = story_form.readForm(request.form)
    except Exception as ex:
        return jsonify(message=str(ex), category='danger')
    else:
        epic.add_story(**form)
        return jsonify(message='Added story', category='success', refresh=True)