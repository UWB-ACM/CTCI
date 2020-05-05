def find_ancestor(root, p, q):
    # edge case -- root is null
    if not root: return None

    # if we found one of the target nodes, return that node
    if root.val == p.val or root.val == q.val:
        return root

    # if both nodes are in left-hand subtree, recurse 
    # into that subtree to find the ancestor
    if root.val > p.val and root.val > q.val:
        return find_ancestor(root.left, p, q)

    # if both nodes are in right-hand subtree, recurse 
    # into that subtree to find the ancestor
    if root.val < p.val and root.val < q.val:
        return find_ancestor(root.right, p, q)

    # otherwise, the nodes are distributed across the 
    # two subtrees of the current node. this implies 
    # that the current node is the LCA.
    return root
