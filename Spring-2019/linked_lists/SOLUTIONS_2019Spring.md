# Linked Lists

Problems and solutions for Linked List session on May 3, 2019.

## Problems

### 1. Reverse Nodes in k-Group

Source: [leetcode](https://leetcode.com/problems/reverse-nodes-in-k-group/)

#### Scenario:

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
`k` is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of `k`  then left-out nodes in the end should remain as it is.

**Note:**
* Only constant extra memory is allowed.
* You may not alter the values in the list's nodes, only nodes itself may be changed.

#### Example Input

```
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
```
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
### 2. PROBLEM 2 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

### 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

### 3. PROBLEM 2 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:


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

```c++
$ g++ -c -std=c++11 ReverseLinkedList.cpp
$ g++ -o a.out ReverseLinkedList.o
$ ./a.out
Given linked list 
1 2 3 4 5 6 7 8 9 10 11 12 13 15 16 17 18 19 
Reversed Linked list in groups of given size
5 4 3 2 1 10 9 8 7 6 16 15 13 12 11 19 18 17
```
### 2. PROBLEM 2 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

## 3. PROBLEM 3 TODO :bug:

Source: 

#### Naive/Simple Solution 



#### Optimal Solution


#### Testing The Solutions OR Driver For Solution



