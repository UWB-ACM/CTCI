<!-- Don't remove -->
<a name="top"/>

# Linked Lists

Problems and solutions for Linked Lists session on January 24, 2020.

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

### 1. LIST PALINDROME 

Source: geeksforgeeks 

#### Scenario

Check if a linked list of N integers is a palindrome.
Return 1 if palindrome, 0 otherwise
1 <= n <= 10

#### Example Input

Input: 1->2->1
Output: 1

Input: 1
Output: 0

#### Function Signature

```Java

class Node
{
	int data;
	Node next;
	
	Node(int d)
	{
		data = d;
		next = null;
	}
}

boolean isPalindrome(Node head) 
{
    //Your code here
}  
```

```C++

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

bool isPalindrome(Node *head)
{
    //Your code here
}
```
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

### 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

<!-- Don't remove -->
Go to [Solution](#s3)   [Top](#top)

<!-- Don't remove -->
<a name="solutions"/>

## Solutions

<!-- Don't remove -->
<a name="s1"/>

### 1. LIST PALINDROME 

Source: geeksforgeeks 

#### Solution

A simple solution is to use a stack of list nodes.
This mainly involves three steps:
1.Traverse the given list from head to tail and push every visited node to stack.
2.Traverse the list again. For every visited node, pop a node from stack and 
compare data of popped node with currently visited node.
3.If all nodes matched, then return true, else false.

Runtime of this will be O(N)

```java
public static boolean isPalindrome(Node head) 
    {
        //Your code here
        Node current = head; 
        boolean ispalin = true; 
        Stack<Integer> stack = new Stack<Integer>(); 

        if(head.next == null){
            return true;
        }
  
        while (current != null) { 
            stack.push(current.data); 
            current = current.next; 
        } 
  
        while (head != null) { 
  
            int i = stack.pop(); 
            if (head.data == i) { 
                ispalin = true; 
            } 
            else { 
                ispalin = false; 
                break; 
            } 
            head = head.next; 
        } 
        return ispalin;
    }    
```

#### Driver For Solution

The coded solution [is available here.](./list-palindrome/driver.java)

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s2"/>

### 2. SOLUTION 2 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s3"/>

### 3. SOLUTION 3 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution 

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

<!-- Don't remove -->
Go to [Top](#top)
