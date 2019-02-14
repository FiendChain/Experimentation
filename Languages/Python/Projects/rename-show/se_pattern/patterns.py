import os
import re
import json

TITLE_PATTERN = r"(?P<title>[a-zA-Z\.\s\-]*)"
SEASON_PATTERN = r"(?P<season>\d+)"
EPISODE_PATTERN = r"(?P<episode>\d+)"
EXTENSION_PATTERN = r"\.(?P<extension>[a-zA-Z0-9]+)"

PATTERN_MAP = {
    't': TITLE_PATTERN,
    's': SEASON_PATTERN,
    'e': EPISODE_PATTERN,
    'ext': EXTENSION_PATTERN,
}

SEASON_EPISODE_PATTERNS = [
    r"{t}.*[Ss]{s}\s*[Ee]{e}.*{ext}",
    r"{t}.*(?:[Ss])eason\s*{s}\s*(?:[Ee])pisode\s*{e}.*{ext}",
    r"{t}.*{s}\s*x\s*{e}.*{ext}",
]

SEASON_EPISODE_PATTERNS = [pattern.format(**PATTERN_MAP) for pattern in SEASON_EPISODE_PATTERNS]

COMPILED_SEASON_EPISODE_PATTERNS = [re.compile(pattern) for pattern in SEASON_EPISODE_PATTERNS]

enumerable_params = ('season', 'episode')
def clean_group(group):
    fixed_group = {}
    for param in enumerable_params:
        fixed_group[param] = int(group[param])
    fixed_group['title'] = group['title'].strip(' ')
    fixed_group['extension'] = group['extension']
    return fixed_group

def get_group(file):
    for pattern in COMPILED_SEASON_EPISODE_PATTERNS:
        match = pattern.match(file)
        if match:
            group = match.groupdict()
            return clean_group(group)
    return None