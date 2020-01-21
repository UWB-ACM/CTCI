#include "Node.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <unordered_set>

using namespace std;

// Forward Declarations
void TestAllBuffer();
void TestAllNoBuffer();

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

void RemoveDuplicatesWithoutBuffer(Node *Start) {
  if (Start == nullptr || Start->GetNext() == nullptr) {
    return;
  }

  Node *Curr = Start;
  Node *Check = nullptr; // Used to iterate over the list
  Node *Prev = nullptr;

  while (Curr != nullptr) {

    //    bool duplicate = false;
    Check = Start; // Start at second Node of list
    Prev = Check;

    while (Check != nullptr) {

      if (Check->GetValue() == Curr->GetValue() && Check != Curr) {
        Prev->SetNext(Check->GetNext());
        delete Check;
        //        delete Curr;
        //        Curr = Prev->GetNext();
      }
      Prev = Check;
      Check = Check->GetNext();
    }

    //    Prev = Curr;
    Curr = Curr->GetNext();
  }
}

int main() {
  cout << "Start of Problem 3: Linked List Duplicate\n" << endl;

  cout << "Starting Tests Using Buffer" << endl;
  TestAllBuffer();
  cout << "Buffer Solution Successfully Passed! You're ready for round 2\n"
       << endl;

  cout << "Starting Tests WITHOUT Using Buffer" << endl;
  TestAllNoBuffer();
  cout << "NO Buffer Solution Successfully Passed! You're hired!" << endl;

  cout << "\nEnd of Problem 3: Linked List Duplicate" << endl;
  return 0;
}

/*
 * Tests
 */

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

void Test1Buffer() {
  Node *Head = new Node(1, nullptr);
  Node *Prev = Head;
  // Generate Nodes
  for (int i = 0; i < 2; ++i) {
    Node *New_Node = new Node(5);
    Prev->SetNext(New_Node); // Add to LinkedList
    Prev = Prev->GetNext();  // Move prev forward
  }
  RemoveDuplicatesWithBuffer(Head);
  assert("[<1> <5>]" == displayAll(Head) && "Expected: [<1> <5>]");

  clearList(Head);
}

void Test1NoBuffer() {
  Node *Head = new Node(1, nullptr);
  Node *Prev = Head;
  // Generate Nodes
  for (int i = 0; i < 2; ++i) {
    Node *New_Node = new Node(5);
    Prev->SetNext(New_Node); // Add to LinkedList
    Prev = Prev->GetNext();  // Move prev forward
  }

  RemoveDuplicatesWithoutBuffer(Head);

  assert("[<1> <5>]" == displayAll(Head) && "Expected: [<1> <5>]");

  clearList(Head);
}

void Test2Buffer() {
  Node *Head = new Node(1, nullptr);

  RemoveDuplicatesWithBuffer(Head);

  assert("[<1>]" == displayAll(Head) && "Expected: [<1>]");

  clearList(Head);
}

void Test2NoBuffer() {
  Node *Head = new Node(1, nullptr);

  RemoveDuplicatesWithoutBuffer(Head);

  assert("[<1>]" == displayAll(Head) && "Expected: [<1>]");

  clearList(Head);
}

void Test3Buffer() {
  Node *Head = new Node(1, nullptr);
  Node *Prev = Head;
  // Generate Nodes
  for (int i = 0; i < 20; ++i) {
    Prev->SetNext(new Node(i)); // Add to LinkedList
    Prev = Prev->GetNext();     // Move prev forward
  }

  for (int i = 20; i < 0; ++i) {
    //    Node *New_Node = new Node(i);
    Prev->SetNext(new Node(i)); // Add to LinkedList
    Prev = Prev->GetNext();     // Move prev forward
  }

  RemoveDuplicatesWithBuffer(Head);

  int total = 0;
  Prev = Head;
  while (Prev != nullptr) {
    Prev = Prev->GetNext();
    ++total;
  }

  assert("[<1> <0> <2> <3> <4> <5> <6> <7> <8> <9> <10> <11> <12> <13> <14> "
         "<15> <16> <17> <18> <19>]" == displayAll(Head) &&
         "Failed Test 3 with Buffer");
  assert(total == 20);

  clearList(Head);
}

void Test3NoBuffer() {
  Node *Head = new Node(1, nullptr);
  Node *Prev = Head;
  // Generate Nodes
  for (int i = 0; i < 20; ++i) {
    Prev->SetNext(new Node(i)); // Add to LinkedList
    Prev = Prev->GetNext();     // Move prev forward
  }

  for (int i = 20; i < 0; ++i) {
    //    Node *New_Node = new Node(i);
    Prev->SetNext(new Node(i)); // Add to LinkedList
    Prev = Prev->GetNext();     // Move prev forward
  }

  RemoveDuplicatesWithoutBuffer(Head);

  int total = 0;
  Prev = Head;
  while (Prev != nullptr) {
    Prev = Prev->GetNext();
    ++total;
  }

  assert("[<1> <0> <2> <3> <4> <5> <6> <7> <8> <9> <10> <11> <12> <13> <14> "
         "<15> <16> <17> <18> <19>]" == displayAll(Head) &&
         "Failed Test 3 without Buffer");
  assert(total == 20);

  clearList(Head);
}

void Test4Buffer() {
  Node *Head = new Node(1, nullptr);
  Node *Prev = Head;
  // Generate Nodes
  for (int i = 0; i < 1; ++i) {
    Prev->SetNext(new Node(i)); // Add to LinkedList
    Prev = Prev->GetNext();     // Move prev forward
  }

  RemoveDuplicatesWithBuffer(Head);

  assert("[<1> <0>]" == displayAll(Head) && "Failed Test 4 with Buffer");

  clearList(Head);
}

void Test4NoBuffer() {
  Node *Head = new Node(1, nullptr);
  Node *Prev = Head;
  // Generate Nodes
  for (int i = 0; i < 1; ++i) {
    Prev->SetNext(new Node(i)); // Add to LinkedList
    Prev = Prev->GetNext();     // Move prev forward
  }

  RemoveDuplicatesWithoutBuffer(Head);

  assert("[<1> <0>]" == displayAll(Head) && "Failed Test 4 without Buffer");

  clearList(Head);
}

void TestAllBuffer() {
  Test1Buffer();
  Test2Buffer();
  Test3Buffer();
  Test4Buffer();
}

void TestAllNoBuffer() {
  Test1NoBuffer();
  Test2NoBuffer();
  Test3NoBuffer();
  Test4NoBuffer();
}
