//
// Created by ryan on 1/20/20.
//

#ifndef INC_1_LINKED_LISTS_NODE_H
#define INC_1_LINKED_LISTS_NODE_H

class Node {
public:
  explicit Node(int Value = 0, Node *Next = nullptr) {
    this->Value = Value;
    this->Next = Next;
  }

  void SetValue(int V) { this->Value = V; }

  void SetNext(Node *N) { this->Next = N; }

  int GetValue() { return this->Value; }

  Node *GetNext() { return this->Next; }

private:
  int Value;
  Node *Next;
};

#endif // INC_1_LINKED_LISTS_NODE_H
