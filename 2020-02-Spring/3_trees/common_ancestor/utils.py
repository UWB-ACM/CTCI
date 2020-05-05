# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# Reads an input array, building the tree
# left-to-right, top-to-bottom.
# A la https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
def build_tree(values):
    head = None
    if not values: return head
    
    # allocate head
    head = TreeNode(values.pop(0))
    q = [head]
    
    while q and values:
        curr = q.pop(0)
        # make left node
        left = values.pop(0)
        if left: curr.left = TreeNode(left)
        if curr.left: q.append(curr.left)
        # make right node
        right = values.pop(0)
        if right: curr.right = TreeNode(right)
        if curr.right: q.append(curr.right)
    
    return head

def find_node(root, val):
    if not root: return None
    if val == root.val: return root
    if val < root.val: return find_node(root.left, val)
    return find_node(root.right, val)
