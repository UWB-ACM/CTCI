#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"

class Graph
{
public:
    Graph(){};
    bool addPhone(std::map<std::string, std::vector<std::string>> PhoneCalls);
    Vertex *findThePhone(std::string FoundPhoneNum);

private:
    std::map<std::string, Vertex*> PhoneNumbers;
};

#endif