<!-- Don't remove -->
<a name="top"/>

# Trees

Problems and solutions for Trees session on November 1, 2019.

### Table of Contents

* [Problems](#problems)
  * [1](#p1)
  * [2](#p2)
  * [3](#p3)
* [Solutions](#solutions)
  * [1](#s1)
  * [2](#s2)
  * [3](#s3)

<!-- Don't remove -->
<a name="problems"/>

## Problems

<a name="p1"/>

### 1. Maximum Depth

Source: [LeetCode](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

#### Scenario

Given a binary tree, find its maximum depth.

#### Example Input

Input:

```
      3
     / \
    1   2
   / \   \
  4   7   9
 / \
5   6
   /
  1
```

Output: `5`

#### Function Signature

C++:

```c++
int maxDepth(Node* root) {
    // your code here
}
```

Java:

```java
public int maxDepth(Node root) {
    // your code here
}
```

The class/struct Node may be defined as:

```c++
struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
};
```

<!-- Don't remove -->
Go to [Solution](#s1)   [Top](#top)

<!-- Don't remove -->
<a name="p2"/>

### 2. PROBLEM 2 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

<!-- Don't remove -->
Go to [Solution](#s2)   [Top](#top)

<!-- Don't remove -->
<a name="p3"/>

### 3. Delete Nodes and Return Forest

Source: [LeetCode](https://leetcode.com/problems/delete-nodes-and-return-forest/)

#### Scenario

You are given a tree, where each node in the tree has 
a distinct value. You are also given a structure with 
a selection of values to be deleted from the tree.

When a node is deleted from the tree, that node's 
children become the roots of their own remaining 
subtrees. The new set of tree roots form a forest.

Write a method which deletes the specified nodes, and 
return a collection of the root nodes of the trees in 
the remaining forest.

#### Example Input

![tree to forest example](./forest/forest-example.png)

#### Function Signature

C++:

```c++
/**
 * Node may be defined as:
 * struct Node {
 *     int data;
 *     Node* left = nullptr;
 *     Node* right = nullptr;
 * };
 */

vector<Node*> deleteForest(Node* root, vector<int> deleteVals) {
    // your code here
}
```

Java:

```
/**
 * Node may be defined as:
 * public class Node {
 *     public int data;
 *     public Node left;
 *     public Node right;
 * }
 */

public ArrayList<Node> deleteForest(Node root, int[] deleteVals) {
    // your code here
}
```

<!-- Don't remove -->
Go to [Solution](#s3)   [Top](#top)

<!-- Don't remove -->
<a name="solutions"/>

## Solutions

<!-- Don't remove -->
<a name="s1"/>

### 1. Maximum Depth

Source: [LeetCode](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

#### Solution Reasoning

This function is essentially a `height()` function for a binary tree.

To find the height, we recursively traverse the tree to its leaves, 
and increment a return value for each recursive call we execute. 
We take the maximum of the return values for the left and right children, 
and continue until we have resolved all recursive calls.

#### Solution

The solution is given in Python.

```python
def maxDepth(root):
    if not root:
        return 0
    return max(maxDepth(root.left), maxDepth(root.right)) + 1
```

The definition for the Node class is:

```python
# Definition for a binary tree node.
class Node:
    def __init__(self, v):
        self.val = v
        self.left = None
        self.right = None
```

#### Driver For Solution

The Python [solution](./height/solution.py) and 
[test cases](./height/driver.py) are available.

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s2"/>

### 2. SOLUTION 2 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s3"/>

### 3. Delete Nodes and Return Forest

Source: [LeetCode](https://leetcode.com/problems/delete-nodes-and-return-forest/)

#### Solution Reasoning

We want to remove nodes from the tree if the node's value has been 
flagged for removal. We need to be careful to respect node removal when a 
removed node's immediate child also needs to be removed. The simplest 
way to account for these conditions is to perform post-order traversal, 
where the subtrees are recursively processed before the root node 
of the subproblem.

We can ensure the tree's structure remains consistent between stack 
frames in the recursive calls by assigning the return value of the 
recursive function to the child node pointer in question. Thus, if an 
immediate child is removed from the subtree, we assign that child's 
pointer to `null`.

When the current root has a value that we need to delete, we first 
need to record that node's children (where present) as a forest root. 
We use a class wrapper for the forest root to ensure all roots are 
captured and persist between recursive calls.

#### Solution

We have a few helper classes to define before giving the solution.

```python
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
```

The Python solution is given as follows:

```python
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
```

#### Driver For Solution

[The complete solution](./forest/solution.py) and [tests](./forest/driver.py) are available.  

<!-- Don't remove -->
Go to [Top](#top)
