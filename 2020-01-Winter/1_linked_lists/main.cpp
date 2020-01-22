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

}

void RemoveDuplicatesWithoutBuffer(Node *Start) {

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
// Do not edit
string displayAll(Node *Start) {

  if (Start == nullptr) {
    return "";
  }

  ostringstream out;

  Node *Curr = Start;

  out << Curr->GetValue() << " -> ";

  while (Curr->GetNext() != nullptr) {
    Curr = Curr->GetNext();
    out << Curr->GetValue() << " -> ";
  }

  return out.str();
}

// Cleans up memory by removing all nodes
// Do not edit
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

void LastTwoRepeating_Buffer() {
  Node *Head = new Node(1, nullptr);
  Node *Prev = Head;
  // Generate Nodes
  for (int i = 0; i < 2; ++i) {
    Node *New_Node = new Node(5);
    Prev->SetNext(New_Node); // Add to LinkedList
    Prev = Prev->GetNext();  // Move prev forward
  }
  RemoveDuplicatesWithBuffer(Head);

  assert("1 -> 5 -> " == displayAll(Head));

  clearList(Head);
}

void LastTwoRepeating_NoBuffer() {
  Node *Head = new Node(1, nullptr);
  Node *Prev = Head;
  // Generate Nodes
  for (int i = 0; i < 2; ++i) {
    Node *New_Node = new Node(5);
    Prev->SetNext(New_Node); // Add to LinkedList
    Prev = Prev->GetNext();  // Move prev forward
  }

  RemoveDuplicatesWithoutBuffer(Head);

  assert("1 -> 5 -> " == displayAll(Head));

  clearList(Head);
}

void SingleElement_Buffer() {
  Node *Head = new Node(1, nullptr);

  RemoveDuplicatesWithBuffer(Head);

  assert("1 -> " == displayAll(Head));

  clearList(Head);
}

void SingleElement_NoBuffer() {
  Node *Head = new Node(1, nullptr);

  RemoveDuplicatesWithoutBuffer(Head);

  assert("1 -> " == displayAll(Head));

  clearList(Head);
}

void LongList_Buffer() {
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

  assert("1 -> 0 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11 -> 12 -> "
         "13 -> 14 -> 15 -> 16 -> 17 -> 18 -> 19 -> " == displayAll(Head));
  assert(total == 20);

  clearList(Head);
}

void LongList_NoBuffer() {
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

  assert("1 -> 0 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11 -> 12 -> "
         "13 -> 14 -> 15 -> 16 -> 17 -> 18 -> 19 -> " == displayAll(Head));
  assert(total == 20);

  clearList(Head);
}

void UniqueShortList_Buffer() {
  Node *Head = new Node(1, nullptr);
  Node *Prev = Head;
  // Generate Nodes
  for (int i = 0; i < 1; ++i) {
    Prev->SetNext(new Node(i)); // Add to LinkedList
    Prev = Prev->GetNext();     // Move prev forward
  }

  RemoveDuplicatesWithBuffer(Head);

  assert("1 -> 0 -> " == displayAll(Head));

  clearList(Head);
}

void UniqueShortList_NoBuffer() {
  Node *Head = new Node(1, nullptr);
  Node *Prev = Head;
  // Generate Nodes
  for (int i = 0; i < 1; ++i) {
    Prev->SetNext(new Node(i)); // Add to LinkedList
    Prev = Prev->GetNext();     // Move prev forward
  }

  RemoveDuplicatesWithoutBuffer(Head);

  assert("1 -> 0 -> " == displayAll(Head));

  clearList(Head);
}

void DuplicateShortList_Buffer() {
  Node *Head = new Node(1, nullptr);
  Node *Prev = Head;
  for (int i = 0; i < 5; ++i) {
    Prev->SetNext(new Node(73)); // Add to LinkedList
    Prev = Prev->GetNext();      // Move prev forward
  }

  RemoveDuplicatesWithBuffer(Head);

  assert("1 -> 73 -> " == displayAll(Head));

  clearList(Head);
}

void DuplicateShortList_NoBuffer() {
  Node *Head = new Node(1, nullptr);
  Node *Prev = Head;
  for (int i = 0; i < 5; ++i) {
    Prev->SetNext(new Node(73)); // Add to LinkedList
    Prev = Prev->GetNext();      // Move prev forward
  }

  RemoveDuplicatesWithoutBuffer(Head);

  assert("1 -> 73 -> " == displayAll(Head));

  clearList(Head);
}

void DuplicateLongList_Buffer() {
  Node *Head = new Node(1, nullptr);
  Node *Prev = Head;
  for (int i = 0; i < 50; ++i) {
    Prev->SetNext(new Node(11)); // Add to LinkedList
    Prev = Prev->GetNext();      // Move prev forward
  }

  RemoveDuplicatesWithBuffer(Head);

  assert("1 -> 11 -> " == displayAll(Head));

  clearList(Head);
}

void DuplicateLongList_NoBuffer() {
  Node *Head = new Node(1, nullptr);
  Node *Prev = Head;
  for (int i = 0; i < 10; ++i) {
    Prev->SetNext(new Node(11)); // Add to LinkedList
    Prev = Prev->GetNext();      // Move prev forward
  }

  RemoveDuplicatesWithoutBuffer(Head);

  assert("1 -> 11 -> " == displayAll(Head));

  clearList(Head);
}

void TestAllBuffer() {
  LastTwoRepeating_Buffer();
  SingleElement_Buffer();
  LongList_Buffer();
  UniqueShortList_Buffer();
  DuplicateLongList_Buffer();
  DuplicateShortList_Buffer();
}

void TestAllNoBuffer() {
  LastTwoRepeating_NoBuffer();
  SingleElement_NoBuffer();
  LongList_NoBuffer();
  UniqueShortList_NoBuffer();
  DuplicateLongList_NoBuffer();
  DuplicateShortList_NoBuffer();
}
