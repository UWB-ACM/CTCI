#include "Vertex.h"

bool Vertex::connect(std::map<std::string, Vertex *> &Phones, std::vector<std::string> &CallsMade)
{
    for (auto I : CallsMade)
    {
        auto It = Phones.find(I);
        if (It == Phones.end()) // if the phone num is not already there, add it
        {
            auto Phone = new Vertex(I); // add function ??
            Phones.insert({I, Phone});
            It->second = Phone;
        }

        auto Temp = new Edge(It->second);
        TheCallsMade.push_back(Temp);
    }
    return true;
}

void Vertex::printCallsMade()
{
    std::cout << "[" << Number << "::";
    for (auto I : TheCallsMade)
    {
        std::cout << "(" << I->Called->Number << "), "; 
    }
    std::cout << "]" << std::endl;
}
