from flask import render_template, redirect, url_for, abort

from . import scrum_app, system  

@scrum_app.route(methods=['GET'])
@scrum_app.get_template
def show_scrum(scrum_id, template):
    scrum = system.get_scrum_by_id(scrum_id)
    if not scrum:
        return redirect(url_for('.show_scrums'))
    return render_template(template, scrum=scrum, categories=system.categories)

@scrum_app.route(methods=['GET'])
@scrum_app.get_template
def show_scrums(template):
    return render_template(template, scrums=system.scrums)






    



