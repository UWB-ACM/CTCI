#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
struct Node {
    Node* next;
    T data;
};

template <typename T>
Node<T>* rotate(Node<T>* node, int k) {
    // placeholder pointers
    Node<T>* curr = node;
    Node<T>* newHead = nullptr;
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

template <typename T>
string printList(Node<T>* node) {
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

template <typename T>
void deleteList(Node<T>* node) {
    if (node->next != nullptr) {
        deleteList(node->next);
    }
    delete node;
    return;
}

int main() {
    Node<int>* prev = nullptr;
    Node<int>* curr = nullptr;
    Node<int>* head = nullptr;
    for (int i = 0; i < 10; i++) {
        curr = new Node<int>();
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
