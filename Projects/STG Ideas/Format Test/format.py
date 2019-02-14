# read a string and ignore formatting
# apply a second style to it
test = "{a}b{c}"

def process(string):
    string = string.replace("{{", "{").replace("}}", "}")
    ignore = False
    formatter = "{{b}}{0}{{/b}}"
    newString = ""
    for index, char in enumerate(string):
        # toggle ignore if
        if not ignore and char == '{':
            ignore = True
        # different formatting for ignore
        if ignore:
            newString += char
        else:
            newString += formatter.format(char)
        # if character is terminating
        if ignore and char == '}':
            ignore = False
    return newString

print process(test)
print process("{{s}}Faggot{{/s}}")
