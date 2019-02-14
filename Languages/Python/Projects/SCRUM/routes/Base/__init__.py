from src.URL import BlueprintURL

base_app = BlueprintURL('base', __name__, url_prefix='', routes='resources/base_routes.json')

from . import home

from server import app
app.register_blueprint(base_app)