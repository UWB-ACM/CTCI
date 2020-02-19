#include <iostream>
#include <map>
#include <vector>
#include <set>
class Edge
{
public:
    Edge(Vertex *BeingCalled) : Called(BeingCalled){};

private:
    Vertex *Called;
};

class Vertex
{
public:
    Vertex(std::string PhoneNum) : Number(PhoneNum){};
    bool connect(std::map<std::string, Vertex*> Phones, std::vector<std::string> &CallsMade);

private:
    std::string Number;
    Edge *CallsMade{nullptr};
};

class Graph
{
public:
    Graph(){};
    bool addPhone(std::map<std::string, std::vector<std::string>> PhoneCalls);
    bool Graph::add();
    Vertex *findThePhone(std::string FoundPhoneNum);

private:
    std::map<std::string, Vertex*> PhoneNumbers;
};

bool Graph::addPhone(std::map<std::string, std::vector<std::string>> PhoneCalls)
{
    for (auto I : PhoneCalls)
    {
        auto Phone = new Vertex(I.first); // add function ??
        PhoneNumbers.insert({I.first, Phone});
    }
    for (auto I : PhoneNumbers)
    {
        
    }
}

Vertex *Graph::findThePhone(std::string FoundPhoneNum)
{
    auto It = PhoneNumbers.find(FoundPhoneNum);
    return It->second;
}

bool Vertex::connect(std::map<std::string, Vertex*> Phones, std::vector<std::string> &CallsMade)
{
    for (auto I : CallsMade)
    {
        
    }
}


void FindStrangers(std::map<std::string, std::vector<std::string>> PhoneCalls)
{
}

void test()
{
}

int main()
{
}