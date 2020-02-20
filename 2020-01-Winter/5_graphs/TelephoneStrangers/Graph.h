#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"

class Graph
{
public:
    Graph(){};
    bool addPhone(std::map<std::string, std::vector<std::string>> PhoneCalls);
    Vertex *findThePhone(std::string FoundPhoneNum);
    void printPhoneNumbers();
    std::map<std::string, Vertex*> returnPhoneNumbers();

private:
    std::map<std::string, Vertex*> PhoneNumbers;
};

#endif