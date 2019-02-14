import os
import re
import json

from patterns import COMPILED_SEASON_EPISODE_PATTERNS, get_group

TEST_EXAMPLES = []
TEST_TITLES = ["Doctor Who", "Doctor.Who", ""]
TEST_SE_PATTERNS = [
    "S{s:02d}E{e:02d}",
    "S{s:d}E{e:d}",
    "{s:02d}x{e:02d}",
    "{s:d}x{e:d}",
    "{s:02d} x {e:02d}",
    "{s:d} x {e:d}",
    "Season {s:02d} Episode {e:02d}",
    "Season {s:d} Episode {e:d}",
    "Season{s:02d}Episode{e:02d}",
    "Season{s:d}Episode{e:d}",
]
TEST_SE_EXAMPLES = [(1, 2), (10, 3), (3, 10)]
TEST_NAMES = ["Unknown", "Space and Space", "Dot.Dot", "They're"]
TEST_EXTENSIONS = ["srt", "mp4", "avi"]

for title in TEST_TITLES:
    for se_pattern in TEST_SE_PATTERNS:
        for name in TEST_NAMES:
            for ext in TEST_EXTENSIONS:
                for se_example in TEST_SE_EXAMPLES:
                    expected = {
                        'title': title, 
                        'season': se_example[0],
                        'episode': se_example[1],
                        'extension': ext,
                    }
                    if title:
                        formatter = "{title} {se} {name}.{ext}"
                    else:
                        formatter = "{title}{se} {name}.{ext}"
                    file = formatter.format(
                        title=title, 
                        se=se_pattern.format(s=se_example[0], e=se_example[1]),
                        name=name,
                        ext=ext
                    )
                    TEST_EXAMPLES.append((file, expected))

correct_matches = []
no_matches = []
malformed_matches = []

for file, expected in TEST_EXAMPLES:
    given = get_group(file)
    if not given:
        no_matches.append(file)
    elif expected != given:
        malformed_matches.append((file, expected, given))
    else:
        correct_matches.append((file, given))

with open('correct_matches.json', 'w') as file:
    json.dump(correct_matches, file, indent=2)

with open('no_matches.json', 'w') as file:
    json.dump(no_matches, file, indent=2)

with open('malformed_matches.json', 'w') as file:
    json.dump(malformed_matches, file, indent=2)





