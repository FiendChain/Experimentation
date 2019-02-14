from abc import ABC, abstractmethod, abstractproperty

NO_DEFAULT = object()

class FormInput(ABC):
    """
    Description:
        Base class for a form input type
    Attributes:
        _name: name of the field in form
        @property name: returns _name
    """
    def __init__(self, name, default=NO_DEFAULT):
        self._name = name
        self.default = default

    @property
    def name(self):
        return self._name

    @abstractmethod
    def convertStringToValue(self, string):
        """
        Description:
            converts string to the appropriate type
        Args:
            string: string representing the item
        Returns:
            the item associated with the string
        """
        pass