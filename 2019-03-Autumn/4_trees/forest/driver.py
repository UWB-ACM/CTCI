from solution import *

# Create example tree
def tree_1():
    root = Node(1)
    root.left = Node(2)
    root.left.left = Node(4)
    root.left.right = Node(3)
    return root

def tree_2():
    root = Node(1)
    root.left = Node(40)
    root.left.left = Node(10)
    root.left.left.left = Node(-14)
    root.left.left.right = Node(-7)
    root.left.right = Node(3)
    root.left.right.left = Node(-6)
    root.left.right.right = Node(4)
    root.right = Node(5)
    root.right.left = Node(30)
    root.right.left.left = Node(-18)
    root.right.left.left.left = Node(9)
    root.right.left.left.right = Node(17)
    root.right.left.right = Node(2)
    root.right.right = Node(-2)
    root.right.right.left = Node(-15)
    root.right.right.right = Node(8)
    root.right.right.right.right = Node(11)
    return root

def nodes_to_vals(nodes):
    return [n.val for n in nodes]

def main():
    s1 = deleteForest(tree_1(), [2, 3])
    assert(sorted(nodes_to_vals(s1)) == sorted([1, 4]))
    s2 = deleteForest(tree_2(), [5, 10, 3, -6, -18, 8])
    assert(sorted(nodes_to_vals(s2)) == sorted([1, -14, -7, 4, 9, 17, 30, -2, 11]))
    s3 = deleteForest(tree_1(), [1])
    assert(nodes_to_vals(s3) == [2])

if __name__=="__main__":
    main()
