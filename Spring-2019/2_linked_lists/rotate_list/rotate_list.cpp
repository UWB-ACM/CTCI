#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct Node {
    Node* next;
    int data;
};

Node* rotate(Node* node, int k) {
    // placeholder pointers
    Node* curr = node;
    Node* newHead = nullptr;
    // find k-th element
    for (int i = 1; i < k; i++) {
        curr = curr->next;
    }
    // curr now points to new end of list; break list here
    newHead = curr->next;
    curr->next = nullptr;
    // now find end of old list, and point to old head
    curr = newHead;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = node;
    return newHead;
}

string printList(Node* node) {
    stringstream s;
    while (node != nullptr) {
        s << node->data;
        if (node->next != nullptr) {
            s << " -> ";
        }
        node = node->next;
    }
    return s.str();
}

void deleteList(Node* node) {
    if (node->next != nullptr) {
        deleteList(node->next);
    }
    delete node;
    return;
}

int main() {
    Node* prev = nullptr;
    Node* curr = nullptr;
    Node* head = nullptr;
    for (int i = 0; i < 10; i++) {
        curr = new Node();
        curr->data = i + 1;
        if (prev != nullptr) prev->next = curr;
        if (i == 0) head = curr;
        prev = curr;
    }
    cout << "List before: " << printList(head) << endl;
    head = rotate(head, 6);
    cout << "List after:  " << printList(head) << endl;
    cout << endl;
    deleteList(head);
    return 0;
}
