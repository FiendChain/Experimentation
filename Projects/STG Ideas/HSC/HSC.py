"""
    A question would have a string question, a list of strings, and a threshold
    question = {
        "question": "...",
        "keywords": ["...", "...", ...],
        "threshold": ...,
    }
"""
def readQuestion(question):
    print question["question"]
    answer = raw_input("Enter your answer: ")
    keywordsDict = {word: False for word in question["keywords"]}
    answerWords = answer.split()
    for word in answerWords:
        lowerWord = word.lower()
        if lowerWord in keywordsDict:
            keywordsDict[lowerWord] = True
    totalMatched = 0
    for word, value in keywordsDict.iteritems():
        if value:
            totalMatched += 1
    correctPercent = totalMatched/float(len(question["keywords"]))
    print "You got {0}%".format(correctPercent*100)
    if correctPercent >= question["threshold"]:
        print "Correct"
    else:
        print "Incorrect"

questionList = {
    "phys1": {
        "question": "What is the Meisner effect?",
        "keywords": ["superconductor", "expulsion", "magnetic", "fields", "low", "temperature"],
        "threshold": 0.6,
    },
    "chem1": {
        "question": "Is sniffing cyclohexane a good idea?",
        "keywords": ["yes"],
        "threshold": 1,
    }
}

for name, question in questionList.iteritems():
    readQuestion(question)

