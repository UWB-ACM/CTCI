#include "node.h"
#include <string>
#include <map>

using namespace std;

Node::Node(string name) {
    this->name = name;
    edges = new map<Node*, int>;
}

Node::~Node() {
    delete edges;
}

bool Node::addEdge(Node* neighbor, int weight) {
    if (edges->count(neighbor) != 0) return false;
    (*edges)[neighbor] = weight;
    return true;
}

map<Node*, int>* Node::getEdges() {
    return edges;
}

string Node::getName() {
    return name;
}
