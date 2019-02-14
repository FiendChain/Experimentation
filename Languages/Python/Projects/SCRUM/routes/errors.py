from flask import render_template, jsonify
from . import app

@app.errorhandler(404)
def page_not_found(e):
    return jsonify(error=404, text=str(e)), 404






    



