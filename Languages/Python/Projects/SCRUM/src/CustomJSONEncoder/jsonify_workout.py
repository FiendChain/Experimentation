from . import JSONEncoder

from src.Workout import Workout, Exercise
from datetime import time

@JSONEncoder.add_type(Exercise)
def jsonify_exercise(exercise):
    return {
        "id": exercise.id,
        "name": exercise.name,
        "sets": exercise.sets,
        "reps": exercise.reps,
        "rest": exercise.rest,
        "description": exercise.description,
    }

@JSONEncoder.add_type(Workout)
def jsonify_workout(workout):
    return {
        "id": workout.id,
        "name": workout.name,
        "estimated_time": workout.estimated_time,
        "description": workout.description,
        "exercises": workout.exercises,
    }

def time_to_string(time_obj: time):
    return time_obj.strftime("%H:%M")