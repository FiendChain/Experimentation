from src.URL import BlueprintURL

scrum_app = BlueprintURL('scrum', __name__, url_prefix='/SCRUM', routes='resources/scrum_routes.json')

from src.SCRUM import SCRUM_System
system = SCRUM_System()

from . import add_scrum, modify_scrum, remove_scrum, get_scrum, move_story, show_scrum

from server import app
app.register_blueprint(scrum_app)