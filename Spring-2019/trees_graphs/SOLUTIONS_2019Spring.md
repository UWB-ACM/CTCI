# Trees & Graphs

Problems and solutions for Trees & Graphs session on May 24, 2019.

## Problems

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

### 2. Unique Binary Search Trees

Source: [leetcode](https://leetcode.com/problems/unique-binary-search-trees-ii/)

#### Scenario

Given an integer `n`, generate all structurally unique BST's (binary search trees)  that store values 1 ... n using preorder traversal. 

#### Example Input
```
Input: 3
Output:
[1, 2, 3]
[1, 3, 2]
[2, 1, 3]
[3, 1, 2]
[3, 2, 1]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

1         3     3      2      1
 \       /     /      / \      \
  3     2     1      1   3      2
 /     /       \                 \
2     1         2                 3
```

#### Function Signature

Java:

```java
/**
* Definition for a binary tree node.
* public class TreeNode {
*     int val;
*     TreeNode left;
*     TreeNode right;
*     TreeNode(int x) { val = x; }
* }
*/

public List<TreeNode> generateTrees(int n) {}
```

C++:

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

vector<TreeNode*> generateTrees(int n) {}
```
### 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

## Solutions

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

### 2. Unique Binary Search Trees

Source: [GeeksforGeeks](https://www.geeksforgeeks.org/construct-all-possible-bsts-for-keys-1-to-n/)

#### Optimal Solution

The optimal solution for this problem is to maintain a list of roots of all BSTs. Recursively construct all possible left and right subtrees. Create a tree for every pair of left and right subtree and add the tree to list.

Time Complexity: `O(n)`

Here is a solution method:

Java:

```java
public List<TreeNode> generateTrees(int n) {
    if(n==0){
        return new ArrayList<TreeNode>();
    }
    return helper(1, n);
}

public List<TreeNode> helper(int m, int n){
    List<TreeNode> result = new ArrayList<TreeNode>();
    if(m>n){
        result.add(null);
        return result;
    }
    for(int i=m; i<=n; i++){
        List<TreeNode> ls = helper(m, i-1);
        List<TreeNode> rs = helper(i+1, n);
        for(TreeNode l: ls){
            for(TreeNode r: rs){
                TreeNode curr = new TreeNode(i);
                curr.left=l;
                curr.right=r;
                result.add(curr);
            }
        }
    }
    return result;
}    
```

#### Testing The Solutions OR Driver For Solution

The executable Java solution for this problem is located under  `Spring-2019/trees_graphs/Problem2_UniqueBTS/UniqueBTS.java`.

The output for Java solution where `n` = 4 is:

```console
The total of unique binary search trees: 14
Generate the tree in preorder traversal
[1, 2, 3, 4,]
[1, 2, 4, 3,]
[1, 3, 2, 4,]
[1, 4, 2, 3,]
[1, 4, 3, 2,]
[2, 1, 3, 4,]
[2, 1, 4, 3,]
[3, 1, 2, 4,]
[3, 2, 1, 4,]
[4, 1, 2, 3,]
[4, 1, 3, 2,]
[4, 2, 1, 3,]
[4, 3, 1, 2,]
[4, 3, 2, 1,]
```

## 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution 

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:


