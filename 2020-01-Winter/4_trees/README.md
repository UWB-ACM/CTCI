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

### 2. Kth Smallest Element in a BST

Source: [LeetCode](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

#### Scenario

Problem Statement
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

#### Example Input
Example 1
```
Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
```
Example 2
```
Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
```
#### Function Signature
```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
```
<!-- Don't remove -->
Go to [Solution](#s2)   [Top](#top)

<!-- Don't remove -->
<a name="p3"/>

### 3. Serialize and Deserialize Binary Tree

Source: [LeetCode](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)

#### Scenario

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to **serialize** and **deserialize** a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

#### Example Input

```
You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
```

#### Function Signature

```java
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

    }
```

<!-- Don't remove -->
Go to [Solution](#s3)   [Top](#top)

<!-- Don't remove -->
<a name="solutions"/>

## Solutions

<!-- Don't remove -->
<a name="s1"/>

### 1. Path Sum

Source: [Leetcode](https://leetcode.com/problems/path-sum/)

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

```c++
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

### 2. Kth Smallest Element in a BST


As we know that BST is already sorted if we transverse the tree in order. Therefore,
if we transverse the tree in order, the k node we find is the k smallest value. The
time complexity to transverse through the tree is O(2n-1) = O(n). Below is the solutions
using recursion or iteration. 
#### Recursion Solution
```python3
class Solution:
  def findNode(self,node, count, result):
      # have we found the kth node and added its value?
      if result:
          return
      if node.left:
          self.findNode(node.left,count,result)
      count[0] -= 1
      if count[0] == 0:
          result.append(node.val)
          return
      if node.right:
          self.findNode(node.right,count, result)


  def kthSmallest(self, root: TreeNode, k: int) -> int:                
      count = [k] #<= why use list when it's only 1 element? because list is mutable in python. So we can "pass by reference", while an int or float is immutable and cannot pass by reference.
      result = []
      self.findNode(root,count,result)
      return result[0]
```
#### Iteration Solution
```python3
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:                
        # Set current to root of binary tree
        current = root  
        stack = [] # initialize stack
        count = 0 #initialize count
        while True:
            # Reach the left most Node of the current Node
            if current is not None:  #if the current node is not Null or None
                stack.append(current)  #add the current node to stack so we can go back
                current = current.left  #go to the left node
            elif(stack):             #if the current node is null and stack is not empty
                current = stack.pop() #go back to previous node by popping the stack
                count+=1               # the value of the node is the (count)th smallest number
                if count == k:         #until count == k => the kth smallest value in the tree => return
                    return current.val
                current = current.right #if not check the right side.  
            else:
                break
        return -1 # no solution found
```        



#### Testing The Solutions OR Driver For Solution

The Testing is in [the repository](./Kth_Smallest_Element_in_BST).

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s3"/>

### 3. Serialize and Deserialize Binary Tree

Serialize using pre-order traversal and preserve nulls in the output. To deserialize, create a list and start "consuming" the nodes from left to right creating new `TreeNode`s as you find values.

#### Optimal Solution

```java
class Codec {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) {
            // Keep track of the nulls in the serialized string
            return "null,";
        }

        // Pre-order traversal of the tree will serialize
        // the tree easily. Pre-order traversing visits
        // current node, then left, then right.
        //
        // Traversing in this way uses the fact that recursive
        // calls keep the state of each call and this allows us
        // to keep track of where we are in the tree.
        //
        // Pre-order traversal is O(n) where n is the number of
        // nodes in the tree. Space complexity is O(n), on average
        // it can be O(height of tree).
        //
        // Appending to the string can be something to consider, in
        // Java string are immutable and appending will create a new
        // string in the string pool every time. An improvement would
        // be to use a more efficient structure like StringBuilder.
        String s = root.val + ",";
        s += serialize(root.left);
        s += serialize(root.right);
        return s;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        // First thing we can do to make things easy is to
        // turn the string into a list of Integers. A list
        // is useful becuase we can remove elements from it
        // as we process them.
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (String s : data.split(",")) {
            list.add(s.equals("null") ? null : Integer.parseInt(s));
        }

        // Now call the real deserialize logic:
        return deserialize(list);
    }

    private TreeNode deserialize(ArrayList<Integer> list) {
        // Read and remove the first element of the list
        Integer value = list.get(0);
        list.remove(0);

        // If the element is null, lets return null
        if (value == null) {
            return null;
        }

        // If not, let's create the node and recursively
        // deserialize the REMAINING (remember we already
        // sliced the list) elements of the list.
        TreeNode node = new TreeNode(value);
        node.left = deserialize(list);
        node.right = deserialize(list);
        return node;
    }
}
```

#### Testing The Solutions OR Driver For Solution

The solution code is [in the repository](./serialize-and-deserialize-a-tree/serialize-and-deserialize-a-tree.java).

<!-- Don't remove -->
Go to [Top](#top)
