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

void printStrangers(std::vector<std::pair<std::string, std::string>> res) {
    std::cout << "Stranger pairs are: ";
    std::vector<std::pair<std::string, std::string>>::iterator it;
    for (it = res.begin(); it != res.end(); ++it) {
        std::cout << "(" << (*it).first << ", " << (*it).second << ") ";
    }
    std::cout << std::endl;
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
    std::cout << "Test 1:" << std::endl;
    G1->printPhoneNumbers();
    std::vector<std::pair<std::string, std::string>> res = FindStrangers(G1);
    // print results
    printStrangers(res);
}

void test2()
{
    // ? Test the second case in problem
    auto G1 = new Graph();
    std::map<std::string, std::vector<std::string>> CallHistory;
    std::vector<std::string> VectList = {};
    VectList = {"2", "3", "4"};
    CallHistory.insert({"1", VectList});
    VectList = {"1", "4"};
    CallHistory.insert({"2", VectList});
    VectList = {"1"};
    CallHistory.insert({"3", VectList});
    VectList = {"1", "2"};
    CallHistory.insert({"4", VectList});
    G1->addPhone(CallHistory);
    std::cout << "\nTest 2:" << std::endl;
    G1->printPhoneNumbers();
    std::vector<std::pair<std::string, std::string>> res = FindStrangers(G1);
    // print results
    printStrangers(res);
}

void test3() {
    auto G1 = new Graph();
    std::map<std::string, std::vector<std::string>> CallHistory;
    std::vector<std::string> VectList = {};
    VectList = {"b", "b", "b", "b", "c"};
    CallHistory.insert({"a", VectList});
    VectList = {"a", "a", "c", "a", "a"};
    CallHistory.insert({"b", VectList});
    VectList = {"b", "a"};
    CallHistory.insert({"c", VectList});
    G1->addPhone(CallHistory);
    std::cout << "\nTest 3:" << std::endl;
    G1->printPhoneNumbers();
    std::vector<std::pair<std::string, std::string>> res = FindStrangers(G1);
    // print results
    printStrangers(res);
}

int main()
{
    test1();
    test2();
    test3();
    std::cout << "Done!" << std::endl;
    return 0;
}
