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

### 1. SameTree

Source: [LeetCode](https://leetcode.com/problems/same-tree/)

#### Scenario

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

#### Example Input

        1               1
       / \             / \
      2   3           2   3

```
Input: [1,2,3] [1,2,3]        Output: 1
Input: [1,nullptr,3] [1,2]    Output: 0
Input: [nullptr] [nullptr]    Output: 1

```
#### Function Signature

C++:

```c++
bool isSameTree(TreeNode* p, TreeNode* q) {
    
}
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

### 1. SOLUTION 1

#### Solution

To solve this problem recursively we think about the base case as the problem gets smaller. In this case, the base case is when we hit a nullptr. If we hit a nullptr, then we have reached an end leaf node.

When we traverse through the both trees in the same fashion, we can check that each value at each node is equal. If one of the values are different from the other, we return false because the trees are not the same.

Finally, the recursive calls will traverse the left and right node individually. This will traverse the whole tree and reduce the problem size until we reach the base case. 

Time complexity: We are checking each node in the tree individually with the other tree's equivalent node. Therefore, this program will lead to a time complexity of O(N) time. 

#### Naive/Simple Solution

TODO :bug:

#### Optimal Solution

```c++
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == nullptr && q == nullptr) {
        return true;
    }
    if(p == nullptr || q == nullptr) {
        return false;
    }
    if(p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
```

#### Testing The Solutions OR Driver For Solution

The solution code is [in the repository](./sametree/SameTree.cpp).

It produces the following output:

```console
$ ./a.out
0
1
```

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
