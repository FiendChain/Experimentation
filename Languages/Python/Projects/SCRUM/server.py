from flask import Flask
from flask_cors import CORS

app = Flask(__name__)
CORS(app)
app.secret_key = 'secret123'
app.config['CORS_HEADERS'] = 'Content-Type'

import routes

# add json encoder
from src import CustomJSONEncoder
app.json_encoder = CustomJSONEncoder.JSONEncoder


