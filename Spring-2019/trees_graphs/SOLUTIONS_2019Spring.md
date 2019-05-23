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

### 3. Six Degrees of Kevin Bacon

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
    a queue of nodes to check next, containing the node and the neighbor's weight
add all of Kevin Bacon's neighbors to the queue, if the weight is less than 6
// use Dijkstra's algorithm to traverse the graph
while the queue is not empty:
    if the node has already been visited, do not proceed with this node (prevents backtracking)
    get weightsum of current path (predecessor weight + queue item's weight)
    if weightsum > 6; do not proceed with current item
    else:
        if the queue item is not in the weightsum map:
            add the queue item to the weightsum and previous-node maps
        otherwise (the queue item is in the set):
            if the current path results in smaller weight than what is already recorded:
                update the weightsum and previous maps with the current values
       add all neighbors of current queue item to queue
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
Name: lennyface     Degrees: 4
Name: crabperson    Degrees: 2
Name: reachthis     Degrees: 6
Name: thisalso      Degrees: 6
```

