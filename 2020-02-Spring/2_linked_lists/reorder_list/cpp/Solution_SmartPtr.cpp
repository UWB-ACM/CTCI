// UWM ACM CTCI 
// 05/01/2020 
// Week 3: Linked Lists

// Solution for LeetCode #143 Reorder List using shared pointers 

#include <iostream>
#include <memory> 
#include <vector> 

struct ListNode {
    int val;
    std::shared_ptr<ListNode> next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, std::shared_ptr<ListNode> next) : val(x), next(next) {}
};

std::shared_ptr<ListNode> insert(std::shared_ptr<ListNode> head, int element) {
    std::shared_ptr<ListNode> newNode(new ListNode(element));
    if (head == nullptr) {
        head = newNode;
    } else {
        std::shared_ptr<ListNode> current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

// Helper method for creating lists for test cases
std::shared_ptr<ListNode> createBasicList(std::vector<int> list) {
    std::shared_ptr<ListNode> front = nullptr;
    for (const int &value : list) {
        front = insert(front, value);
    }
    return front;
}

void printList(std::shared_ptr<ListNode> head) {
    std::shared_ptr<ListNode> current = head;
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


void reorderList(std::shared_ptr<ListNode> head) {
    // Find the middle element of the linked list
    std::shared_ptr<ListNode> slow = head, fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    std::shared_ptr<ListNode> previous = nullptr, current = slow, temp;
    while (current) {
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }

    // Merge the two linked lists
    std::shared_ptr<ListNode> first = head, second = previous;
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
    std::shared_ptr<ListNode> testCase1 = createBasicList(vec);
    std::cout << "Before: ";
    printList(testCase1);
    reorderList(testCase1);

    std::cout << "After: ";
    printList(testCase1); // Expected: 1, 4, 2, 3


    std::vector<int> vec2{1, 2, 3, 4, 5};
    std::shared_ptr<ListNode> testCase2 = createBasicList(vec2);

    std::cout << "Before: ";
    printList(testCase2);
    reorderList(testCase2);

    std::cout << "After: ";
    printList(testCase2); // Expected: 1, 5, 2, 4, 3
}