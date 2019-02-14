from .Workout import Workout
from .Exercise import Exercise

class Workout_System(object):
    @property
    def workouts(self):
        return list(Workout.selectBy())

    @property
    def exercises(self):
        return list(Exercise.selectBy())

    def remove_workout(self, workout):
        if isinstance(workout, Workout):
            Workout.deleteBy(id=workout.id)

    def remove_exercise(self, exercise):
        if isinstance(exercise, Exercise):
            Exercise.deleteBy(id=exercise.id)

    def add_workout(self, *args, **kwargs):
        Workout(*args, **kwargs)

    def get_exercise_by_id(self, exercise_id):
        return self.fetch_id(exercise_id, Exercise)
    
    def get_workout_by_id(self, workout_id):
        return self.fetch_id(workout_id, Workout)

    def fetch_id(self, obj_id, sqlobject):
        try:
            obj_id = int(obj_id)
            objects = list(sqlobject.selectBy(id=obj_id))
            return objects.pop()
        except:
            return None 
