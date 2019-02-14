from src.URL import BlueprintURL

workout_app = BlueprintURL('workout', __name__, url_prefix='/Workout', routes='resources/workout_routes.json')

from src.Workout import Workout_System
system = Workout_System()

from . import add_workout, get_workout, modify_workout, remove_workout, show_workout

from server import app
app.register_blueprint(workout_app)