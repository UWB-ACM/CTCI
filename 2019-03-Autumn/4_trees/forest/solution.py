# Definition for a binary tree node.
class Node:
    def __init__(self, v):
        self.val = v
        self.left = None
        self.right = None

# A wrapper class to maintain forest
class RemovalHelper:
    def __init__(self, to_delete):
        self.items_to_remove = to_delete
        self.root_nodes = []

# The entry function
def deleteForest(root, to_delete):
    wrapper = RemovalHelper(to_delete)
    # Walk the tree and generate forest
    root = traversal_helper(root, wrapper)
    # Add root to forest if root was not removed
    if root:
        wrapper.root_nodes.append(root)
    return wrapper.root_nodes

# Core traversal logic for solution
def traversal_helper(root, wrapper):
    # Base case
    if root is None:
        return None
    # Post-order Traversal
    root.left = traversal_helper(root.left, wrapper)
    root.right = traversal_helper(root.right, wrapper)
    # Should we remove this node from the tree?
    # If so, we need to record the new roots in the forest.
    if root.val in wrapper.items_to_remove:
        if root.left:
            wrapper.root_nodes.append(root.left)
        if root.right:
            wrapper.root_nodes.append(root.right)
        return None
    return root
