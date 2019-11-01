# Definition for a binary tree node.
class Node:
    def __init__(self, v):
        self.val = v
        self.left = None
        self.right = None

def maxDepth(root):
    if not root:
        return 0
    return max(maxDepth(root.left), maxDepth(root.right)) + 1
