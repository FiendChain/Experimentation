from flask import Blueprint
from functools import wraps

from .UrlException import UrlException

class BlueprintURL(Blueprint):
    def __init__(self, *args, **kwargs):
        self.load_urls(kwargs.pop('routes', None))
        super().__init__(*args, **kwargs)

    # gets route based on blueprint name and function name
    def route(self, **options):
        def decorator(func):
            rule = self.get_page_url(func.__name__)
            route_decorator = Blueprint.route(self, rule, **options)                                              
            return route_decorator(func)
        return decorator

    # wraps function with template keyword if present
    def get_template(self, func):
        @wraps(func)
        def wrapper(*args, **kwargs):
            return func(*args, **kwargs, template=self.get_page_template(func.__name__))
        return wrapper

    # get page entry
    def get_page(self, pageName):
        pages = self.urls.get('pages', None)
        if not pages:
            raise IOError("Blueprint '{}': json routes file required 'path' field".format(self.name))
        page = pages.get(pageName, None)
        if not page:
            raise UrlException(self.name, pageName, msg="page not found")
        return page

    # get url from page name
    def get_page_url(self, pageName):
        page = self.get_page(pageName)
        url = page.get("url", None)
        if not url:
            raise UrlException(self.name, pageName, msg="url not found")
        return self.insert_url_variables(url)
    
    # get template from page name
    def get_page_template(self, pageName):
        page = self.get_page(pageName)
        template = page.get("file", None)
        if not template:
            raise UrlException(self.name, pageName, msg="file not found")
        return self.insert_url_variables(template)

    # insert path variables if necessary
    def insert_url_variables(self, string):
        url_variables = self.urls.get("path", None)
        if not url_variables:
            return string
        return string.format(**url_variables)

    # load urls from json file
    def load_urls(self, routes):
        """
            Structure of json file
            {
                "path_info": {
                    "var": "folder", ...
                },
                "pages": {
                    "pageName" : {
                        "url": "required",
                        "file": "optional"
                    }, ...
                }
            }
        """
        import json
        if not routes:
            raise ValueError('Must provide path to routes json file!')
        with open(routes) as json_file:
            self.urls = json.load(json_file)
