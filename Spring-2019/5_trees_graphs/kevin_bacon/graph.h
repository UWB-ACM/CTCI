#include "node.h"
#include <set>
#include <string>

using namespace std;

#ifndef GRAPH_H__
#define GRAPH_H__

class Graph {
    private:
        set<Node*>* vertices;
    public:
        Graph();
        ~Graph();
        bool connect(string, string, int);
        map<Node*, int>* sixDegrees();
};

#endif      // GRAPH_H__
