# Trees & Graphs

Problems and solutions for Trees & Graphs session on May 24, 2019.

## Background

### What is a tree?

A `tree` is a data structure that organizes information according to 
a heirarchy. As its name suggests, all items (or `nodes`) in a tree 
originate from a single node, and this organization is analogous to a 
tree's root system. The originating node is usually called the `root`.

A tree node contains the following items:
- A pointer, reference, or value called `data`
- References or pointers to child nodes

We will review two of the most common types of trees: **binary trees** 
and **binary search trees**.

#### Binary Tree

A binary tree is structured so that any node can have no more than 
two children.

A node with no children is called a leaf node. 

A binary tree has no inherent order to how data is added to the tree 
or organized inside the tree. However, the structure of the tree itself 
is guaranteed (that is, any node in a binary tree has either 0, 1, or 2 
children).

A binary tree can be defined in C++ as follows:

```c++
<template typename T>
class BinaryTree {
    public:
    private:
        Node root;
}
```

A binary tree node can be defined in C++ as follows:

```c++
<template typename T>
struct Node {
    T data;
    Node leftChild;
    Node rightChild;
};
```

An example of a binary tree that contains integers is:

![binary tree - unsorted](./background/binarytree.png)

#### Binary Search Tree

A binary search tree (BST) has all of the same properties as a binary 
tree, but also has the following additional property:

**In the BST, each node's left-hand subtree has data which is comparatively 
*smaller* than its own data. 
Similarly, each node's right-hand subtree has data which is comparatively 
*larger* than its own data.**

This property implies inherent order in the tree's data. Searching for a 
particular item in a BST is quite efficient, with a typical runtime time 
complexity of `O(log N)`.

An example of a binary search tree that contains characters is:

![binary search tree](./background/binarysearchtree.png)

### What is a graph?

## Problems

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

### 2. PROBLEM 2 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

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

### 2. PROBLEM 2 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

## 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution 

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:


