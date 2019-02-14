# Import the namedtuples module
from collections import namedtuple

# Creating a nametuple
PersonInfo = namedtuple('PersonInfo', 'age atar uni')

# Creating a dictionary with named tuples
friendInfo = {
    'Zeus'      : PersonInfo(age=20, atar=99    , uni='UNSW'),
    'Chronos'   : PersonInfo(age=50, atar=99.65 , uni='UTS')
}
# Iterating through the dictionary
for friend in friendInfo:
    print(friend, ':', friendInfo[friend])
''' 
    Prints out:
        Chronos : PersonInfo(age=50, atar=99.65, uni='UTS')
        Zeus : PersonInfo(age=20, atar=99, uni='UNSW')
    NOTE:
        friend = keys contained in the dictionary
        NOT the data contained inside the dictionary
'''