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

def tree_3():
    root = Node(3)
    root.left = Node(1)
    root.left.left = Node(4)
    root.left.left.left = Node(5)
    root.left.left.right = Node(6)
    root.left.left.right.left = Node(1)
    root.left.right = Node(7)
    root.right = Node(2)
    root.right.right = Node(9)
    return root

def main():
    s1 = maxDepth(tree_1()) # 3
    s2 = maxDepth(tree_2()) # 5
    s3 = maxDepth(tree_3()) # 5
    assert(s1 == 3)
    assert(s2 == 5)
    assert(s3 == 5)

if __name__=="__main__":
    main()
