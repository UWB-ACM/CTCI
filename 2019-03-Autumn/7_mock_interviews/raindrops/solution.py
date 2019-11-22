class Node:
    def __init__(self, edges):
        self.edges = edges

class Edge:
    def __init__(self, time, node):
        self.weight = time
        self.node = node

def saturation_time(root):
    # base case: current node is a leaf
    if not root or not root.edges:
        return 0
    # construct a list of subtree maximum paths
    l = []
    for e in root.edges:
        l.append(e.weight + saturation_time(e.node))
    # return the maximum of the constructed list
    return max(l)

def saturation_time_pythonic(root):
    # base case: current node is a leaf
    if not root or not root.edges:
        return 0
    # find maximum of list of subtree paths
    return max([e.weight + saturation_time(e.node) for e in root.edges])
