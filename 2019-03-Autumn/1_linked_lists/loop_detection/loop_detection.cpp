#include <iostream>
#include <vector>

struct Node
{
    int data;
    Node* next;
};

bool detectLoop(Node* head) {
    Node* fast = head;
    Node* slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            return true;
        }
    }
    // fast hit nullptr, no loop
    return false;
}

Node* startOfLoop(Node* head) {
    Node* fast = head;
    Node* slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            // now we need to find the start of the loop
            fast = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    // fast hit nullptr, no loop
    return nullptr;
}

Node* array2LinkedList(const std::vector<int>& nums) {
    Node* head = new Node{0, nullptr};
    Node* retVal = head;
    for (int num : nums) {
        retVal->next = new Node{num, nullptr};
        retVal = retVal->next;
    }
    retVal = head->next;
    return retVal;
}

void addToEnd(Node* head, Node* toAdd) {
    if (head == nullptr) {
        return;
    }
    while (head->next != nullptr) {
        head = head->next;
    }
    head->next = toAdd;
}

int main() {
    Node* test1 = array2LinkedList({1,2,3,4,5,6,7,8});
    std::cout << "Test1, detectLoop: " << detectLoop(test1) << std::endl;
    std::cout << "Test1, startOfLoop: " << startOfLoop(test1) << std::endl;
    
    Node* test2 = array2LinkedList({1,2,3,4,5,6,7,8});
    addToEnd(test2, test2->next->next);     // the '3' Node
    std::cout << "Test2, detectLoop: " << detectLoop(test2) << std::endl;
    std::cout << "Test2, startOfLoop: " << startOfLoop(test2)->data << std::endl;
    
    Node* test3 = array2LinkedList({1,2,3,4,5,6,7,8});
    addToEnd(test3, test3);     // the head aka '1' Node
    std::cout << "Test3, detectLoop: " << detectLoop(test3) << std::endl;
    std::cout << "Test3, startOfLoop: " << startOfLoop(test3)->data << std::endl;
    
    Node* test4 = array2LinkedList({1,2,3,4,5,6,7,8});
    addToEnd(test4, test4->next->next->next->next->next->next->next);   // last Node
    std::cout << "Test4, detectLoop: " << detectLoop(test4) << std::endl;
    std::cout << "Test4, startOfLoop: " << startOfLoop(test4)->data << std::endl;
    
    return 0;
}