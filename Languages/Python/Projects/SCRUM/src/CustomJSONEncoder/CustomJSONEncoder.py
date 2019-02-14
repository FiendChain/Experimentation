import json

# json encoder with decorator support
class JSONEncoder(json.JSONEncoder):
    type_list = []

    def default(self, obj):
        for obj_type, json_function in self.type_list:
            if isinstance(obj, obj_type):
                return json_function(obj)
        return json.JSONEncoder.default(self, obj)

    @staticmethod
    def add_type(obj_type):
        def decorator(func):
            if obj_type not in JSONEncoder.type_list:
                JSONEncoder.type_list.append((obj_type, func))
                return func
            else:
                raise TypeError('Type {} already exists'.format(obj_type))
        return decorator






