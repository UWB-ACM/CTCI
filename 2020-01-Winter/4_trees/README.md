<!-- Don't remove -->
<a name="top"/>

# Trees

Problems and solutions for Trees session on February 14, 2020.

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

### 1. Path Sum

Source: [Leetcode](https://leetcode.com/problems/path-sum/)

#### Scenario

Problem Statement: Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

#### Example Input
Example 1:

Given the below binary tree and sum = 22,

```
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
```
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Example 2:
Given the below binary tree and sum = 1,
```
      1
     / \
   -2   3
```
return false, as there does not exist a root-to-leaf path which sums 1.

#### Function Signature
Example C++ function signature:

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {

    //your code here
}
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

### 1. Path Sum

Source: [Leetcode]https://leetcode.com/problems/path-sum/

#### Naive/Simple Solution
This implementation uses the queue for BFS iterating over the nodes.
**Time Complexity**: O(n) where N is the number of nodes in the tree.

```c++
class Solution {
public:
 bool hasPathSum(TreeNode* root, int sum) {
  //gone through the tree, no path
  if (root == NULL)
	  return false;
 
  queue <TreeNode*> qlayer;
  qlayer.push(root);
  while (!qlayer.empty())
  {
	  TreeNode *ptr= qlayer.front();
	  //if no children
	  if (ptr->left == NULL && ptr->right == NULL)
	  {
		  //value at the end is equal to sum
		  //means there is a path from root to leaf 
		  if (ptr->val==sum)
			  return true;
	  }
	  else
	  {
		  //go layer by layer
		  //the current value is added to the left child
		  //add the node to the queue
		  if (ptr->left != NULL)
		  {
			  ptr->left->val += ptr->val;
			  qlayer.push(ptr->left);
		  }
		  //the current value is added to the right child
		  if (ptr->right != NULL)
		  {
			  ptr->right->val += ptr->val;
			  qlayer.push(ptr->right);
		  }
	  }
	  qlayer.pop();
  }
  return false;
 }
};
```

#### Optimal Solution
This implementation uses recursion  for DFS.
**Time Complexity**: `O(2^n)` -- the branch factor is two in a binary search tree and N is the number of nodes in the tree.

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		//gone through the tree, no path
		if (root == NULL)
			return false;
		//subtract root from the sum at each visited node
		sum -= root->val;
		//if no children
		if (root->left == NULL && root->right == NULL)
		{
			//sum after subtracting is equal to 0
			//means there is a path from root to leaf 
			if (sum == 0)
				return true;
		}
		//recursive call passing left child or right child as root and new sum
		return (hasPathSum(root->left, sum) || hasPathSum(root->right, sum));
	}
};
```
#### Testing The Solutions OR Driver For Solution

[Available in the repository](./4_trees/pathSum/pathSum.cpp)
```[5,4,8,11,null,13,4,7,2,null,null,null,1] sum=22 : 1(true)
    [1,-2,3] sum=1 : 0(false)
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
