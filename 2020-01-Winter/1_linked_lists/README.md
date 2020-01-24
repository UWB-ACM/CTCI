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

Source: [LeetCode] (https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)

#### Scenario

You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.


#### Example Input

Example 1:

Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation:

The multilevel linked list in the input is as follows:
``
1---2---3---4---5---6---NULL
	|
	7---8---9---10---NULL
	    |
	    11--12---NULL
``

After flattening the multilevel linked list it becomes:

	1---2---3---7---8---11---12---9---10---4---5---6---NULL

Example 2:

Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation:

The input multilevel linked list is as follows:

  	1---2---NULL
  	|
  	3---NULL
  
 After flattening the multilevel linked list it becomes:
 
 	 1---3---2---NULL
	 
Example 3:

Input: head = []
Output: []

#### Function Signature

public Node flatten(Node head)

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

### 1. SOLUTION 1 TODO :bug:

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
<a name="s2"/>

### 2. SOLUTION 2 TODO :bug:

Source: [LeetCode](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)

#### Solution
In this solution, you first check the base case that the Linked List you call the flatten method on is not null. If it is you return the empty list. Otherwise you will use the tail node to travel to the tail of the first level of the list. You then begin traversing through the first level of the list until you reach the tail checking each node and whether or not they have a child node and thus another level to the list. If a second level is found move the level below in between current and current.next. Continue this until you have reached the tail node of the list.

```java

	public Node flatten(Node head) {
		/*Base case*/
		if (head == null) { 
			return head; 
		} 

		/* Find tail node of first level linked list */
		Node tail = head; 
		while (tail.next != null) { 
			tail = tail.next; 
		} 

		// One by one traverse through all nodes of first level 
		// linked list till we reach the tail node 
		Node current = head; 
		while (current != tail) { 
			

			// If current node has a child 
			if (current.child != null) { 
				// then link child in between current and current.next
				//store last link on next level as temp to connect to
				//current.next
				Node temp = current.child; 
				while (temp.next != null) { 
					temp = temp.next; 
				} 
				//break and create new links
				temp.next = current.next;
				current.next.prev = temp;
				current.next = current.child; 
				current.child.prev = current;
				current.child = null;
			} 

			// Change current node 
			current = current.next; 
		} 
		return head;
	}
```

#### Driver For Solution

[Driver](CTCI/2020-01-Winter/1_linked_lists/Flatten_Multilevel_Doubly_Linked_List/LinkeList.java)

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
