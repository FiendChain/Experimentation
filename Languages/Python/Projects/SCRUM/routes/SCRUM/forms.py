from src.FormBuilder import FormBuilder, StringFormInput, DateTimeFormInput

class ScrumForm(FormBuilder):
    name        = StringFormInput('name', length=100)
    description = StringFormInput('description', length=200, default=None)

class EpicForm(FormBuilder):
    name        = StringFormInput('name', length=100)
    description = StringFormInput('description', length=200, default=None) 

class StoryForm(FormBuilder):
    name        = StringFormInput('name', length=100)
    description = StringFormInput('description', length=200, default=None)
    date        = DateTimeFormInput('date', '%Y-%m-%d', default=None)

# instantiate forms
scrum_form = ScrumForm()
epic_form = EpicForm()
story_form = StoryForm()