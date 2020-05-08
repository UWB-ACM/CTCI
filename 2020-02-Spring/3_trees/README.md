<!-- Don't remove -->
<a name="top"/>

# Topic Name TODO :bug:

Simple description TODO :bug:

In the style of:
***Problems and solutions for Maze & Dynamic Programming session on March 1, 2019.***

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

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

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

### 3. Recover Binary Search Tree

[LeetCode](https://leetcode.com/problems/recover-binary-search-tree/)

#### Scenario

Two elements of a binary search tree (BST) are swapped by mistake.
The tree is now no longer a binary search tree.

Recover the tree so it is a binary search tree again without changing its structure.

**Follow-up**: Can you devise a constant space solution? In other words, can you come up with a solution that does not use an auxilliary data structure?

#### Example Input

**Example 1:**


Input: [1,3,null,null,2]

```
   1
  /
 3
  \
   2
```

Output: [3,1,null,null,2]

```
   3
  /
 1
  \
   2
```

**Example 2:**

Input: [3,1,4,null,null,2]

```
  3
 / \
1   4
   /
  2
```

Output: [2,1,4,null,null,3]

```
  2
 / \
1   4
   /
  3
```

#### Function Signature

##### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

public void recoverTree(TreeNode root) {
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

### 3. Recover Binary Search Tree Solution

#### Basic Solution 

<details>
<summary>Click to see basic solution</summary>

##### Algorithm Overview

Recall the invariants of a binary search tree:

* **Structural property**: a BST is a binary search tree

* **Ordering propety**: For every node `X` in a BST:
  
  * the key in `X` is greater than every key in the node's LEFT subtree
  * the key in `X` is smaller than every key in the node's RIGHT subtree


Also recall that the inorder traversal of a binary search tree is sorted in ascending order. 

The key idea behind this problem is understanding which invariant would be violated if a pair of the nodes were swapped.
Additionally, you must also use the properties of the inorder traversal of a binary search tree to identify the nodes that you must fix.

1. Create an inorder traversal of the tree. This will be an almost sorted list.
2. Find two nodes in the almost sorted list that are not in sorted order.
3. Traverse the tree and fix the nodes that are not in sorted order.

##### Complexity Analysis

* ***Time Complexity***: `O(N)`

    * `O(N)` - Inorder traversal of a binary search tree
    * `O(N)` - Finding the swapped nodes (in the worst case)
    * `O(N)` - Fixing the swapped nodes

* ***Space Complexity***: `O(N)`

    * `O(N)` - Space occupied by the call stack during the recursive traversals of the binary tree. In the worst case, `O(N)` when the binary tree is a degenerate tree.
    * `O(N)` - Space used to store the inorder traversal


<details>
<summary>Click to see basic solution</summary>

```java
    // Recursive inorder traversal with O(n) space
    public static void inorderTraversal(TreeNode root, List<Integer> nodes) {
        if (root != null) {
            inorderTraversal(root.left, nodes);
            nodes.add(root.val);
            inorderTraversal(root.right, nodes);
        }
    }

    // Helper method that finds the first two values
    // that are not in ascending order
    public static int[] findSwappedValues(List<Integer> values) {
        int length = values.size();
        int first = -1;
        int second = -1;
        for (int i = 0; i < length - 1; i++) {
            if (values.get(i + 1) < values.get(i)) {
                if (first == -1) {
                    first = values.get(i);
                    second = values.get(i + 1);
                } else {
                    second = values.get(i + 1);
                    break;
                }
            }
        }
        return new int[]{first, second};
    }

    // Helper method that finds the nodes that have the given values
    // and swaps their values
    public static void fixSwaps(TreeNode root, int fixes, int first, int second) {
        if (root != null) {
            if (root.val == first || root.val == second) {
                if (root.val == first) {
                    root.val = second;
                } else {
                    root.val = first;
                }
                if (--fixes == 0) return;
            }
            fixSwaps(root.left, fixes, first, second);
            fixSwaps(root.right, fixes, first, second);
        }
    }

    public static void recoverTree(TreeNode root) {
        List<Integer> nodes = new ArrayList<>();
        inorderTraversal(root, nodes);
        int[] swapped = findSwappedValues(nodes);
        fixSwaps(root, 2, swapped[0], swapped[1]);
    }

```

</details>


</details>


#### Optimal Solution

<details>
<summary>Click to see optimal solution</summary>

##### Algorithm Overview

**Inorder Traversal + Swap Detection in One Pass**

Instead of building the inorder traversal list and traversing that list to find the swapped nodes, we can combine these steps to traverse the tree and find the swapped nodes in one pass.
While performing the inorder traversal, we can compare the previous node to the current node that we are visiting.
If we find a node that is not smaller than the previous node, the node must be a swapped node. 


**Morris Traversal** 

This answers the follow-up question: Can you solve this using `O(1)` space?

Normally, with inorder traversal, you traverse the left subtree, then you visit the current node, then you traverse the right subtree.

You normally must use recursion or a stack is used so:

* You know when the left subtree has been fully visited
* You can revisit the left subtree's parent node and traverse the right subtree

Morris traversal gets around this by setting a link between a node that has a left subtree and its ***inorder predecessor***.
The inorder predecessor is the node that occurs immediately before a node in an inorder traversal.
It also happens to be the last node that is visited when you're done traversing a node's left subtree.

We can take advantage of this property to always have a "portal" back to a parent node without needing to store nodes in a stack of some kind, whether it be the call stack or an stack that you create.

![Morris example 1](./images/del_pred.png)


**Finding Inorder Predecessor Pseudocode**

```
current = root
predecessor = null
while current exists
  # Take one step left
  predecessor = root.left
  while predecessor.right exists
    # Morris traversal modification:
    # Check if we have a link to the parent node
    if predecessor.right is root
      break
    # Otherwise, go as far right as possible
    predecessor = predecessor.right

```


![Morris example 2](./images/morris-example.PNG)

**Morris Traversal Pseudocode**
```
current = root
while current exists
  if current->left doesn't exist
    # If there is no left subtree, no need to look for predecessor
    visit(current)
    current = current.right
  else
    # Before visiting left subtree, find predecessor
    predecessor = findInorderPredecessor(current)
    if predecessor.right doesn't exist
      predecessor.right = current  # Link predecessor to parent node
      current = current.left       # Visit left subtree
    else
      predecessor.right = null    # Predecessor link already exists
      visit(current)
      current = current.right     # Visit right subtree (no more left subtree to visit)
```


See [this YouTube video](https://www.youtube.com/watch?v=wGXB9OWhPTg) for a more detailed step-by-step explanation of Morris inorder traversal.

Also see [this Google Slides presentation](https://docs.google.com/presentation/d/11GWAeUN0ckP7yjHrQkIB0WT9ZUhDBSa-WR0VsPU38fg/edit#slide=id.g61bfb572cf_0_214) to see another example of stepping through a binary tree with Morris inorder traversal.


##### Complexity Analysis

* ***Time Complexity***: `O(N)`

    * O(N) - Every node must be visited at least once during the traversal
    * O(N) - In the worst case, every node is visited again while searching for an inorder predecessor, in the case of a degenerate tree
  
* ***Space Complexity***: `O(1)`

    * No new data structures are created. Only pointers are used.


<details>
<summary>Click to see Morris traversal solution</summary>

```java

// Helper method for swapping the values of two nodes
public void swap(TreeNode a, TreeNode b) {
  int temp = a.val;
  a.val = b.val;
  b.val = temp;
}

public void recoverTree(TreeNode root) {
  TreeNode first = null;
  TreeNode second = null;
  TreeNode predecessor = null; // For Morris traversal
  TreeNode previous = null;    // For finding the swapped nodes

  while (root != null) {
    if (root.left != null) {
      // Find inorder predecessor of root
      predecessor = root.left;
      while (predecessor.right != null && predecessor.right != root) {
        predecessor = predecessor.right;
      }
      // If there is no link to the parent node
      // Create one, then visit the left subtree
      if (predecessor.right == null) {
        predecessor.right = root;
        root = root.left;
      } else {
        // Link already exists. We're done with the left subtree

        // Check to see if this node is swapped
        if (previous != null && root.val < previous.val) {
          second = root;
          if (first == null) first = previous;
        }
        previous = root;          // Save this node for swap comparison

        predecessor.right = null; // Break the existing link
        root = root.right;        // Go to the right subtree
      }
    } else {
      // No left subtree. No need to check for predecessors. Just go right.
      
      // Check to see if this node is swapped
      if (previous != null && root.val < previous.val) {
        second = root;
         if (first == null) first = previous;
      }
      previous = root;          // Save this node for swap comparison
      
      root = root.right; // Go to the right subtree
    }
  }
  // We are done traversing through the tree.
  // We can swap the nodes now.
  swap(first, second);
}

```

</details>

</details>


#### Driver for Solution

See [the full solution file](./recover_bst/java/Solution.java) for helper methods.

```java

    public static void main(String[] args) {
        List<Integer> treeList1 = new ArrayList<>(Arrays.asList(1, 3, null, null, 2));
        List<Integer> treeList2 = new ArrayList<>(Arrays.asList(3, 1, 4, null, null, 2));

        TreeNode tree1 = buildTree(treeList1);
        TreeNode tree2 = buildTree(treeList2);

        printTree(tree1); // Before: [ 3 2 1 ]
        printTree(tree2); // Before: [ 1 3 2 4 ]

        recoverTree(tree1);
        recoverTree(tree2);

        printTree(tree1); // After: [ 1 2 3 ]
        printTree(tree2); // After: [ 1 2 3 4 ]
    }

```


<!-- Don't remove -->
Go to [Top](#top)
