// UWM ACM CTCI 
// 05/01/2020 
// Week 3: Linked Lists

// Solution for LeetCode #143 Reorder List using manual memory management
// Compile and run using: make ; ./Solution_Manual


#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ~ListNode() {
        delete next;
    }
};

// Helper method that inserts a new node at the end of the linked list
ListNode* insert(ListNode* head, int element) {
    ListNode* newNode = new ListNode(element);
    if (head == nullptr) {
        head = newNode;
    } else {
        ListNode* current = head;
        while (current && current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

// Helper method for creating lists for test cases
ListNode* createBasicList(std::vector<int> list) {
    ListNode* front = nullptr;
    for (const int &value : list) {
        front = insert(front, value);
    }
    return front;
}

// Helper method for printing the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    std::cout << "[";
    if (current) { 
        std::cout << current->val;
        current = current->next;
    }
    while (current) {
        std::cout <<  ", " << current->val; 
        current = current->next;
    }
    std::cout << "]" << std::endl;
}

void reorderList(ListNode *head) {
    // Find the middle element of the linked list
    // 1->2->3->4->5->6, find 4
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    // 1->2->3->4->5->6 ----> 1->2->3->4, 6->5->4
    ListNode *previous = nullptr, *current = slow, *temp;
    while (current) {
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }

    // Merge the two linked lists
    // 1->2->3->4, 6->5->4 ----> 1->6->2->5->3->4
    ListNode *first = head, *second = previous;
    while (second->next) {
        temp = first->next;
        first->next = second;
        first = temp;

        temp = second->next;
        second->next = first;
        second = temp;
    }
};

int main() {
    std::vector<int> vec{1, 2, 3, 4};
    ListNode* testCase1 = createBasicList(vec);
    std::cout << "Before: ";
    printList(testCase1);
    reorderList(testCase1);

    std::cout << "After: ";
    printList(testCase1); // Expected: 1, 4, 2, 3


    std::vector<int> vec2{1, 2, 3, 4, 5};
    ListNode* testCase2 = createBasicList(vec2);

    std::cout << "Before: ";
    printList(testCase2);
    reorderList(testCase2);

    std::cout << "After: ";
    printList(testCase2); // Expected: 1, 5, 2, 4, 3

    delete testCase1;
    delete testCase2;
}
