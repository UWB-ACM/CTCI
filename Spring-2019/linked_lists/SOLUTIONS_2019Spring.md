# Linked Lists

Problems and solutions for Linked List session on May 3, 2019.

## Problems

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

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

### 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature


## Solutions

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

### 2. Delete Middle Node

Source: CTCI 6th edition 2.3

#### Optimal Solution

```
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

## 3. PROBLEM 3 TODO :bug:

Source: 

#### Naive/Simple Solution 



#### Optimal Solution


#### Testing The Solutions OR Driver For Solution



