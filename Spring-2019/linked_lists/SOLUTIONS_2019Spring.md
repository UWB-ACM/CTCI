# Linked Lists

Problems and solutions for Linked List session on May 3, 2019.

## Problems

### 1. Reverse Nodes in k-Group

Source: [leetcode](https://leetcode.com/problems/reverse-nodes-in-k-group/)

#### Scenario:

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
`k` is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of `k`  then left-out nodes in the end should remain as it is.

#### Function Signature

C++:

```c++
using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int data;
*     ListNode *next;
*     ListNode(int x) : data(x), next(NULL) {}
* };
*/

ListNode* reverseKGroup(ListNode* head, int k) {}
```

Java:

```java
/**
* Definition for singly-linked list.
* public class ListNode {
*     int data;
*     ListNode next;
*     ListNode(int x) { data = x; }
* }
*/

ListNode reverseKGroup(ListNode head, int k) {}
```

### 2. Delete Middle Node

Source: CTCI 6th edition 2.3

#### Scenario

Write a method to delete a node in the middle (i.e., any node but the first and last node,
not necessarily the exact middle) of a singly linked list, given only access to that node.

#### Example Input

Node c from the linked list a->b->c->d->e->f is passed to the method
Result: nothing is returned, but the new linked list looks like a->b->d->e->f

#### Function Signature

Java:
```
boolean deleteMiddleNode(LinkedListNode n) {}
```

C++:

```
boolean deleteMiddleNode(LinkedListNode* n) {}
```

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

### 1. Reverse Nodes in k-Group

Source: [GreeksforGreeks](https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/)

#### Optimal Solution

The optimal solution for this problem is to reverse the first sub-list of size `k` while keeping track of the next node and previous node. Then, recursively call for rest of the list and link the two sub-lists toghether. 

Time Complexity: `O(n)` where n is the number of nodes in the given list.

Here is a solution method:

C++:

```c++
/* Reverses the linked list in groups 
of size k and returns the pointer 
to the new head node. */
ListNode* reverseKGroup(ListNode* head, int k) {
  ListNode* current = head;  
  ListNode* next = NULL;  
  ListNode* prev = NULL;  
  int count = 0;  

  //reverse first k nodes of the linked list 
    while(current != NULL && count < k) {  
       next = current->next;  
       current->next = prev;  
       prev = current;  
       current = next;  
       count++;  
   }  
 /* next is now a pointer to (k+1)th node  
    Recursively call for the list starting from current.  
    And make rest of the list as next of first node */
    if (next != NULL)  
    head->next = reverseKGroup(next, k);  

   /* prev is new head of the input list */
  return prev;  
 }  
}
```

Java:

```java
ListNode reverseKGroup(ListNode head, int k) { 

   ListNode current = head; 
   ListNode next = null; 
   ListNode prev = null; 

   int count = 0; 

      /* Reverse first k nodes of linked list */
         while (count < k && current != null) { 
      
           next = current.next; 
           current.next = prev; 
           prev = current; 
           current = next; 
           count++; 
      } 

      /* next is now a pointer to (k+1)th node  
         Recursively call for the list starting from current. 
         And make rest of the list as next of first node */
         if (next != null)  
         head.next = reverse(next, k); 

    // prev is now head of input list 
       return prev; 
}                       
```
#### Testing The Solutions OR Driver For Solution

The executable C++ solution for this problem is located under `Spring-2019/linked_lists/Reverse_Nodes_In_k-Group/ReverseLinkedList.cpp`.

The output for C++ solution where `k` = 5 is:

```console
$ g++ -c -std=c++11 ReverseLinkedList.cpp
$ g++ -o a.out ReverseLinkedList.o
$ ./a.out
Given linked list 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 
Reversed Linked list in groups of given size
5 4 3 2 1 10 9 8 7 6 15 14 13 12 11 19 18 17 16
```

### 2. Delete Middle Node

Source: CTCI 6th edition 2.3

#### Optimal Solution

Because we don't have access to the head node of the list, we cannot cycle back to the node in 
question from the head of the list. This constrains our ability to safely delete the last node 
in the list, so checking that the node and the node's next item is not `null` is important. If 
these two checks pass, then we simply replace the node's value with it's successor's value and 
delete the successor node.

```java
boolean deleteNode(LinkedListNode n) {
    if(n == null || n.next == null) {
        return false; // Failure
    }
    LinkedListNode next = n.next;
    n.data = next.data;
    n.next = next.next;
    return true;
}
```

#### Testing The Solutions OR Driver For Solution

The executable java test driver is located `spring-2019/linked_lists/Delete_Middle_Node/TestDeleteMiddleNode.java`

```
Given Linked List:
a->b->c->d->e->f->Null

Linked List after deletion of middle
a->b->d->e->f->Null

Result of Null node passed to delete middle function
false


Result of Null node passed to delete middle function
false
```

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

$
```

