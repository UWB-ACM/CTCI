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

Recover the tree without changing its structure.

**Follow-up**: Can you devise a constant space solution?

#### Example Input

**Example 1:**


Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2


**Example 2:**

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3


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

### 3. Recover Binary Search Tree Solution

#### Basic Solution 

<details>
<summary>Click to see basic solution</summary>

##### Algorithm Overview

The key idea behind this problem is using the properties of the inorder traversal of a binary search tree to identify the nodes that you must fix.

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


##### Complexity Analysis

* ***Time Complexity***: `O(N)`

    * O(N) - Finding the middle node of the linked list (N / 2 operations, which is asymptotically O(N))
    * O(N) - Reversing the second half of the linked list (N / 2 operations, which is asymptotically O(N))
    * O(N) - Merging the in-order list and reversed linked list (N / 2 operations, which is asymptotically O(N))

* ***Space Complexity***: `O(1)`

    * No new data structures are created. Only pointers are used to manipulate the nodes of the linked list. 



</details>

TODO :bug:

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
