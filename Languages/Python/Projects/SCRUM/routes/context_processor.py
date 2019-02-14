from . import app 

@app.context_processor
def inject_current_time():
    """
    Inject current_time into jinja's global context
    """
    from datetime import datetime
    return dict(current_time=datetime.now())

@app.context_processor
def inject_id_manager():
    return dict(get_id=id)