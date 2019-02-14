# use this for clarity
class AttrDict(dict):
    def __init__(self, init={}):
        dict.__init__(self, init)
        
    def __getattr__(self, name):
        return self[name]

    def __setattr__(self, name, value):
        self[name] = value

    def combine(self, otherDict):
        self.update(otherDict)
        return self

# Manage branches in the game for groundhog day style
class BranchManager:
    """
        self.labels = {
            "start" : {
                "labels": ["start1", "start2", "finish", "death"],
                "current": 0,
            },
        }
    """
    def __init__(self, labelList={}):
        self.labels = {}
        self.addLabels(labelList)
        
    def addLabels(self, labelList):
        for name, labels in labelList.iteritems():
            if type(labels) is not list:
                raise TypeError("Expect list for labelList, not {0}".format(type(labels)))
            self.labels[name] = AttrDict({
                "labels": labels,
                "current": 0,
            })

    def resetLabel(self, label):
        if label in self.labels:
            self.labels[label].current = 0

    def jumpLabel(self, label):
        # internal label that is tracked
        if label in self.labels:
            labelList = self.labels[label]
            if labelList.current < len(labelList.labels):
                # jump to currnet label
                currentLabel = labelList.labels[labelList.current]
                if currentLabel == label:
                    raise NameError("Recursive label {0}".format(label))
                else:
                    self.jumpLabel(currentLabel)
                    labelList.current += 1
            else:
                renpyJump(labelList.labels[-1])
        # non internal label that has no list
        else:
            try:
                renpyJump(label)
            except:
                raise NameError("{0} is a non existent label".format(label))

    def describe(self):
        print ">>> Describing {0}".format(self)
        for name, label in self.labels.iteritems():
            print "{0} = '{{'".format(name)
            self.describeLabel(label, header="\t")
            print "},"
        print ""
    
    def describeLabel(self, label, header=""):
        print "{0}{{".format(header)
        for key, value in label.iteritems():
            print "{0}\t{1}: {2},".format(header, key, value)
        print "{0}}},".format(header)

def renpyJump(label):
    print("Jumped to: {0}".format(label))

def main():
    # testing functions
    def jump(label):
        branches.jumpLabel(label)

    def cycleLabel(label, total=10):
        print ">>> Cycling through label: {0}".format(label)
        for i in xrange(total):
            jump(label)
        print ""

    # instance
    branches = BranchManager()
    branches.addLabels({
        "start": ["start1", "start2", "start3", "start4", "finish"],
        "morning": ["moxGreet", "moxAttack", "moxKill", "moxRape", "moxLive"],
        "serena": ["serenaIgnore", "serenaHi", "serenaDeath", "death"],
        "death": ["death1", "death2", "death3"],
    })

    # testing
    branches.describe()

    for label in ("start", "morning", "serena", "death"):
        cycleLabel(label)
    
    print ">>> Resetting death branch"
    branches.resetLabel("death")
    cycleLabel("death")

if __name__ == "__main__":
    main()
            