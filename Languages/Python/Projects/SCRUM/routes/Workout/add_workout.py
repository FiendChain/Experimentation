from flask import request, jsonify, abort

from . import workout_app, system
from .forms import workout_form, exercise_form

@workout_app.route(methods=['POST'])
def add_workout():
    try:
        form = workout_form.readForm(request.form)
    except Exception as ex:
        return jsonify(message=str(ex), category='danger')
    else:
        system.add_workout(**form)
        return jsonify(message='Added workout', category='success', refresh=True)

@workout_app.route(methods=['POST'])
def add_exercise(workout_id):
    print(request.form)
    workout = system.get_workout_by_id(workout_id)
    if not workout:
        abort(404)
    try:
        form = exercise_form.readForm(request.form)
    except Exception as ex:
        return jsonify(message=str(ex), category='danger')
    else:
        workout.add_exercise(**form)
        return jsonify(message='Added exercise', category='success', refresh=True)
