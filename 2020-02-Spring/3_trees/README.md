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

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): 
"The lowest common ancestor is defined between two nodes p and q as 
the lowest node in T that has both p and q as descendants (where we 
allow a node to be a descendant of itself)."

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
not a direct decendant of the LCA. 

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

### 1. SOLUTION 1 TODO :bug:

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
