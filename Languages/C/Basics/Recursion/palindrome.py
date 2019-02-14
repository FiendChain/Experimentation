string = input("Enter string: ");
words = string.split()
print(words)

wordCount = {}
for word in words:
    lowercase = word.lower()
    if str(lowercase) == str(lowercase)[::-1]:
        if word not in wordCount:
            wordCount[word] = 1
        else:
            wordCount[word] += 1

print(wordCount)
