# Testing objects as game management tools
class Person:
    def __init__(self, name, friendship, intellect, agility):
        self.name = name
        self.friendship = friendship
        self.intellect = intellect
        self.agility = agility
    def response(self, demand):
        agreement = (self.friendship-self.intellect)**2
        if agreement >= demand:
            self.friendship += demand/2
            return True
        else:
            self.friendship -= demand/2
            return False
    def showInfo(self, newline):
        if newline > 0:
            endChar = '\n'
        else:
            endChar = ''
        print('Friendship:', self.friendship, end=endChar)
        print('Intellect:', self.intellect, end=endChar)
        print('Agility:', self.agility, end=endChar)

        


class FriendList:
    def __init__(self, friends):
        self.friendInfo = {}
        self.friends = friends
        for friend in friends:
            self.friendInfo[friend] = Person(friend, 0, 0, 0)
    def addFriend(self, name, friendship, intellect, agility):
        if name in friends:
            return
        else:
            self.friends.append(name)
            self.friendInfo[name] = Person(name, friendship, intellect, agility)
    def showFriends(self):
        for friend in self.friends:
            response = self.friendInfo[friend].response(0)
            print('=' + friend + '=')
            self.friendInfo[friend].showInfo(newline=True)
            

friends = ['A1', 'A2', 'A3', 'A4', 'B1', 'B2', 'B3', 'B4']
friendlist = FriendList(friends)
friendlist.addFriend('Jeremy Clarkson', 0, 0, 0)
friendlist.showFriends()





        