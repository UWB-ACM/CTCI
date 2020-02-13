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

### 2. PROBLEM 2 k smallest element in a BST

Source: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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

### 2. SOLUTION 2


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
      result = [-1]
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
