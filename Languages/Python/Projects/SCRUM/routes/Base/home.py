from flask import render_template, request, redirect, url_for, abort, jsonify

from . import base_app

@base_app.route(methods=['GET', 'POST'])
def home():
    return redirect(url_for('scrum.show_scrums'))