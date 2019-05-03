# Topic Name TODO :bug:

Simple description TODO :bug:

In the style of:
***Problems and solutions for Maze & Dynamic Programming session on March 1, 2019.***

## Problems

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

### 2. PROBLEM 2 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

### 3. Rotate List 

Source: [CrazyForCode](http://www.crazyforcode.com/rotate-linked-list-k-nodes/)

#### Scenario

Given a singly linked list, rotate the list by `k` nodes. The rotation 
will cause the first `k` items to be moved to the back of the list.

You may assume that `k` is smaller than the length of the list.

#### Example Input

```
k = 3
Input:   1 -> 2 -> 3 -> 4 -> 5
Result:  4 -> 5 -> 1 -> 2 -> 3
```

#### Function Signature

Java:

```java
public class ListNode {
    public int data;
    public ListNode next;

    ListNode(int x) {
        data = x;
    }
}

public ListNode rotate(ListNode node, int k) { }
```

C++:

```c++
struct Node {
    Node* next;
    int data;
};

Node* rotate(Node* node, int k);
```

## Solutions

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

### 2. PROBLEM 2 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

## 3. Rotate List

Source: [CrazyForCode](http://www.crazyforcode.com/rotate-linked-list-k-nodes/)

#### Optimal Solution

_Note: An important question to ask with this question is whether `k` is 
guaranteed to be smaller than the length of the list. This implementation 
assumes this is true._

Because linked lists contain pointers/references to their successor links, 
we can take advantage of the list structure without allocating extra memory 
for copy operations.

This problem requires 2 modifications to list links:

1. The `kth` list item must point to `null`
2. The last list item must point to the original head of the list

So, our solution must keep track of the `kth + 1` object so the `kth` link can 
be broken without losing access to subsequent items.

Here is the datatype-agnostic implementation in C++:

```c++
Node* rotate(Node* node, int k) {
    // placeholder pointers
    Node* curr = node;
    Node* newHead = nullptr;
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
```

#### Driver For Solution

The executable C++ solution for this problem is located under 
`Spring-2019/linked_lists/rotate_list/rotate_list.cpp`.

The output for the C++ solution is:

```console
$ g++ -o test rotate_list.cpp -g
$ ./test
List before: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10
List after:  7 -> 8 -> 9 -> 10 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6

[ etc... ]

$
```
