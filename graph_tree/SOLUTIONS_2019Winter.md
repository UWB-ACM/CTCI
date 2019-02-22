## Graphs And Trees Problems

Solutions for Graphs & Trees session on February 22, 2019.

### 1. Validate BST

##### PROBLEM: 
Implement a function to check if a binary tree is a binary search tree.

Definition: 
```java
class Node {
  public int data;
  public Node left;
  public Node right;
}
```

Reference: CTCI 6th Ed. Problem 4.5

##### Solution:

```C++
/////////////  C++ Solution /////////////
bool validate() {
    return validateHelper(root, nullptr, nullptr);
}

// the actual interview question's solution, implemented as a class method
bool validateHelper(Node* currPtr, Node* minVal, Node* maxVal) {
    // base case: return true if current node is nullptr
    if (currPtr == nullptr)
        return true;
    // for the given partition points (min/max values possible),
    // ensure that the current node's data lies within the permissible range
    if (minVal != nullptr && currPtr->data < minVal->data)
        return false;
    if (maxVal != nullptr && currPtr->data >= maxVal->data)
        return false;
    bool checkLhs = validateHelper(currPtr->left, minVal, currPtr);
    bool checkRhs = validateHelper(currPtr->right, currPtr, maxVal);
    if (!checkLhs || !checkRhs)
        return false;
    return true;
}
```

### 2. Route Between Nodes

##### PROBLEM:

Given a directed graph, implement a function that determines whether there is a route between two nodes.

Definitions:

```java
class Graph {
  Node[] nodes;
  public Node[] getNodes() { return nodes; }
}

class Node {
  Int data;
  Node[] adjacent;
  public Node[] getAdjacent() { return adjacent; }
}
```

Reference: CTCI 6th Ed. Problem 4.1

##### Solution:

```java
/////////////  Java Solution /////////////
public boolean hasPath(Graph g, Node start, Node end) {
        
  boolean[] hasVisited = new boolean[g.getNodes().length];
  Queue<Node> q = new LinkedList<Node>();
  q.add(start);

  while(!q.isEmpty()) {
    Node cur = q.remove();
    if (cur == null)
      break;
            
    for(Node adj : cur.getAdjacent()) {
      if(!hasVisited[adj.getData()]) {
        if(adj == end)
          return true;
        else
          q.add(adj);
      }
      hasVisited[cur.getData()] = true;
    }
  }
  return false;
}
```

**NOTE:** this solution assumes that there are no two unique vertices with duplicate labels in the graph's structure; if duplicate values are expected or should be considered, then a data structure should be chosen to replace the `boolean[] hasVisited` variable.

### 3. Check Subtree

##### PROBLEM:

T1 and T2 are two very large binary trees, with T1 much bigger than T2. Create an algorithm to determine if T2 is a subtree of T1.
A Tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to to T2. That is, if you cut off the tree at node n, the two trees would be identical.

Definition: 
```java
class Node {
  public int data;
  public Node left;
  public Node right;
}
```

Reference: CTCI 6th Ed. Problem 4.10

##### Solution:

```C++
// public method
bool isSubtree(BinTree& t2) {
    vector<Node*> subTrees = this->find(t2.root->data);
    bool isSubtree = false;
    for (typename vector<Node*>::iterator it = subTrees.begin(); it != subTrees.end(); ++it) {
        isSubtree = t2.identical(*it);
        if (isSubtree)
            break;
    }
    return isSubtree;
}

// locate nodes in the tree which match the provided data
// helper method
vector<Node*> find(T data) {
    vector<Node*> items;
    findHelper(data, items, root);
    return items;
}

// determine whether two subtrees are identical
// helper method
bool identical(Node* ptr) {
    return identicalHelper(ptr, root);
}

// a helper method that searches the tree for all nodes that
// contain the supplied data
// helper method
void findHelper(T searchItem, vector<Node*>& items, Node* rootPtr) {
    if (rootPtr == nullptr)
        return;
    if (rootPtr->data == searchItem)
        items.push_back(rootPtr);
    findHelper(searchItem, items, rootPtr->left);
    findHelper(searchItem, items, rootPtr->right);
}

// helper method
bool identicalHelper(Node* ptr1, Node* ptr2) {
    if (ptr1 == nullptr && ptr2 == nullptr)
        return true;
    if (ptr1 == nullptr && ptr2 != nullptr)
        return false;
    if (ptr1 != nullptr && ptr2 == nullptr)
        return false;
    return identicalHelper(ptr1->left, ptr2->left) && (ptr1->data == ptr2->data) && identicalHelper(ptr1->right, ptr2->right);
}
```

