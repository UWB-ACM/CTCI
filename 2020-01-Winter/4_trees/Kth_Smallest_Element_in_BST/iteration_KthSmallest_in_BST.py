class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None


def kthSmallest(root: TreeNode, k: int) -> int:
    # Set current to root of binary tree
    current = root
    stack = [] # initialize stack
    count = 0 #initialize count
    while True:
        # Reach the left most Node of the current Node
        if current is not None:  #if the current node is not Null or None
            stack.append(current)  #add the current node to stack so we can go back
            current = current.left  #go to the left node
        elif(stack):             #if the current node is null and stack is not empty
            current = stack.pop() #go back to previous node by popping the stack
            count+=1               # the value of the node is the (count)th smallest number
            if count == k:         #until count == k => the kth smallest value in the tree => return
                return current.val
            current = current.right #if not check the right side.
        else:
            break
    return -1 # no solution found



root = TreeNode(3)
root.left = TreeNode(1)
root.right = TreeNode(4)
root.left.right = TreeNode(2)
ans = kthSmallest(root,1)
assert(ans == 1)

root2 = TreeNode(5)
root2.right = TreeNode(6)
root2.left = TreeNode(3)
root2.left.left = TreeNode(2)
root2.left.left.left = TreeNode(1)
root2.left.right = TreeNode(4)
ans = kthSmallest(root2,3)
assert(ans == 3)
