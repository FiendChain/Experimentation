from src.FormBuilder import FormBuilder, StringFormInput, IntFormInput, TimeFormInput

class WorkoutForm(FormBuilder):
    name = StringFormInput('name', length=100)
    description = StringFormInput('description', default=None)
    estimated_time = TimeFormInput('estimated_time', '%H:%M', default=None)
    
class ExerciseForm(FormBuilder):
    name = StringFormInput('name', length=100)
    reps = IntFormInput('reps', min=1)
    sets = IntFormInput('sets', min=1)
    rest = IntFormInput('rest', min=1)
    description = StringFormInput('description', default=None)

workout_form = WorkoutForm()
exercise_form = ExerciseForm()