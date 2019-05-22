#include "node.h"
#include "graph.h"
#include <set>
#include <map>
#include <string>

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
    // return immediately if Kevin Bacon does not exist in graph
    if (vertices->count("Kevin Bacon") == 0) {
        return nullptr;
    }
    // create an iterator for the method
    set<Node*>::iterator it;
    // get the pointer to start node (Kevin Bacon)
    Node* currNode = nullptr;
    for (it = vertices->begin(); it != vertices->end(); ++it) {
        if ((*it)->getName() == "Kevin Bacon") currNode = *it;
    }
    // TODO: fix everything below this point
    /*
    // create a priority queue for handling paths in order
    priority_queue<pair<int, string>, vector<pair<int, string>>,
                        greater<pair<int, string>>> pq;
    // create sets for managing visited and unvisited vertices
    set<string> explored;
    // create a temp string to track which vertex is being inspected
    string currLabel = startLabel;
    // add the outbound neighbors of currLabel to the queue, and reset
    // the weights for those items
    list<pair<string, int>>& edgeList = edges->at(currLabel);
    for (list<pair<string, int>>::iterator it = edgeList.begin();
                        it != edgeList.end(); ++it) {
        pq.push(make_pair((*it).second, (*it).first));
        weights[(*it).first] = (*it).second;
        previous[(*it).first] = currLabel;
    }
    // add currLabel to explored set
    explored.insert(currLabel);
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
        pair<int, string> currVertex = pq.top();
        currLabel = currVertex.second;
        pq.pop();
        explored.insert(currLabel);
        // inspect neighbors for weight differentials and
        // queue neighbors for further inspection
        list<pair<string, int>>& nextEdgeList = edges->at(currLabel);
        for (list<pair<string, int>>::iterator it = nextEdgeList.begin();
                        it != nextEdgeList.end(); ++it) {
            // for each neighbor, check whether current weight val of
            // startLabel->neighbor is g.t. current weight val of
            // currLabel + neighbor.weight; if so, reassign weight val.
            if (weights.count((*it).first) == 0) {
                weights[(*it).first] = weights[currLabel] + (*it).second;
                previous[(*it).first] = currLabel;
            } else if (weights[(*it).first] >
                                weights[currLabel] + (*it).second) {
                weights[(*it).first] = weights[currLabel] + (*it).second;
                previous[(*it).first] = currLabel;
            }
            if (explored.count((*it).first) == 0) {
                // add the node to the priority queue to be explored
                pq.push(make_pair((*it).second, (*it).first));
            }
        }
    }
    // if a cycle occurs in the graph, then the originating node will
    // be added with cyclical weight & previous node entries; these
    // should be removed.
    if (weights.count(startLabel) != 0) {
        weights.erase(startLabel);
        previous.erase(startLabel);
    }
    */
    return nullptr;
}
