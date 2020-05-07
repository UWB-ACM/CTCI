<!-- Don't remove -->
<a name="top"/>

# Trees

Problems and solutions for Trees session on May 8, 2020.

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

### 1. Lowest Common Ancestor

Source: [LeetCode](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

#### Scenario

Given a binary search tree (BST), find the lowest common ancestor (LCA) 
of two given nodes in the BST.

Paraphrased from the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): 

> In an arbitrary tree `T`, there exists two nodes `p` and `q`. The 
lowest common ancestor (LCA) of `p` and `q` is the lowest node in `T` 
which has both `p` and `q` as descendants. Note that a node can be a 
descendant or ancestor of itself.

#### Example Input

We are given a tree which looks like:

```
            6
           / \
          2   8
         /|   |\
        0 4   7 9
         / \
        3   5
```

<details>

<summary>Example 1</summary>

Input: `root = Node(6)`, `p = Node(2)`, `q = Node(8)`

Output: `Node(6)`

The nodes with values `2` and `8` are direct children of the root node, 
so the root node is returned as the LCA.

</details>

<details>

<summary>Example 2</summary>

Input: `root = Node(6)`, `p = Node(2)`, `q = Node(4)`

Output: `Node(2)`

`Node(4)` is a direct descendant of `Node(2)`, and a node is allowed 
to be an ancestor of itself. So, we return `Node(2)` as the LCA.

</details>

<details>

<summary>Example 3</summary>

Input: `root = Node(6)`, `p = Node(5)`, `q = Node(0)`

Output: `Node(2)`

The `p` node is one level lower than the `q` node, so the `p` node is 
not a direct descendant of the LCA. 

</details>

#### Function Signature

<details>

<summary>Java Signature</summary>

```java
/*
 * public class Node {
 *     public Node left;
 *     public Node right:
 *     public int val;
 * }
 */

public Node findAncestor(Node root, Node p, Node q) {
    // your code here
}
```

</details>

<details>

<summary>Python Signature</summary>

```python
# class Node:
#     def __init__(self, val):
#         self.val = val
#         self.left = None
#         self.right = None

def find_ancestor(root, p, q):
    # your code here
```

</details>

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

### 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

<!-- Don't remove -->
Go to [Solution](#s3)   [Top](#top)

<!-- Don't remove -->
<a name="solutions"/>

## Solutions

<!-- Don't remove -->
<a name="s1"/>

### 1. Lowest Common Ancestor

Source: [LeetCode](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

#### Solution

<details>

<summary>Solution strategy</summary>

In this problem, there are a few crucial axioms that help simplify 
the solution approach. Those axioms are:

* Both target nodes are guaranteed to exist in the tree if the tree is not empty.
* The tree is guaranteed to be a binary search tree, with all nodes in sorted order.

Using this information, we can formulate a traversal strategy that 
harnesses these properties. At each visited node, we test for the 
following properties:

1. Is the root `null`? If so, we return `null`.
2. Is the current root equal to one of the target nodes? If so, the 
   current root must be the LCA of both of the target nodes. We return 
   the current root.
3. Is the root's value **greater** than both of the target nodes? If so, 
   both nodes must be in the _left-hand subtree_. So, we call 
   the same method on the left-hand child of the current node and 
   return the result of that call.
4. Is the root's value **less** than both of the target nodes? If so, 
   we search the _right-hand_ subtree and return the result.
5. At this point, the only other possible outcome is that the target 
   nodes are **divided between the two child subtrees** of the current 
   root. If this is the case, the current node is the Lowest Common 
   Ancestor (LCA), and we return the current node.

</details>

<details>

<summary>Python solution code</summary>

```python
def find_ancestor(root, p, q):
    # edge case -- root is null
    if not root: return None

    # if we found one of the target nodes, return that node
    if root == p or root == q:
        return root

    # if both nodes are in left-hand subtree, recurse 
    # into that subtree to find the ancestor
    # NOTE: this implementation supports the convention 
    # of allowing duplicate BST entries, but all duplicates 
    # are sorted into the left-hand subtree.
    if root.val >= p.val and root.val >= q.val:
        return find_ancestor(root.left, p, q)

    # if both nodes are in right-hand subtree, recurse 
    # into that subtree to find the ancestor
    if root.val < p.val and root.val < q.val:
        return find_ancestor(root.right, p, q)

    # otherwise, the nodes are distributed across the 
    # two subtrees of the current node. this implies 
    # that the current node is the LCA.
    return root
```

</details>

#### Testing The Solutions

The coded solution is in [this `solution.py` file](./common_ancestor/solution.py). 

We wrote a few [utility functions](./common_ancestor/utils.py) which 
generate the trees and locate target nodes in the tree to set up the 
test cases. 

Lastly, the [driver file containing test cases](./common_ancestor/driver.py) 
was created to run test cases. The driver uses Python `assert` statements 
to validate the function's output, and nothing is printed to the terminal.

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

### 3. SOLUTION 3 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution 

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

<!-- Don't remove -->
Go to [Top](#top)
