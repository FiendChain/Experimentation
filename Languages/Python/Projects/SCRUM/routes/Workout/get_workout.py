from flask import jsonify, abort

from . import workout_app, system

@workout_app.route(methods=['GET'])
def get_workouts():
    return jsonify(system.workouts)

@workout_app.route(methods=['GET'])
def get_workout(workout_id):
    workout = system.get_workout_by_id(workout_id)
    if not workout:
        abort(404)
    return jsonify(workout)

@workout_app.route(methods=['GET'])
def get_exercise(exercise_id):
    exercise = system.get_exercise_by_id(exercise_id)
    if not exercise:
        abort(404)
    return jsonify(exercise)
