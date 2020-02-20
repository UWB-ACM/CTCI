#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <set>
#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"

std::pair<std::string, std::string> Helper(std::set<Vertex *> InCallHistory, Vertex *Curr)
{
    for (auto I : Curr->returnCallsMade())
    {
        auto Temp = InCallHistory.find(I->returnCalled()); 
        if(Temp == InCallHistory.end())
        {
            continue; // update this
        }

        InCallHistory.erase(I->returnCalled());
    }

    std::vector<Vertex *> Temp;
    for (auto I : InCallHistory)
    {
        Temp.push_back(I);
    }
    if (Temp.size() > 1) {
        auto Foo = std::make_pair(Temp[0]->returnNumber(), Temp[1]->returnNumber());
        return Foo;
    }
    return std::make_pair("", "");
}

std::vector<std::pair<std::string, std::string>>
FindStrangers(Graph *PhoneHistory)
{
    std::vector<std::pair<std::string, std::string>> StrangerPairs;
    std::set<Vertex *> PrevCallStack;
    auto Numbs = PhoneHistory->returnPhoneNumbers();

    for (auto I : Numbs)
    {
        PrevCallStack.insert(I.second);
    }

    for (auto I : Numbs)
    {
        if(I.second->returnCallsMade().empty())
        {
            continue;
        }
        StrangerPairs.push_back(Helper(PrevCallStack, I.second));
    }

    return StrangerPairs;
}


void test1()
{
    auto G1 = new Graph();
    std::map<std::string, std::vector<std::string>> CallHistory;
    std::vector<std::string> VectList = {};
    CallHistory.insert({"206", VectList});
    VectList = {"425"};
    CallHistory.insert({"940", VectList});
    VectList = {"940"};
    CallHistory.insert({"425", VectList});
    G1->addPhone(CallHistory);
    FindStrangers(G1);
}

void test2()
{
    // ? Test the second case in problem
}

int main()
{
    test1();
    std::cout << "Done!" << std::endl;
    return 0;
}