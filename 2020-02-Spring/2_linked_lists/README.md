<!-- Don't remove -->
<a name="top"/>

# Linked List Manipulation

Practice solving linked list related problems. Session on May 1, 2020.

### Table of Contents

* [Problems](#problems)
  * [1](#p1)
  * [2](#p2)
  * [3](#p3)
* [Solutions](#solutions)
  * [1](#s1)
  * [2](#s2)
  * [3](#s3)

<!-- Don't remove -->
<a name="problems"/>

## Problems

<a name="p1"/>

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

<!-- Don't remove -->
Go to [Solution](#s1)   [Top](#top)

<!-- Don't remove -->
<a name="p2"/>

### 2. PROBLEM 2 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

<!-- Don't remove -->
Go to [Solution](#s2)   [Top](#top)

<!-- Don't remove -->
<a name="p3"/>

### 3. Reorder List

Source: [LeetCode](https://leetcode.com/problems/reorder-list/)

#### Scenario

Given a singly linked list

![Starting linked list](images/end_ll.png)

Reorder it to: 

![Ending linked list](images/end_ll)



You may **not** modify the values in the list's nodes. 
Only the pointers of the nodes may be changed.

#### Example Input

Given 1->2->3->4, reorder to 1->4->2->3.

Given 1->2->3->4->5, reorder to 1->5->2->4->3.

#### Function Signature

```java
// Definition for singly linked list
public class ListNode {
  int val;
  ListNode next;
  ListNode(int x) { val = x; }
}

void reorderList(ListNode head) {
  // Your code here
}
```

```cpp
// Definition for singly linked list
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
  ~ListNode() {
      delete next;
  }
};

void reorderList(ListNode* head) {
  // Your code here
}
```

<!-- Don't remove -->
Go to [Solution](#s3)   [Top](#top)

<!-- Don't remove -->
<a name="solutions"/>

## Solutions

<!-- Don't remove -->
<a name="s1"/>

### 1. SOLUTION 1 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution
<details>
<summary>Click to see solution</summary>

TODO put your solution here :bug:

</details>


#### Optimal Solution

<details>
<summary>Click to see solution</summary>

TODO put your solution here :bug:

</details>

#### Testing The Solutions OR Driver For Solution

TODO :bug:

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s2"/>

### 2. SOLUTION 2 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution

<details>
<summary>Click to see solution</summary>

TODO put your solution here :bug:

</details>

#### Optimal Solution

<details>
<summary>Click to see solution</summary>

TODO put your solution here :bug:

</details>

#### Testing The Solutions OR Driver For Solution

TODO :bug:

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s3"/>

### 3. Reorder List Solution

<details>
<summary>Click to see solutions and solution explanation</summary>

#### Algorithm Overview

This problem is a combination of three common linked list manipulations:

* Finding the middle of a linked list
* Reversing a linked list
* Merging two linked lists


#### Complexity Analysis

* ***Time Complexity***: `O(N)`

    * O(N) - Finding the middle node of the linked list (N / 2 operations, which is asymptotically O(N))
    * O(N) - Reversing the second half of the linked list (N / 2 operations, which is asymptotically O(N))
    * O(N) - Merging the in-order list and reversed linked list (N / 2 operations, which is asymptotically O(N))

* ***Space Complexity***: `O(1)`

    * No new data structures are created. Only pointers are used to manipulate the nodes of the linked list. 


<details>
<summary>Click to see Java solution</summary>

```java
    public void reorderList(ListNode head) {
        // Find the middle node of the linked list
        // 1->2->3->4->5->6, find 4
        ListNode slow = head, fast = head;
        while (fast && fast.next) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Reverse the second half of the linked list
        // 1->2->3->4->5->6 ----> 1->2->3->4, 6->5->4
        ListNode previous = null, current = slow, temp;
        while (current) {
            temp = current.next;
            current.next = previous;
            previous = current;
            current = temp;
        }

        // Merge the two linked lists
        // 1->2->3->4, 6->5->4 ----> 1->6->2->5->3->4
        ListNode first = head, second = previous;
        while (second.next) {
            temp = first.next;
            first.next = second;
            first = temp;

            temp = second.next;
            second.next = first;
            second = temp;
        }
    }

```

</details>



<details>

<summary>Click to see C++ solution</summary>

```cpp
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

```
</details>


#### Tests for Solution

##### Java 

See `reorder_list/java/Solution.java` for helper methods.

```java
    public static void main(String[] args) {
        ArrayList<Integer> list1 = new ArrayList<>({1, 2, 3, 4});
        ListNode testCase1 = makeBasicList(list1);
        System.out.print("Before: ");
        printList(testCase1);
        reorderList(testCase1);
        
        System.out.print("After: ");
        printList(testCase1); // Expected: 1, 4, 2, 3

        ArrayList<Integer> list2 = new ArrayList<>({1, 2, 3, 4, 5});
        ListNode testCase2 = makeBasicList(list2);
        System.out.print("Before: ");
        printList(testCase2);
        reorderList(testCase2);
        
        System.out.print("After: ");
        printList(testCase2); // Expected: 1, 5, 2, 4, 3
    }
```

##### C++

See `reorder_list/cpp/Solution_Manual.cpp` for helper methods.

```cpp
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

```

TODO :bug:

<!-- Don't remove -->
Go to [Top](#top)
