from routes import app

virtual_server = {
    'host': '0.0.0.0',
    'port': 9000,
    'debug': False,
}

localhost = {
    'host': '127.0.0.100',
    'port': 9000,
    'debug': True,
}

if __name__ == '__main__':
    from flask_jsglue import JSGlue
    jsglue = JSGlue()
    jsglue.init_app(app)
    app.run(**localhost)
