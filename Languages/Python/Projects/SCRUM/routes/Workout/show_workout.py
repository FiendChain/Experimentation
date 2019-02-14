from flask import render_template, redirect, url_for, abort

from . import workout_app, system  

@workout_app.route(methods=['GET'])
@workout_app.get_template
def show_workout(workout_id, template):
    workout = system.get_workout_by_id(workout_id)
    if not workout:
        return redirect(url_for('.show_workouts'))
    return render_template(template, workout=workout)

@workout_app.route(methods=['GET'])
@workout_app.get_template
def show_workouts(template):
    return render_template(template, workouts=system.workouts)