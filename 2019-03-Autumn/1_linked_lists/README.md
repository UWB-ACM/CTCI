# Linked Lists

Problems and solutions for Linked List session on October 11, 2019.

## Problems

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

### 2. Loop Detection

Source: CTCI 2.8

#### Scenario

Given a circular (or non-circular) linked list, implement an algorithm that returns the node at the beginning of the loop.

#### Example Input

Input:
```
1 -> 2 -> 3 -> 4 -> 5
          ⬆        ⬇
          8 <- 7 <- 6
```
Output: `true` or `3(Node)`

#### Function Signature

Java:
```java
public class Node {
    public int data;
    public Node next;
}

// basic
public boolean detectLoop(Node head) {
    // your code here
}

public Node startOfLoop(Node head) {
    // your code here
}
```

C++:
```c++
struct Node {
    int data;
    Node* next;
};

bool detectLoop(Node* head) {
    // your code here
}

Node* startOfLoop(Node* head) {
    // your code here
}
```

### 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

## Solutions

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

### 2. Loop Detection

Source: CTCI 2.8

#### Solution for Detect Loop

By using the *slow pointer and fast pointer* approach, we can guarantee that in 
the case which there is a loop, the 2 pointers will meet at some node in the loop.

```c++
struct Node {
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
```

#### Solution for Start of Loop

To find the start of the loop, we first do the same steps as the solution above.
When the pointers collide, we move one of the pointers back to head, and move 
both pointers again, but at the normal (one at the time) speed. When they 
collide again, we have found the answer.


[GeeksforGeeks](https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/)
has a good explanation of why this works.

```c++
struct Node {
    int data;
    Node* next;
};

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
```

#### Driver For Solution

[The C++ implementation is available here.](./loop_detection/loop_detection.cpp)

### 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution 

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:


