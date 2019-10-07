#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next = nullptr;
};

Node* sumReversedNums(Node* n1, Node* n2) {
    // If the lists are reversed, we can iterate 
    // through the list, carrying the sum % 10 if 
    // the sum is greater than 9, just like regular 
    // addition.
    // We must be careful to avoid accessing digits 
    // for next nodes that are nullptrs.
    Node* result = nullptr;
    Node* end = result;
    int carry = 0;
    while (n1 != nullptr || n2 != nullptr) {
        int sum = carry;
        if (n1 != nullptr) {
            sum += n1->data;
            n1 = n1->next;
        }
        if (n2 != nullptr) {
            sum += n2->data;
            n2 = n2->next;
        }
        carry = (sum > 9 ? 1 : 0);
        Node* tmp = new Node();
        tmp->data = sum % 10;
        if (result == nullptr) {
            result = tmp;
        } else {
            end->next = tmp;
        }
        end = tmp;
    }
    if (carry > 0) {
        Node* tmp = new Node();
        tmp->data = carry;
        end->next = tmp;
    }
    return result;
}

void printList(Node* n) {
    cout << "( ";
    while (n->next != nullptr) {
        cout << n->data << " -> ";
        n = n->next;
    }
    cout << n->data << " )" << endl;
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
    printList(sumReversedNums(n1, n2));
}

void test2() {
    // 1234567 + 765433 = 2000000
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
    end->data = 3;
    for (int i = 1; i < 6; i++) {
        end->next = new Node();
        end = end->next;
        end->data = i + 2;
    }
    cout << "L1: ";
    printList(n1);
    cout << "L2: ";
    printList(n2);
    cout << "Sum: ";
    printList(sumReversedNums(n1, n2));
}

int main() {
    test1();
    test2();
}
