# Linked Lists

Problems and solutions for Linked Lists session on January 29, 2019.

## Problems

### 1. Print In Reverse

Source: [HackerRank](https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem)

#### Scenario

Given a pointer to the head, print the list in reverse. Print each item on a new line.

#### Example Input

```
Input: 5 -> 4 -> 3
Output:
3
4
5
```

#### Function Signature

Java:

```java
/*
 * public class Node {
 *     public int data;
 *     public Node next;
 *     public Node (int data) { 
 *     this.data = data; 
 * }
 */

public void reverse(Node head) {
    // your code here
}
```

### 2. Cycle Detection

Source: [HackerRank](https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/forum)

#### Scenario

A linked list is said to contain a cycle if any node is visited more than once while traversing the list. Given a pointer to the head, return true or false as to whether there is a cycle in the linked list.

#### Example Input

```
Example 1:
Input: 1 -> 2 -> 3
Output: false
```

```
Example 2:
Input: 1 -> 2 -> 3 -> 1[head]
Output: true
```

#### Function Signature

Java:

```java
/*
 * public class Node {
 *     public int data;
 *     public Node next;
 *     public Node (int data) { 
 *     this.data = data; 
 * }
 */

public boolean hasCycle(Node head) {
    // your code here
}
```

### 3. Get Node Value

Source: [HackerRank](https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem)

#### Scenario

A value `k` and a pointer to the head of the list are given. Counting backwards from the tail of the list, return the value of the `k`th last node.

#### Example Input

```
Input: 1 -> 2 -> 3 -> 4, index 1
Output: 3
```

#### Function Signature

```java
/*
 * public class Node {
 *     public int data;
 *     public Node next;
 *     public Node (int data) { 
 *     this.data = data; 
 * }
 */

public int getNodeFromTail(Node head, int idx) {
    // your code here
}
```

## Solutions

### 1. Print In Reverse

Source: [HackerRank](https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem)

#### Solution

For the provided `Node` class, the best solution recursively traverses the list and prints the node value before each recursive stack frame is destroyed.

This is not a great solution for extensive lists because recursion incurs stack frames and can cause a stack overflow if the list is sufficiently large. In situations like that, an iterative approach is appropriate, and using a doubly linked list would allow iterative printing of the reversed list without repeatedly iterating down the list at incrementally smaller depths.

The Java solution is below:

```java
public static void reverse(Node head) {
    if (head == null) return;
    reverse(head.next);
    System.out.println(head.data);
}
```

#### Testing The Solutions

The Java solution is in `Winter-2019/linked_lists/reverse_print/ReversePrint.java`. The solution can be run as follows:

```console
$ javac *.java
$ java ReversePrint
Original array:
4
13
12
-3
4
8
9
17
0
3
Reversed array:
3
0
17
9
8
4
-3
12
13
4
```

### 2. Cycle Detection

Source: [HackerRank](https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/forum)

#### Solution

The only reliable way to ensure any cycle at any point in the list is detected is to take a leapfrog approach. Two pointers traverse the list at different rates, so that one pointer can reach the end of the list (or traverse the cycle point) ahead of the other one. Regardless of the length of the cycle or the number of steps the faster pointer takes in each iteration, the pointers are guaranteed to eventually land on the same list node at some point, at which point the function will return true.

Note: both pointers must continue to traverse the list because the cycle can occur at any point in the list (not necessarily at the head).

This solution is implemented in Python in the function below.

```python
def hasCycle(head):
    # check the edge case
    if head is None:
        return False
    # create the leapfrog pointers
    tortoise = head
    hare = head
    # begin traversing the list
    while hare is not None and hare.next is not None:
        tortoise = tortoise.next
        hare = hare.next.next
        if tortoise == hare:
            return True
    return False
```

#### Testing The Solutions

The complete Python implementation is available in `Winter-2019/linked_lists/cycle_detect/cycle.py`. The output of the script is as follows:

```console
$ python cycle.py
Testing list with cycle.	Result: True
Testing list without cycle.	Result: False
```

### 3. Get Node Value

Source: [HackerRank](https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem)

#### Recursive Solution

In a problem like this, we would normally look to recursion as a possible solution to the problem. This is a valid approach, but requires unusual and awkward language features to accomplish it correctly.

C++ was used for this implementation because of the way references are treated. The language features allow the `k`th item to be tracked correctly across all stack frames, and it allows the resulting value to be updated when the correct node has been found after the recursive path has been travelled.

```c++
int getValue(Node* head, int& k) {
    int result = -1;
    getValueRecursiveHelper(head, k, k, result);
    return result;
}

void getValueRecursiveHelper(Node* head, int& k, int original, int& val) {
    // base case; begin backtracking through frames
    if (head == nullptr) {
        k--;
        return;
    }
    // make recursive call otherwise
    getValueRecursiveHelper(head->next, k, original, val);
    // ensure the correct value is stored in the result reference
    if (k == 0) val += (0 - val + head->data);
    if (k < original) k--;
}
```

_Note: the caveat of this solution is that the _`result`_ value will not reflect a real array value if _`k`_ is greater than the list's length. A slightly better way of indicating as much would be to use a minimum or maximum constant value from the language's library._

#### Iterative Solution

A more clever and language-agnostic solution to this problem takes advantage of keeping track of the offset between the current node position and the node we are trying to target.

A leader pointer traverses the list in a for loop which keeps track of the integer index. When the index value becomes equal to the desired value of `k`, the desired offset has been found, and the result node pointer begins to traverse in lockstep with the leader pointer.

When the leader pointer has reached a null value, the result node pointer has been located because the `k` interval has been preserved.



The Java implementation is as follows:

```java
public static int getValueIterative(Node head, int target) {
    Node result = head;
    for (int i = 0; head != null; i++) {
        head = head.next;
        // preserve the interval between head and result
        if (i >= target) result = result.next;
    }
    return result.data;
}
```

_Note: the caveat of this solution is that the _`result`_ value will actually reflect the head node's value if _`k`_ is greater than the list's length._

#### Testing The Solutions

The solutions can be found in `Winter-2019/linked_lists/node_value`.

The iterative solution is in `GetValue.java`, and can be run as follows with the following output:

```console
$ javac *.java
$ java GetValue
Original array: 3 18 4 9 12 -6 2 
k = 3:  12
k = 20: 3
```

The recursive solution is in `getvalue.cpp`, and can be run as follows with the following output:

```console
$ g++ -o test getvalue.cpp
$ ./test
k = 3:	4	(Expecting 4)
k = 8:	-1	(Expecting -1)
```
