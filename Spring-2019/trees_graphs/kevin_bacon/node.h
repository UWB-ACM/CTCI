#include <string>
#include <map>

using namespace std;

#ifndef NODE_H__
#define NODE_H__

class Node {
    private:
        string name;
        map<Node*, int>* edges;
    public:
        Node(string name);
        ~Node();
        bool addEdge(Node*, int);
        map<Node*, int>* getEdges();
        string getName();
};

#endif      // NODE_H__
