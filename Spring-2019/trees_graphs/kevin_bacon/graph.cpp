#include "node.h"
#include "graph.h"
#include <set>
#include <map>
#include <string>
#include <queue>        // priority_queue
#include <utility>      // pair
#include <functional>   // greater (for pairs in pq)

Graph::Graph() {
    vertices = new set<Node*>();
}

Graph::~Graph() {
    for (set<Node*>::iterator it = vertices->begin(); it != vertices->end(); ++it) {
        delete *it;
    }
    delete vertices;
}

bool Graph::connect(string from, string to, int weight) {
    Node* first = nullptr;
    Node* second = nullptr;
    for (set<Node*>::iterator it = vertices->begin(); it != vertices->end(); ++it) {
        if ((*it)->getName() == from) first = *it;
        if ((*it)->getName() == to) second = *it;
    }
    if (first == nullptr) {
        first = new Node(from);
        vertices->insert(first);
    }
    if (second == nullptr) {
        second = new Node(to);
        vertices->insert(second);
    }
    map<Node*, int>* firstEdges = first->getEdges();
    if (firstEdges->count(second) != 0) return false;
    first->addEdge(second, weight);
    second->addEdge(first, weight);
    return true;
}

set<Node*>* Graph::sixDegrees() {
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
                        less<pair<int, Node*>>> pq;
    // create sets for managing visited and unvisited vertices
    set<Node*> explored;
    map<Node*, int> weights;
    map<Node*, Node*> previous;
    // add the outbound neighbors of currLabel to the queue, and reset
    // the weights for those items
    map<Node*, int>::iterator mit;
    map<Node*, int>* currEdges = currNode->getEdges();
    for (mit = currEdges->begin(); mit != currEdges->end(); ++mit) {
        pq.push(make_pair(mit->second, mit->first));
        weights[mit->first] = mit->second;
        previous[mit->first] = currNode;
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
            // for each neighbor, check whether current weight val of
            // startLabel->neighbor is g.t. current weight val of
            // currNode + neighbor.weight; if so, reassign weight val.
            if (weights.count(mit->first) == 0 && mit->second <= 6) {
                weights[mit->first] = weights[currNode] + mit->second;
                previous[mit->first] = currNode;
            } else if (weights[mit->first] > weights[currNode] + mit->second
                            && weights[currNode] + mit->second <= 6) {
                weights[mit->first] = weights[currNode] + mit->second;
                previous[mit->first] = currNode;
            }
            if (explored.count(mit->first) == 0) {
                // add the node to the priority queue to be explored
                pq.push(make_pair(mit->second, mit->first));
            }
        }
    }
    // assemble a set of the nodes contained in weights
    set<Node*>* result = new set<Node*>();
    for (mit = weights.begin(); mit != weights.end(); ++mit)
        if (mit->first->getName() != "Kevin Bacon") result->insert(mit->first);
    return result;
}
