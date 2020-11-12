<!-- Don't remove -->
<a name="top"/>

# Tree Traversal

***Problems and solutions for Tree Traversal session on November 13, 2020.***

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

### 1. Maximum Width of Binary Tree

Source: [LeetCode](https://leetcode.com/problems/maximum-width-of-binary-tree/)

#### Scenario

Given a binary tree, write a function to get the maximum width of the given tree. The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

It is **guaranteed** that the answer will in the range of 32-bit signed integer.

#### Example 1 

**Input:** 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

**Output:** 4

**Explanation:** 
 The maximum width existing in the third level with the length 4 (5,3,null,9).

#### Example 2 
**Input: **

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7

**Output:** 8
**Explanation:** 
The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).
#### Function Signature

**C++:** `int widthOfBinaryTree(TreeNode* root)`

**Java:** `int widthOfBinaryTree(TreeNode root)`

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

### 1. Maximum Width of Binary Tree

Source: [LeetCode](https://leetcode.com/problems/maximum-width-of-binary-tree/)

#### DFS Solution

The key to solve the problem is how we traverse the tree, since we need to traverse it in order to measure its width. 
Keep in mind that the width of the binary tree is the distance (number of nodes) between the left most node, and the right-most, not-null node. Any null nodes between them count as valid nodes.

To help us calculate the width, we can assigned indices to the nodes. Suppose that the indices for the first and the last nodes of one particular level are `C1` and `Cn` respectively, we could then calculate the width of this level as
`Cn - Ci + 1`.

For a full binary tree, the number of nodes double at each level, since each parent node has two child nodes. Therefore, the range of our node index would double as well. If the index of a parent node is `Ci`, the index of its left child node
is `Ci * 2`, and the index of its right child is `Ci * 2 +1`.

Using the formula above, we will manage to assign an unique index to each node in the tree, helping us to calculate the max width at each level, and to obtain the tree's max width.
 
We could traverse it in a BFS fashion, using a stack to visit each tree node, and keeping track of the index of each tree node and its value as we traverse. 

We can also solve this problem traversing the tree in a pre-order Depth First Search. We could use a table to keep only the index of the first element for each level. So, as we traverse, we could compare the index of every node with the
corresponding first index of its level. Rather than keeping all the indices in the table, we save time and space by keeping only the index of the first element per level.

To make sure we are keeping track of the index of the first element of each level, we want to prioritize visiting the left child node over the right child node in each traversal.

We label each node with a number that indicates the global order of visit/index. The nodes at the same level do get visited from left to right. 

Sample implementation code

```
C++:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//All we need is to compare the indices between the first and the last elements of the same level.  
int maxWidth = INT_MIN; // Keeps track of the maxWidth
unordered_map<int,unsigned long int> firstColTable; // table to store the index of the first node at each tree level

//Helper function to traverse the tree in a DFS
void DFS (TreeNode* currNode,  unsigned long int colIndex, int depth) {
	// If the Treenode is null, just return
	if (currNode == nullptr) {
		return ;
	}
	
	//If this is the first Treenode registered for the current level, save its index in the map
	if (firstColTable.find(depth) == firstColTable.end()) {
		firstColTable[depth] = colIndex;
	}
	//Get the index of the first node of this level
	int firstColIndex = firstColTable[depth];
	
	// calculate the current tree width
	int localWidth = colIndex - firstColIndex + 1;
	//Update value of maxWidth
	maxWidth = max(maxWidth, localWidth);
	
	//Recursively call DFS function on left child first to ensure accurate index order
	DFS(currNode->left, 2 * colIndex, depth + 1);
	//The call function on right child
	DFS(currNode->right, 2 * colIndex + 1,  depth + 1);
}


int widthOfBinaryTree(TreeNode* root) {
			
	DFS(root, 0,0);
	
	return maxWidth;
	
}
```


#### Testing The Solutions OR Driver For Solution

[Click here for the C++ driver](./QuestionOne/driver.cpp)

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
