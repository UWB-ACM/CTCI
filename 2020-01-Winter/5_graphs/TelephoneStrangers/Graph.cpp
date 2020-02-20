#include "Graph.h"

bool Graph::addPhone(
    std::map<std::string, std::vector<std::string>> PhoneCalls) {
  for (auto I : PhoneCalls) {
    auto Phone = new Vertex(I.first); // add function ??
    PhoneNumbers.insert({I.first, Phone});
  }
  for (auto I : PhoneCalls) // ? make more efficient
  {
    auto Temp = findThePhone(I.first);
    Temp->connect(PhoneNumbers, I.second);
  }
  return true;
}

Vertex *Graph::findThePhone(std::string FoundPhoneNum) {
  auto It = PhoneNumbers.find(FoundPhoneNum);
  return It->second;
}

void Graph::printPhoneNumbers() {
  for (auto I : PhoneNumbers) {
    I.second->printCallsMade();
  }
}

std::map<std::string, Vertex *> Graph::returnPhoneNumbers() {
  return PhoneNumbers;
};
