from datetime import datetime

from .FormInput import FormInput, NO_DEFAULT
get_current_time = datetime.now

class IntFormInput(FormInput):
    """
    Convert integer field
    """
    def __init__(self, name, min=None, max=None):
        self._min = min
        self._max = max
        super().__init__(name)

    def setConstraints(self, min, max):
        if min:
            if not isinstance(min, int):
                raise TypeError('Invalid min type for FormInput')
            self._min = min
        if max:
            if not isinstance(max, int):
                raise TypeError('Invalid max type for FormInput')
            self._max = max
        if min and max:
            if max < min:
                raise ValueError('Expected max to be larger than min for FormInput')

    def checkConstraints(self, value):
        if (self._min and value < self._min) or (self._max and value > self._max):
            errorMessage = '{name} is not between {min} and {max}'
            raise ValueError(errorMessage.format(name=self.name, min=self._min, max=self._max))

    def convertStringToValue(self, string):
        try:
            value = int(string)
            self.checkConstraints(value)
        except:
            raise
        return value

class FloatFormInput(IntFormInput):
    """
    Convert float field
    """
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def convertStringToValue(self, string):
        try:
            value = float(string)
            self.checkConstraints(value)
        except:
            raise
        return value
        
class StringFormInput(FormInput):
    """
    Convert string field
    """
    def __init__(self, name, length=None, default=NO_DEFAULT):
        self._length = length
        super().__init__(name, default)
    
    def assertLength(self, string):
        if self._length and len(string) > self._length:
            errorMessage = '{name} has exceeded maximum string length of {length}'
            raise ValueError(errorMessage.format(name=self.name, length=self._length))

    def convertStringToValue(self, string: str):
        self.assertLength(string)
        string = string.strip()
        return str(string)

class DateTimeFormInput(FormInput):
    """
    Convert date field
    """
    def __init__(self, name, format, min_time=get_current_time(), max_time=None, default=NO_DEFAULT):
        self.format = format
        self.setConstraints(min_time, max_time)
        super().__init__(name, default)

    def checkIsDate(self, date):
        if not isinstance(date, datetime):
            raise TypeError('Expected datetime object for DateTimeFormInput')

    def setConstraints(self, min_time, max_time):
        if min_time:
            self.checkIsDate(min_time)
            self._min_time = min_time
        if max_time:
            self.checkIsDate(max_time)
            self._max_time = max_time
        if min_time and max_time:
            if min_time > max_time:
                raise ValueError('Minimum time cannot be more than maximum time for DateTimeInput.setConstraints')

    def checkConstraints(self, time):
        if (self._min_time and time < self._min_time) or (self._max_time and time > self._max_time):
            raise ValueError('Time for DateTimeInput is out of constraints')

    def convertStringToValue(self, string):
        time = datetime.strptime(string, self.format)
        # self.checkConstraints(time) # constraints on old events may be broken
        return time

class TimeFormInput(FormInput):
    """
    Convert time field
    """
    def __init__(self, name, format, default=NO_DEFAULT):
        self.format = format
        super().__init__(name, default)

    def convertStringToValue(self, string):
        time = datetime.strptime(string, self.format).time()
        return time

