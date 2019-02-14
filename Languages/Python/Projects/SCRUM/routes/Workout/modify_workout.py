from flask import request, jsonify, abort

from . import workout_app, system
from .forms import workout_form, exercise_form

@workout_app.route(methods=['POST'])
def modify_workout(workout_id):
    workout = system.get_workout_by_id(workout_id)
    if not workout:
        abort(404)
    try:
        form = workout_form.readForm(request.form)
    except Exception as ex:
        return jsonify(message=str(ex), category='danger')
    else:
        workout.set(**form)
        return jsonify(message='Modified workout successfully', category='success', refresh=True)

@workout_app.route(methods=['POST'])
def modify_exercise(exercise_id):
    exercise = system.get_exercise_by_id(exercise_id)
    if not exercise:
        abort(404)
    try:
        form = exercise_form.readForm(request.form)
    except Exception as ex:
        return jsonify(message=str(ex), category='danger')
    else:
        exercise.set(**form)
        return jsonify(message='Modified exercise successfully', category='success', refresh=True)