from labels import labels

# 2 after rollcall
labels.extend([
    {
        "name": "postrollcall1",
        "jump": "TheKwokappears",
        "pos": (1, 0),
        "colour": "orange",
    },
    {
        "name": "TheKwokappears",
        "jump": ["Lyingsze", "Honestsze", "Rektrusali"],
        "pos": (1, 1),
        "colour": "orange",
    },
    {
        "name": "Lyingsze",
        "jump": "dead",
        "pos": (1.5, 0),
        "colour": "orange",
    },
    {
        "name": "Honestsze",
        "jump": "dead",
        "pos": (1.5, 1),
        "colour": "orange",
    },
    {
        "name": "Rektrusali",
        "jump": "phys1",
        "pos": (1.5, 2),
        "colour": "orange",
    },
])