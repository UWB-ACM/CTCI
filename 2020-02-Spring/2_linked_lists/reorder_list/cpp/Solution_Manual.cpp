// UWM ACM CTCI 
// 05/01/2020 
// Week 3: Linked Lists

// Solution for LeetCode #143 Reorder List using manual memory management


#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Helper method that inserts a new node at the end of the linked list
void insert(ListNode* head, int element) {
    ListNode* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = new ListNode(element);
}

// Helper method for creating lists for test cases
ListNode* createBasicList(ListNode* head, std::vector<int> list) {
    ListNode* front = new ListNode(0);
    for (const int &value : list) {
        insert(front, value);
    }
    return front->next;
}

// Helper method for printing the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    std::cout << "[";
    if (current) std::cout << current->val;
    while (current) {
        std::cout <<  ", " << current->val; 
    }
    std::cout << "]" << std::endl;
}

void reorderList(ListNode *head) {
    // Find the middle element of the linked list
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    ListNode *previous = nullptr, *current = slow, *temp;
    while (current) {
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }

    // Merge the two linked lists
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
    ListNode* curr;
}