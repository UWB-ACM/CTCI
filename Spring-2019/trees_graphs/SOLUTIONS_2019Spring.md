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

### 2. PROBLEM 2 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

### 3. Six Degrees of Kevin Bacon

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

Write code (or pseudocode) to determine which nodes, if any, are within 6 degrees of 
Kevin Bacon.

##### Function Signature

The C++ function would be defined as follows:

```c++
vector<Node*> Graph::sixDegreesOfBacon();
```

For convenience, the header file of the `Graph` and `Node` classes 
are listed below with all essential methods for this problem.

```c++
using namespace std;

class Graph {
    public:
        Graph();
        ~Graph();
        Node* getNode(string nodeName);
    private:
        set<Node*> nodes;
};

class Node {
    public:
        Node(string name);
        ~Node();
        vector<pair<Node*, int>*>* getEdges();
        string getName();
    private:
        vector<pair<Node*, int>*>* edges;
        string name;
};
```

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


