#include "graph.h"
#include "node.h"
#include <set>
#include <string>

using namespace std;

Graph* createGraph1() {
    Graph* g1 = new Graph();
    g1->connect("Kevin Bacon", "Marilyn Manson", 5);
    g1->connect("Marilyn Manson", "Iggy Pop", 2);
    g1->connect("Marilyn Manson", "Fred Flinstone", 1);
    return g1;
}

int main() {
    Graph* g1 = createGraph1();
    set<Node*>* g1results = g1->sixDegrees();
    // TODO: print results?
    delete g1;
    return 0;
}
