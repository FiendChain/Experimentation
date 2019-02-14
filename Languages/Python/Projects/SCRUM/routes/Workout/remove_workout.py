from flask import abort, jsonify

from . import workout_app, system 

# remove workout
@workout_app.route(methods=['DELETE'])
def remove_workout(workout_id):
    workout = system.get_workout_by_id(workout_id)
    if not workout:
        return jsonify(message='Workout doesnt exist', category='danger')
    else:
        system.remove_workout(workout)
        return jsonify(message='Removed workout', category='success', refresh=True)

# remove an exercise
@workout_app.route(methods=['DELETE'])
def remove_exercise(exercise_id):
    exercise = system.get_exercise_by_id(exercise_id)
    if not exercise:
        return jsonify(message='Exercise doesnt exist', category='danger')
    else:
        system.remove_exercise(exercise)
        return jsonify(message='Removed exercise', category='success', refresh=True)
