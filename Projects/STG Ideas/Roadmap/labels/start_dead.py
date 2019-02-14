from labels import labels

# dead
labels.extend([
    {
        "name": "dead",
        "jump": "start",
        "colour": "black",
        "font_colour": "white",
        "pos": (4.5, -3.75),
    },
    {
        "name": "deadrestart",
        "jump": "start",
        "colour": "black",
        "font_colour": "white",
        "pos": (4, -3.75),
    },
    {
        "name": "actualdead",
        "jump": None,
        "colour": "black",
        "font_colour": "white",
        "pos": (3.5, -3.75),
    },
])

# script
labels.extend([
    {
        "name": "start",
        "jump": "schoolday1",
        "colour": "purple",
        "pos": (2, -3.75),
    },
])