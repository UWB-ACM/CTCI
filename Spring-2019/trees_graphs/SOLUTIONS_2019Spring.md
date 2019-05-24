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

A graph is also a data structure that organizes and shows relationships 
between individual data nodes. However, a graph is not organized in a 
heirarchal way the way a tree is. Nodes in a graph are not required 
to be connected, and connections (or _edges_) between nodes can be 
created and destroyed dynamically.

It is useful to observe that a tree is a form of an undirected graph.

Graphs are meaningful in the context of computer science because they 
are an excellent model for social interactions. Most social media interactions 
can be represented using graphs.

#### Undirected Graphs

![facebook as an undirected graph](./background/facebook-undirected.png)

#### Directed Graphs

![twitter as a directed graph](./background/twitter-directed.png)

#### Weighted Graphs

Until now, we have looked at graphs whose connections do not have any 
special qualities. A common quality that graph edges might possess are 
_weights_. Weights are usually associated with a cost or benefit of 
the relationship between the nodes. 

Consider a graph which represents 
a map of highways between major US cities. Each graph edge, representing 
a highway, might have a _weight_ that represents the number of miles 
between those cities using that highway. This data structure can be 
used to calculate the shortest route between two different cities, 
for example. For more information about this subclass of problems, 
we recommend reading about 
[Dijkstra's Algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm).

## Problems

### 1. Unique Binary Search Trees

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

### 2. Six Degrees of Kevin Bacon

Source: Lizzy Presland

#### Scenario

The term "Six Degrees of Separation" describes how any two people on 
Earth can be associated by no more than six intermediary people. These 
relationships can easily be represented in a graph structure. A 
popular reimagining of this problem is 
["Six Degrees of Kevin Bacon"](https://en.wikipedia.org/wiki/Six_Degrees_of_Kevin_Bacon), 
which we will explore in this problem.

#### Part I

In the graph given below, use the weighted edges to determine which 
individuals which are within six degrees of Kevin Bacon. 

![six degrees graph](./kevin_bacon/kevin_bacon.png)

#### Part II

Write code (or pseudocode) to determine which nodes in a given graph 
are within 6 degrees of Kevin Bacon, if any.

##### Function Signature

The C++ function for a member of the `Graph` class could be defined as follows:

```c++
map<Node*, int>* Graph::sixDegreesOfBacon();
```

For convenience, the header file of the `Graph` and `Node` classes 
are listed below with all essential methods for this problem.

```c++
using namespace std;

class Graph {
    public:
        Graph();
        ~Graph();
        bool connect(string, string, int);
    private:
        set<Node*> nodes;
};

class Node {
    public:
        Node(string name);
        ~Node();
        map<Node*, int>* getEdges();
        string getName();
        bool addEdge(Node*, int);
    private:
        map<Node*, int>* edges;
        string name;
};
```

## Solutions

### 1. Unique Binary Search Trees

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

### 2. Six Degrees of Kevin Bacon

Source: Lizzy Presland

#### Solution

The solution for this problem is a specialized version of Dijkstra's 
algorithm. The use of tenets of the algorithm is important because 
multiple different paths may lead to the same node, and we want to 
progress if a smaller path allows more subsequent nodes to be found. 
Furthermore, we can customize Dijkstra's algorithm so that we do not 
proceed further into the graph if our weightsum is exceeded.

A pseudocode algorithm for the implementation might look something like this:

```
// edge case
check the graph's set of nodes for "Kevin Bacon"; return null if absent
// graph search setup
create:
    a map of objects which contain a valid node and the weight sum to access that node from Kevin Bacon
    an additional map that maps the current node to the previous node in lowest-sum traversal
    a set of nodes that have already been visited
    a queue (priority queue) of nodes to check next, containing the node and the neighbor's weight
add all of Kevin Bacon's neighbors to the queue, if the weight is less than 6
// use Dijkstra's algorithm to traverse the graph
while the queue is not empty:
    if the node has already been visited, do not proceed with this node (prevents backtracking)
    get weightsum of current path (predecessor weight + queue item's weight)
    if weightsum > 6; do not proceed with current item
    else:
        if the queue item is not in the weightsum map:
            add the queue item to the weightsum and previous-node maps
        otherwise (the queue item is in the weightsum map):
            if the current path results in smaller weight than what is already recorded:
                update the weightsum and previous maps with the current values
        add all neighbors of current queue item to queue, if not previously visited
        mark the current node as visited
return the weightsum map
```

The C++ implementation is as follows:

```c++
map<Node*, int>* Graph::sixDegrees() {
    // create an iterator for the method
    set<Node*>::iterator it;
    // get the pointer to start node (Kevin Bacon)
    Node* currNode = nullptr;
    for (it = vertices->begin(); it != vertices->end(); ++it) {
        if ((*it)->getName() == "Kevin Bacon") currNode = *it;
    }
    // return immediately if Kevin Bacon does not exist in graph
    if (currNode == nullptr) return nullptr;
    // create a priority queue for handling paths in order
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>,
                        greater<pair<int, Node*>>> pq;
    // create sets for managing visited and unvisited vertices
    set<Node*> explored;
    map<Node*, Node*> previous;
    map<Node*, int>* weights = new map<Node*, int>();
    // add the outbound neighbors of currLabel to the queue, and reset
    // the weights for those items
    map<Node*, int>::iterator mit;
    map<Node*, int>* currEdges = currNode->getEdges();
    for (mit = currEdges->begin(); mit != currEdges->end(); ++mit) {
        if (mit->second <= 6) {
            pq.push(make_pair(mit->second, mit->first));
            (*weights)[mit->first] = mit->second;
            previous[mit->first] = currNode;
        }
    }
    // add currLabel to explored set
    explored.insert(currNode);
    // here comes the fun part
    while (!pq.empty()) {
        // Basic Steps:
        // iterate through currLabel's neighbors (already in queue).
        // mark as visited, assign currLabel to currently inspected vertex.
        // for each neighbor of current vertex, calculate weight diffs
        // and reassign as needed.
        // then, iterate through current neighbor's next neighbors.
        // if next neighbors have not already been explored, push
        // them to the priority queue.
        pair<int, Node*> currVertex = pq.top();
        currNode = currVertex.second;
        pq.pop();
        explored.insert(currNode);
        // inspect neighbors for weight differentials and
        // queue neighbors for further inspection
        currEdges = currNode->getEdges();
        for (mit = currEdges->begin(); mit != currEdges->end(); ++mit) {
            // don't backtrack if neighbor is already explored
            if (explored.count(mit->first) != 0) continue;
            // for each neighbor, check whether current weight val of
            // startLabel->neighbor is g.t. current weight val of
            // currNode + neighbor.weight; if so, reassign weight val.
            if (weights->count(mit->first) == 0 && (*weights)[currNode] + mit->second <= 6) {
                (*weights)[mit->first] = (*weights)[currNode] + mit->second;
                previous[mit->first] = currNode;
            } else if (weights->count(mit->first) > 0 
                            && (*weights)[mit->first] > (*weights)[currNode] + mit->second
                            && (*weights)[currNode] + mit->second <= 6) {
                (*weights)[mit->first] = (*weights)[currNode] + mit->second;
                previous[mit->first] = currNode;
            }
            if (explored.count(mit->first) == 0) {
                // add the node to the priority queue to be explored
                pq.push(make_pair(mit->second, mit->first));
            }
        }
    }
    return weights;
}
```

#### Testing The Solutions OR Driver For Solution

The C++ implementation for this problem is available at 
`Spring-2019/trees_graphs/kevin_bacon`, and consists of two classes 
and a driver.

To execute and see the output, run the following in a terminal:

```console
$ cd Spring-2019/trees_graphs/kevin_bacon
$ g++ -o test *.cpp
$ ./test
G1:
Name: Marilyn Manson    Degrees: 5
Name: Fred Flinstone    Degrees: 6
G2:
Name: Christian Bale        Degrees: 5
Name: Helena Bonham-Carter  Degrees: 2
Name: Bruce Wayne           Degrees: 6
Name: Batman                Degrees: 6
```

