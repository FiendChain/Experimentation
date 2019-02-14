class UrlException(Exception):
    def __init__(self, *url_paths, msg=None):
        self.url = '/'.join(url_paths)
        if not msg:
            msg = "url \'{url}\' was not found".format(url=self.url)
        else:
            msg = "url \'{url}\': {msg}".format(url=self.url, msg=msg)
        
        super().__init__(msg)
        
        