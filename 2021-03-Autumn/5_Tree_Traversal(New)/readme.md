# Intervals

## Table of Contents

### Problems
1. [Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/) (Medium)
2. [All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/) (Medium)
3.

## Problem 1

### Title:
[Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/) (Medium)

### Description:
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.

### Example 1:
**Input** root = [1,3,2,5,3,null,9]
**Output** 4

<br>
<br>
<br>

## Problem 2

### Title:
[All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/) (Medium)

### Description:
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

### Example 1:
**Input** root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
**Output** [7,4,1]
**Explanation** The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

<br>
<br>
<br>

# Solutions

## Solution 1

### BFS Traversal

**Approach**

```
class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        
        if(root == null) return 0;
        
        int result = Integer.MIN_VALUE;

        LinkedList<Pair<TreeNode, Integer>> q = new LinkedList<>();
        q.add(new Pair<>(root, 0));

        while(!q.isEmpty()) {

            int size = q.size();
            result = Math.max(result, (q.getLast().getValue() - q.getFirst().getValue() + 1));

            for(int i = 0; i < size; i++) {

                Pair<TreeNode, Integer> pair = q.poll();
                TreeNode item = pair.getKey();
                int index = pair.getValue();

                if(item.left != null) q.add(new Pair<>(item.left, 2*index+1));
                if(item.right != null) q.add(new Pair<>(item.right, 2*index+2));
            }
        }

        return result;
    }
}
```
<br>
<br>

## Solution 2

### BFS Traversal

**Approach**
```
class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        List<Integer> res = new ArrayList<>();
        Map<TreeNode,TreeNode> parentsMap = new HashMap<>();
        buildParentMap(root,root,parentsMap);//first root is node and second root is its parent considered
        Set<TreeNode> visited = new HashSet<>(); //keep track of visited nodes
        Queue<TreeNode> q = new LinkedList<>();//for BFS
        q.add(target);  //instead of root here we are adding target as we need to find from that node
        visited.add(target); //also target node need to be visited first
        int level = 0; //as we are using level order traversal k == level then we find all the nodes in queue
        while(q.size()>0){
            int size = q.size();
            if(level == K) return buildListFromQueue(q);//elements remaining in queue will be nodes at dist 
            for(int i = 0;i<size;i++){                  //k from target
                TreeNode t = q.remove();
                if(t.left != null && !visited.contains(t.left)){
                    q.add(t.left);
                    visited.add(t.left);
                }if(t.right != null && !visited.contains(t.right)){
                    q.add(t.right);
                    visited.add(t.right);
                }
                TreeNode parent = parentsMap.get(t);
                if(!visited.contains(parent)){ //if parent is not visited 
                    q.add(parent);//add parent to q
                    visited.add(parent);   //mark it as visited
                }
            }
            level++; //we check levelwise and each level covers 1 unit distance 
        }
            return res;
    }
    private List<Integer> buildListFromQueue(Queue<TreeNode> q){
        List<Integer> lst = new ArrayList<>();
        while(q.size()>0){
            lst.add(q.remove().val);
        }
        return lst;
    }
    private void buildParentMap(TreeNode root,TreeNode parent,Map<TreeNode,TreeNode> parentsMap){
        if(root == null)
            return;
        parentsMap.put(root,parent);
        buildParentMap(root.left,root,parentsMap); //build for left subtree root.left will be child of root
        buildParentMap(root.right,root,parentsMap);//build for right subtree
    }
}
```
<br
<br>
