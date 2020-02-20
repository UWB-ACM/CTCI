#ifndef VERTEX_H
#define VERTEX_H

#include "Edge.h"
#include <vector>
#include <iostream>
#include <map>


class Vertex
{
    friend class Edge;
public:
    Vertex(std::string PhoneNum) : Number(PhoneNum){};
    bool connect(std::map<std::string, Vertex*> &Phones, std::vector<std::string> &CallsMade);
    void printCallsMade();
    std::vector<Edge *> returnCallsMade() {return TheCallsMade;};
    std::string returnNumber() {return Number;};

private:
    std::string Number;
    std::vector<Edge *> TheCallsMade;
};

#endif