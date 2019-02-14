from matplotlib import pyplot as plt
import networkx as nx
import numpy as np
import copy
from labels.labels import labels

# will convert a labels list into something suitable
def sanitize_labels(labels):
    validKeys = {    # get default for empty fields
        "call": [],
        "colour": "red",
        "font_colour": "black",
        "jump": [],
        "pos": [0, 0],
    }
    for label in labels:
        for key, default in validKeys.iteritems():
            if key not in label:
                label[key] = default
            elif label[key] is None:
                label[key] = default
            elif(key in ("jump", "call") and
                    type(label[key]) is str):
                    label[key] = [label[key]]

# get dictionary of connections
def get_coloured_edges(labels):
    edges = {}
    names = [label["name"] for label in labels]
    for index, label in enumerate(labels):
        # get the call
        for call in label["call"]:
            if call in names:
                if "green" not in edges:
                    edges["green"] = []
                edges["green"].append((index, names.index(call)))
        # get jump in terms of colour
        for jump in label["jump"]:
            if jump in names:
                jumpIndex = names.index(jump)
                colour = labels[jumpIndex]["colour"]
                if colour not in edges:
                    edges[colour] = []
                edges[colour].append((index, names.index(jump)))
    return edges

# sorts nodes into different colours
def get_coloured_nodes(labels):
    colourNodes = {}
    for index, label in enumerate(labels):
        colour = label["colour"]
        if colour not in colourNodes:
            colourNodes[colour] = []
        colourNodes[colour].append(index)
    return colourNodes

# get coloured labels
def get_coloured_labels(labels):
    colourLabels = {}
    for index, label in enumerate(labels):
        colour = label["font_colour"]
        if colour not in colourLabels:
            colourLabels[colour] = []
        colourLabels[colour].append(index)
    return colourLabels


# sanitize the labels
sanitize_labels(labels)

# Get node position, colour and edges(connections)
total_nodes = len(labels)
graph = np.zeros((total_nodes, total_nodes))    # create empty graph
colourEdges = get_coloured_edges(labels)        # convert labels to array of dicts
colourNodes = get_coloured_nodes(labels)        # sort into dict with different colours
colourLabels = get_coloured_labels(labels)
pos = {index: label["pos"] for index, label in enumerate(labels)}       # get position of nodes


# create the directed graph network
G = nx.DiGraph(graph)                                           # make basic graph

# render the network
for colour, nodes in colourLabels.iteritems():
    mapping = {index: labels[index]["name"] for index in nodes}
    nx.draw_networkx_labels(G, pos, labels=mapping, font_color=colour) # draw node label names                                         
for colour, nodes in colourNodes.iteritems(): # render each node with its specified colour
    nx.draw_networkx_nodes(G, pos, node_size=2000, nodelist=nodes, node_color=colour)
for colour, edges in colourEdges.iteritems():   # draw connections
    nx.draw_networkx_edges(G, pos, arrows=True, edgelist=edges, edge_color=colour)
plt.show()                                      # use matplotlib to plot it

