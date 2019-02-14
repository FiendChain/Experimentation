import sqlobject
from sqlobject.sqlite import builder

conn = builder()('resources/scrum.db')
