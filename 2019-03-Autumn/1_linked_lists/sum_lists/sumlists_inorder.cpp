#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next = nullptr;
};

struct Result {
    Node* head = nullptr;
    int carry = 0;
};

// Helper function
void printList(Node* n) {
    cout << "( ";
    while (n->next != nullptr) {
        cout << n->data << " -> ";
        n = n->next;
    }
    cout << n->data << " )" << endl;
}

// Helper function
void deleteList(Node* n, bool trim) {
    if (n == nullptr || trim && n->data != 0) return;
    deleteList(n->next, trim);
    delete n;
}

// Helper function
int length(Node* n) {
    int count = 0;
    while (n != nullptr) {
        count++;
        n = n->next;
    }
    return count;
}

// Helper function
Node* padListWithZeroes(Node* n, int zeroes) {
    Node* head = n;
    while (zeroes > 0) {
        Node* tmp = new Node();
        tmp->data = 0;
        tmp->next = head;
        head = tmp;
        zeroes--;
    }
    return head;
}

// Recursive call
void addElements(Node* n1, Node* n2, Result* result) {
    if (n1 == nullptr && n2 == nullptr) return;
    addElements(n1->next, n2->next, result);
    int sum = n1->data + n2->data + result->carry;
    result->carry = (sum > 9 ? 1 : 0);
    Node* tmp = new Node();
    tmp->data = sum % 10;
    if (result->head == nullptr) result->head = tmp;
    else {
        tmp->next = result->head;
        result->head = tmp;
    }
}

// Entry point for recursive solution
Node* getListSum(Node* n1, Node* n2) {
    // pad list if needed
    int n1Length = length(n1);
    int n2Length = length(n2);
    bool trimN1 = false;
    bool trimN2 = false;        // needed for memory cleanup
    if (n1Length > n2Length) {
        n2 = padListWithZeroes(n2, n1Length - n2Length);
        trimN2 = true;
    } else {
        n1 = padListWithZeroes(n1, n2Length - n1Length);
        trimN1 = true;
    }
    // create result wrapper
    Result* result = new Result();
    // begin recursion
    addElements(n1, n2, result);
    // edge case; still have carry value after lists are processed
    if (result->carry == 1) {
        Node* tmp = new Node();
        tmp->data = result->carry;
        tmp->next = result->head;
        result->head = tmp;
    }
    // memory cleanup
    if (trimN1) deleteList(n1, true);
    if (trimN2) deleteList(n2, true);
    Node* tmp = result->head;
    delete result;
    return tmp;
}

void test1() {
    // 9999 + 1 = 10000
    Node* n1 = new Node();
    n1->data = 1;
    Node* n2 = new Node();
    Node* end = n2;
    for (int i = 0; i < 3; i++) {
        end->data = 9;
        end->next = new Node();
        end = end->next;
    }
    end->data = 9;
    cout << "L1: ";
    printList(n1);
    cout << "L2: ";
    printList(n2);
    cout << "Sum: ";
    Node* result = getListSum(n1, n2);
    printList(result);
    deleteList(n1, false);
    deleteList(n2, false);
    deleteList(result, false);
}

void test2() {
    // 7654321 + 2345679 = 10000000
    Node* n1 = new Node();
    Node* end = n1;
    for (int i = 0; i < 7; i++) {
        end->data = 7 - i;
        end->next = new Node();
        if (i < 6) end = end->next;
    }
    delete end->next;
    end->next = nullptr;
    Node* n2 = new Node();
    end = n2;
    for (int i = 0; i < 6; i++) {
        end->data = 2 + i;
        end->next = new Node();
        end = end->next;
    }
        end->data = 9;
    cout << "L1: ";
    printList(n1);
    cout << "L2: ";
    printList(n2);
    cout << "Sum: ";
    Node* result = getListSum(n1, n2);
    printList(result);
    deleteList(n1, false);
    deleteList(n2, false);
    deleteList(result, false);
}

int main() {
    test1();
    test2();
}
