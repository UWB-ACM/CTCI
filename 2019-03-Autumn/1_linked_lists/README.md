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

Given a circular (or non-circular) linked list, implement an algorithm that 
returns the node at the beginning of the loop if a loop exists.

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

### 3. Sum Lists

Source: CTCI 2.5

#### Scenario

You have two integers, each represented by a linked list where each node 
contains a single digit. The digits are stored in _reverse_ order, such 
that the 1's digit is at the head of the list. Write a function that adds 
the two numbers and returns the sum as a linked list.

**Example:**

Input: `( 7 -> 1 -> 6 )  +  ( 5 -> 9 -> 2 )`. That is, `617 + 295`.

Output: `( 2 -> 1 -> 9 )`. That is, `912`.

###### Bonus Question (If You Have Time)

Suppose the digits are stored in forward order. Repeat the above problem. 

**Example:**

Input: `( 6 -> 1 -> 7 )  +  ( 2 -> 9 -> 5 )`. That is, `617 + 295`.

Output: `( 9 -> 1 -> 2 )`. That is, `912`.

#### Function Signature

Java:

```java
public class Node {
    public int data;
    public Node next;
}

public Node sumReversedNums(Node n1, Node n2) {
    // your code here
}

// bonus
public Node sumOrderedNums(Node n1, Node n2) {
    // your code here
}
```

C++:

```c++
struct Node {
    int data;
    Node* next;
};

Node* sumReversedNums(Node* n1, Node* n2) {
    // your code here
}

// bonus
Node* sumOrderedNums(Node* n1, Node* n2) {
    // your code here
}
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

### 2. Loop Detection

Source: CTCI 2.8

#### Solution for Detect Loop

By using the *slow pointer and fast pointer* (or *tortoise and hare*) approach,
we can guarantee that in the case which there is a loop, the 2 pointers will 
meet at some node in the loop.

```
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

#### Solution for Start of Loop (Intro)

In the previous solution, we were able to detect the existence of a loop. Now, 
to find where the loop starts, one technique is to count the number of nodes in 
the loop. Since we know we have a loop, for any node `n` in the list where `n` 
is also in the loop, `n` will be the same node as the (`n` + `sizeOfLoop`)th 
node. Having that information, we can adopt a technique similar to the one used 
in Problem 1. Starting from the head, make the two pointers having a distance 
of the size of the loop, and step through the linked list (at the same pace 
this time) until they meet.

```c++
struct Node {
    int data;
    Node* next;
};

Node* startOfLoopIntro(Node* head) {
    Node* fast = head;
    Node* slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            // now we need to find the start of the loop
            // count number of nodes in loop
            int sizeOfLoop = 1;
            slow = slow->next;
            while (fast != slow) {
                slow = slow->next;
                sizeOfLoop++;
            }
            // now we can go back to the head
            fast = head; slow = head;
            // and make the distance of the pointers the size of the loop
            for (int i = 0; i < sizeOfLoop; i++) {
                fast = fast->next;
            }
            // now move both at the same pace
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

#### Optimal Solution for Start of Loop

It turns out that counting the size of the loop isn't needed. We just need to 
set one of the pointers back to head and move both pointers until they meet.

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

### 3. Sum Lists

Source: CTCI 2.5

#### Solution for Reversed List (First Problem Statement)

Because the order in which we add the digits is the same order in which 
they are presented, we iterate through the lists in lockstep and add 
the `sum % 10` of the respective list nodes to a new list we call `result`. 
As with traditional addition, we carry a 1 when `sum` is greater than 9, 
and that extra value gets included in the next `sum` operation for 
the subsequent node. 
This approach requires checking whether the either of the current nodes 
are `null`, and when both are `null`, the loop terminates.

The code is given as:

```c++
Node* sumReversedNums(Node* n1, Node* n2) {
    // build list for resulting sum
    Node* result = nullptr;
    Node* end = result;
    int carry = 0;
    // iterate through argument lists
    while (n1 != nullptr || n2 != nullptr) {
        int sum = carry;
        if (n1 != nullptr) {
            sum += n1->data;
            n1 = n1->next;
        }
        if (n2 != nullptr) {
            sum += n2->data;
            n2 = n2->next;
        }
        carry = (sum > 9 ? 1 : 0);
        // add result to result list
        Node* tmp = new Node();
        tmp->data = sum % 10;
        if (result == nullptr) {
            result = tmp;
        } else {
            end->next = tmp;
        }
        end = tmp;
    }
    // edge case: sum requires additional decimal place
    if (carry > 0) {
        Node* tmp = new Node();
        tmp->data = carry;
        end->next = tmp;
    }
    return result;
}
```

**NOTE:** This solution is iterative, and equivalent solutions may be 
written recursively. See the detailed solution in CTCI for a recursive 
implementation.

#### Solution for Ordered List (Bonus Problem Statement)

Because the order of the lists has fundamentally changed, we must take 
a different approach. 

The simplest solution will recursively traverse the two lists until the 
last element is found, and then perform the addition at each recursive 
level. This presents complications when we consider that the two lists 
may have different lengths, and so our approach must compensate for this. 

To compensate for this problem, we can ensure the lists are of equal 
length by padding the shorter list with leading zeroes as needed. 
Helper functions (or function placeholders) for this should be written.

Additional complications arise when we consider how to ensure the 
`carry` and `result` values remain consistent between recursive calls. 
The simplest way to ensure this is to create a wrapper class/struct for 
these specific data items, particularly because we are building a list 
to store our results.

In our implementation, our helper methods and structs look like this:

```c++
struct Node {
    int data;
    Node* next = nullptr;
};

struct Result {
    Node* head = nullptr;
    int carry = 0;
};

// Helper function
int length(Node* n) {
    int count = 0;
    while (n != nullptr) {
        count++;
        n = n->next;
    }
    return count;
}

// Helper function
Node* padListWithZeroes(Node* n, int zeroes) {
    Node* head = n;
    while (zeroes > 0) {
        Node* tmp = new Node();
        tmp->data = 0;
        tmp->next = head;
        head = tmp;
        zeroes--;
    }
    return head;
}
```

The core implementation is in these two methods:

```c++
// Recursive call
void addElements(Node* n1, Node* n2, Result* result) {
    // base case: entire list has been traversed
    if (n1 == nullptr && n2 == nullptr) return;
    // recurse to end of list
    addElements(n1->next, n2->next, result);
    // perform addition
    int sum = n1->data + n2->data + result->carry;
    result->carry = (sum > 9 ? 1 : 0);
    // add sum to result list
    Node* tmp = new Node();
    tmp->data = sum % 10;
    if (result->head == nullptr) result->head = tmp;
    else {
        tmp->next = result->head;
        result->head = tmp;
    }
}

// Entry point for recursive solution
Node* sumOrderedNums(Node* n1, Node* n2) {
    // pad list if needed
    int n1Length = length(n1);
    int n2Length = length(n2);
    if (n1Length > n2Length) n2 = padListWithZeroes(n2, n1Length - n2Length);
    else n1 = padListWithZeroes(n1, n2Length - n1Length);
    // create result wrapper
    Result* result = new Result();
    // begin recursion
    addElements(n1, n2, result);
    // edge case: still have carry value after lists are processed
    if (result->carry == 1) {
        Node* tmp = new Node();
        tmp->data = result->carry;
        tmp->next = result->head;
        result->head = tmp;
    }
    return result->head;
}
```

**NOTE:** While recursion is useful in specific circumstances, it becomes 
impractical for extremely large lists due to stack size. In an interview, 
it can be expected for you to mention why this approach might not be ideal 
for all cases.

#### Driver For Solutions

[The iterative solution for the reversed lists is here.](./sum_lists/sumlists.cpp)

The output for the solution is:

```console
$ g++ -o test sumlists.cpp
$ ./test
L1: ( 1 )
L2: ( 9 -> 9 -> 9 -> 9 )
Sum: ( 0 -> 0 -> 0 -> 0 -> 1 )
L1: ( 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 )
L2: ( 3 -> 3 -> 4 -> 5 -> 6 -> 7 )
Sum: ( 0 -> 0 -> 0 -> 0 -> 0 -> 0 -> 2 )
```

[The recursive solution for the ordered lists is here.](./sum_lists/sumlists_inorder.cpp)

The output for the solutions is here:

```console
$ g++ -o test sumlists_inorder.cpp
$ ./test
L1: ( 1 )
L2: ( 9 -> 9 -> 9 -> 9 )
Sum: ( 1 -> 0 -> 0 -> 0 -> 0 )
L1: ( 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 )
L2: ( 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 9 )
Sum: ( 1 -> 0 -> 0 -> 0 -> 0 -> 0 -> 0 -> 0 )
```
