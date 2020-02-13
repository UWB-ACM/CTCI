class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

def findNode(node, count, result):
  if result[0] != -1:
      return
  if node.left:
      findNode(node.left,count,result)
  count[0] -= 1
  if count[0] == 0:
      result.append(node.val)
      return
  if node.right:
      findNode(node.right,count, result)


def kthSmallest(root: TreeNode, k: int) -> int:
  count = [k]
  #why use list when it's only 1 element? because list is mutable in python.
  #So we can "pass by reference", while an int or float is immutable and cannot pass by reference.
  result = []
  findNode(root,count,result)
  return result[0]

#Create first tree to test
root = TreeNode(3)
root.left = TreeNode(1)
root.right = TreeNode(4)
root.left.right = TreeNode(2)
ans = kthSmallest(root,1)
assert(ans == 1)
#Create Second tree
root2 = TreeNode(5)
root2.right = TreeNode(6)
root2.left = TreeNode(3)
root2.left.left = TreeNode(2)
root2.left.left.left = TreeNode(1)
root2.left.right = TreeNode(4)
ans = kthSmallest(root2,3)
assert(ans == 3)
