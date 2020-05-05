def find_ancestor(root, p, q):
    """
    :type root: TreeNode
    :type p: TreeNode
    :type q: TreeNode
    :rtype: TreeNode
    """
    if not root: return None
    if root.val == p.val or root.val == q.val: return root
    if root.val > p.val and root.val > q.val:
        return find_ancestor(root.left, p, q)
    if root.val < p.val and root.val < q.val:
        return find_ancestor(root.right, p, q)
    return root
