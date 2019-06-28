#include <iostream>
#include <sstream>

using namespace std;

class Node {

    public: 
        int data;
        Node* next = nullptr;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }

        // constructor assumes that array has non-zero length
        // bad constructor! bad!
        Node(int arr[], int length) {
            this->data = arr[0];
            Node* curr = nullptr;
            Node* prev = nullptr;
            for (int i = 1; i < length; i++) {
                curr = new Node(arr[i]);
                if (i == 1) this->next = curr;
                else prev->next = curr;
                prev = curr;
            }
        }

};

void getValueRecursiveHelper(Node* head, int& k, int original, int& val) {
    if (head == nullptr) {
        k--;
        return;
    }
    getValueRecursiveHelper(head->next, k, original, val);
    if (k == 0) val += (0 - val + head->data);
    if (k < original) k--;
}

int getValue(Node* head, int& k) {
    int result = -1;
    getValueRecursiveHelper(head, k, k, result);
    return result;
}

int main() {
    int arr[] = {8, 12, -3, 4, 9, 2};
    Node* head = new Node(arr, 6);
    int v1 = 3;
    cout << "k = 3:\t" << getValue(head, v1) << "\t(Expecting 4)" << endl;
    int v2 = 8;
    cout << "k = 8:\t" << getValue(head, v2) << "\t(Expecting -1)" << endl;
    return 0;
}
