from flask import request, redirect, url_for, abort, jsonify

from . import scrum_app, system  

@scrum_app.route(methods=['POST'])
def move_story_left(story_id):
    story = system.get_story_by_id(story_id)
    if not story:
        abort(404)
    story.move_category_left()
    return redirect(url_for('.show_scrum', scrum_id=story.epic.scrum.id))

@scrum_app.route(methods=['POST'])
def move_story_right(story_id):
    story = system.get_story_by_id(story_id)
    if not story:
        abort(404)
    story.move_category_right()
    return redirect(url_for('.show_scrum', scrum_id=story.epic.scrum.id))