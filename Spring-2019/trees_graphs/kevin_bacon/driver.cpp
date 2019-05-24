#include "graph.h"
#include "node.h"
#include <set>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

Graph* createGraph1() {
    Graph* g1 = new Graph();
    g1->connect("Kevin Bacon", "Marilyn Manson", 5);
    g1->connect("Marilyn Manson", "Iggy Pop", 2);
    g1->connect("Marilyn Manson", "Fred Flinstone", 1);
    return g1;
}

Graph* createGraph2() {
    Graph* g2 = new Graph();
    g2->connect("Kevin Bacon", "Christian Bale", 14);
    g2->connect("Kevin Bacon", "Helena Bonham-Carter", 2);
    g2->connect("Helena Bonham-Carter", "Christian Bale", 3);
    g2->connect("Christian Bale", "Bruce Wayne", 1);
    g2->connect("Bruce Wayne", "The Joker", 1);
    g2->connect("Bruce Wayne", "Batman", 0);
    g2->connect("The Joker", "Batman", 1);
    return g2;
}

string printGraph(map<Node*, int>* m) {
    stringstream ss;
    for (map<Node*, int>::iterator it = m->begin(); it != m->end(); ++it) {
        ss << "Name: " << it->first->getName();
        ss << "\tDegrees: " << it->second << endl;
    }
    return ss.str();
}

int main() {
    Graph* g1 = createGraph1();
    map<Node*, int>* g1results = g1->sixDegrees();
    cout << "G1:\n" << printGraph(g1results);
    Graph* g2 = createGraph2();
    map<Node*, int>* g2results = g2->sixDegrees();
    cout << "G2:\n" << printGraph(g2results);
    delete g1;
    delete g2;
    delete g1results;
    delete g2results;
    return 0;
}
