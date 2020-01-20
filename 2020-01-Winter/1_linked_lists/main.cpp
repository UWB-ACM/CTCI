#include <cassert>
#include <iostream>
#include <list>
#include <sstream>
#include <unordered_set>

using namespace std;

class Node {
public:
  int Node_Count = 0;

  explicit Node(int Value = 0, Node *Next = nullptr) {
    this->Value = Value;
    this->Next = Next;
  }

  void SetValue(int V) { this->Value = V; }

  void SetNext(Node *N) { this->Next = N; }

  int GetValue() { return this->Value; }

  Node *&GetNext() { return this->Next; }

private:
  int Value;
  Node *Next;
};

void RemoveDuplicatesWithBuffer(Node *Start) {
  if (Start == nullptr || Start->GetNext() == nullptr) {
    return;
  }

  unordered_set<int> set;

  Node *Curr = Start;
  Node *Prev = nullptr;

  while (Curr != nullptr) {
    // Doesn't exist
    if (set.find(Curr->GetValue()) == set.end()) {

      set.insert(Curr->GetValue());
      Prev = Curr;
      Curr = Curr->GetNext();

    } else { // Exists

      Prev->SetNext(Curr->GetNext());
      delete Curr;
      Curr = Prev->GetNext();
    }
  }
}

// Displays all starting at the given Node
string displayAll(Node *Start) {

  if (Start == nullptr) {
    return "[]";
  }

  ostringstream out;

  Node *Curr = Start;

  out << "[";
  out << "<" << Curr->GetValue() << ">";

  while (Curr->GetNext() != nullptr) {
    Curr = Curr->GetNext();
    out << " <" << Curr->GetValue() << ">";
  }
  out << "]";

  return out.str();
}

void clearList(Node *Start) {
  // Delete old list
  Node *Curr = Start;
  Node *Prev = nullptr;
  while (Curr != nullptr) {
    Prev = Curr;
    Curr = Curr->GetNext();
    delete Prev;
  }
}

void Test1() {
  Node *Head = new Node(1, nullptr);
  Node *Prev = Head;
  // Generate Nodes
  for (int i = 0; i < 20; ++i) {
    Node *New_Node = new Node(5);
    Prev->SetNext(New_Node); // Add to LinkedList
    Prev = Prev->GetNext();  // Move prev forward
  }
  RemoveDuplicatesWithBuffer(Head);

  assert("[<1> <5>]" == displayAll(Head) && "Expected: [<1> <5>]");

  clearList(Head);
};

void Test2() {
  Node *Head = new Node(1, nullptr);

  RemoveDuplicatesWithBuffer(Head);

  assert("[<1>]" == displayAll(Head) && "Expected: [<1>]");

  clearList(Head);
};

void Test3() {
  Node *Head = new Node(1, nullptr);
  Node *Prev = Head;
  // Generate Nodes
  for (int i = 0; i < 20; ++i) {
    Prev->SetNext(new Node(5)); // Add to LinkedList
    Prev = Prev->GetNext();     // Move prev forward
  }


  //  for (int i = 20; i < 0; ++i) {
  //    Node *New_Node = new Node(i);
  //    Prev->SetNext(New_Node); // Add to LinkedList
  //    Prev = Prev->GetNext();  // Move prev forward
  //  }

  //  RemoveDuplicatesWithBuffer(Head);

  //  cout << Head->Node_Count << endl;
  //  assert(Head->Node_Count == 30);

  //  clearList(Head);
};

int main() {
  cout << "Start of Problem 3: Linked List Duplicate" << endl;

  Test1();
  Test2();
  Test3();

  cout << "End of Problem 3: Linked List Duplicate" << endl;
  return 0;
}
