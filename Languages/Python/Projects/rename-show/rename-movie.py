import re
import os
import sys
import pprint as pp

TITLE_PATTERN = r"(?P<title>[a-zA-Z0-9\s\.\-]*)"
YEAR_PATTERN = r"(?P<year>(?:20|19)\d\d)"
EXTENSION_PATTERN = r"\.(?P<extension>[a-zA-Z0-9]+)"

MOVIE_PATTERN = r"{t}.*{y}.*{ext}".format(
    t=TITLE_PATTERN,
    y=YEAR_PATTERN,
    ext=EXTENSION_PATTERN)
COMPILED_MOVIE_PATTERN = re.compile(MOVIE_PATTERN)

PROPER_FORMAT = "{title} ({year:04d}).{extension}"

def main():
    if len(sys.argv) <= 1:
        translations = recurive_fetch()
        pp.pprint(translations, width=100)
        if get_prompt():
            print('Renaming files')
            recursive_rename(translations) 
    elif len(sys.argv) >= 2:
        file = re.sub(r"\.\\", "", sys.argv[1])
        if os.path.isfile(file):
            title = None if len(sys.argv) <= 2 else sys.argv[2]
            new_file = get_proper_format(file, title)
            if new_file:
                print('{}: {}'.format(file, new_file))
                if get_prompt():
                    os.rename(file, new_file)
            else:
                print("{} has invalid format for movie".format(file))
        else:
            print("{} is not a valid file".format(file))

def get_prompt(msg='Are you sure you want to continue?', responses=('y', 'Y')):
    response = input(msg+' ')
    if response in responses:
        return True
    return False

def recursive_rename(translations, path='.'):
    for old_file, new_file in translations.items():
        if isinstance(new_file, str):
            os.rename(os.path.join(path, old_file), os.path.join(path, new_file))
        elif isinstance(new_file, dict):
            recursive_rename(new_file, os.path.join(path, old_file))

def recurive_fetch(path='.', depth=1):
    translations = {}
    for file in os.listdir(path):
        filepath = os.path.join(path, file)
        if os.path.isfile(filepath):
            translations[file] = get_proper_format(file)
        elif os.path.isdir(filepath):
            translations[file] = recurive_fetch(filepath, depth+1)
    return translations

def get_proper_format(file, default_title=None):
    group = get_group(file)
    if not group:
        return None
    group = clean_group(group)
    if default_title:
        group['title'] = default_title
    return PROPER_FORMAT.format(**group)
    
def get_group(file):
    match = COMPILED_MOVIE_PATTERN.match(file)
    if not match:
        return None
    return match.groupdict()

def clean_group(group):
    fixed_group = {}
    title = re.sub(r"\.+", " ", group['title'])
    title = title.strip(' ')
    fixed_group['title'] = title
    fixed_group['year'] = int(group['year'])
    fixed_group['extension'] = group['extension']
    return fixed_group

if __name__ == '__main__':
    main()
