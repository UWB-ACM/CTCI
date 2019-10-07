# Linked Lists

Problems and solutions for Linked List session on October 11, 2019.

## Problems

### 1. Intersection

Source: CTCI 2.7

#### Scenario
Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting node. Note that the intersection is defined based on reference, not value. That is, if the kth node of the first linked list is the exact same node (by reference) as the jth node of the second linked list, then they are intersecting.

#### Example Input

Input: [3, 1, 5, 9, 7, 2, 1] [4, 6, 7, 2, 1]
Output: 7

#### Function Signature

public LinkedListNode findIntersection(LinkedListNode list1, LinkedListNode list2) {
    // you code here
}

### 2. Partition

Source: CTCI 2.4

#### Scenario

Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x. If x is contained within the list, the values of x only need to be after the elements less than x. The partition element x can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions.

#### Example Input

Input: 3 --> 5 --> 8 --> 5 --> 10 --> 2 --> 1   [partition = 5]
Output: 3 --> 1 --> 2--> 10 --> 5 --> 5 --> 8

#### Function Signature

public LikedListNode partition(LinkedListNode node, int x) {
    // you code here
}

### 3. Merge K Sorted List

Source: LeetCode

#### Scenario

Merge K sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

#### Example Input

Input: 
[
    1 --> 4 --> 5
    1 --> 3 --> 4
    2 --> 6
]
Output: 1 --> 1 --> 2 --> 3 --> 4 --> 4 --> 5 --> 6

#### Function Signature

Java example:

public ListNode mergeKLists(ListNode[] lists) {
    // you code here
}

C++ example:

ListNode* mergeKLists(vector<ListNode*>& lists) {
    // you code here
}

## Solutions

### 1. Intersection

Source: CTCI 

#### Solution

Steps

1. Run through each linked list to get the lengths and the tails.
2. Compare the tails. If they are different (by regerence, not by value), return immediately. There is no intersection.
3. Set two pointers to the start of each linked list.
4. On the longer linked list, advance its pointer by the difference in lengths.
5. Now, traverse on each linked list until the pointers are the same. 

Implementation

public LinkedListNode<Integer> findIntersection(LinkedListNode list1, LinkedListNode list2) {
    if (list1 == list2 || list2 == null) {
        return null;
    }

//Get tail and sizes
    Result result1 = getTailAndSize(list1);
    Result result2 = getTailAndSize(list2);

 //If different tail nodes, then there's no intersection
    if (result1.tail != result2.tail) {
        return null;
    }

 //Set pointers to the start of each linked list
    LinkedListNode shorter = result1.size < result2.size ? list1 : list2;
    LinkedListNode longer = result1.size < result2.size ? list2 : list1;

 //Advance the pointer for the longer linked list by difference in lengths
    longer = getKthNode(longer, Math.abs(result1.size - result2.size));

 //Move both pointers until you have a collision
    while (shorter != longer) {
        shorter = shorter.next;
        longer = longer.next;
    }
    return longer;
}

#### Testing The Solutions OR Driver For Solution

TODO :bug:

### 2. Partition

Source: CTCI

#### Solution

Steps

We iterate through the linked list, inserting elements into our before list or our after list. Once we reach the end of the linked list and have completed this splitting, we merge the two lists.

This approach is mostly "stable" in that elements stay in their original order, other than the necessary movement around the partition. 

Implementation

// Pass in the head of the linked list and the value to partition around
public LinkedListNode partition(LinkedListNode node, int x) {
    LinkedListNode beforeStart = null;
    LinkedListNode beforeEnd = null;
    LinkedListNode afterStart = null;
    LinkedListNode afterEnd = null;
    
// Partition list
    while (node != null) {
        LinkedListNode next = node.next;
        node.next = null;
        if (node.data < x) {
        // Insert node into end of before list
        if (beforeStart == null) {
                beforeStart = node;
                beforeEnd = beforeStart;
            } else {
                beforeEnd.next = node;
                beforeEnd = node;
            }
        } else {
            // Insert node into end of after list
            if (afterStart == null) {
                afterStart = node;
                afterEnd = afterStart;
            } else {
                afterEnd.next = node;
                afterEnd = node;
            }
        }
        node = next;
    }
    if (beforeStart == null) {
        return afterStart;
    }

// Merge before list and after list
    beforeEnd.next = afterStart;
    return beforeStart;
}

#### Testing The Solutions OR Driver For Solution

TODO :bug:

### 3. Merge K Sorted Lists

Source: LeetCode

#### Naive/Simple Solution 

Approach 1: Brute Force
Intuition & Algorithm

Traverse all the linked lists and collect the values of the nodes into an array.
Sort and iterate over this array to get the proper value of nodes.
Create a new sorted linked list and extend it with the new nodes.

class Solution(object):
def mergeKLists(self, lists):
"""
:type lists: List[ListNode]
:rtype: ListNode
"""
self.nodes = []
head = point = ListNode(0)
for l in lists:
while l:
self.nodes.append(l.val)
l = l.next
for x in sorted(self.nodes):
point.next = ListNode(x)
point = point.next
return head.next

Complexity Analysis

Time complexity : O(NlogN) where NN is the total number of nodes.

Collecting all the values costs O(N) time.
A stable sorting algorithm costs O(NlogN) time.
Iterating for creating the linked list costs O(N) time.
Space complexity : O(N).

Sorting cost O(N) space (depends on the algorithm you choose).
Creating a new linked list costs O(N)O(N) space. 


#### Optimal Solution

Approach 2: Compare one by one
Algorithm

Compare every \text{k}k nodes (head of every linked list) and get the node with the smallest value.
Extend the final sorted linked list with the selected nodes.

Complexity Analysis

Time complexity : O(kN) where k is the number of linked lists.

Almost every selection of node in final linked costs O(k) k-1 times comparison).
There are NN nodes in the final linked list.
Space complexity :

O(n) Creating a new linked list costs O(n) space.
O(1) It's not hard to apply in-place method - connect selected nodes instead of creating new nodes to fill the new linked list. 

#### Optimal Solution
Approach 3: Optimize Approach 2 by Priority Queue
Algorithm

Almost the same as the one above but optimize the comparison process by priority queue. 

from Queue import PriorityQueue

class Solution(object):
def mergeKLists(self, lists):
"""
:type lists: List[ListNode]
:rtype: ListNode
"""
head = point = ListNode(0)
q = PriorityQueue()
for l in lists:
if l:
q.put((l.val, l))
while not q.empty():
val, node = q.get()
point.next = ListNode(val)
point = point.next
node = node.next
if node:
q.put((node.val, node))
return head.next

Complexity Analysis

Time complexity : O(Nlogk) where \text{k}k is the number of linked lists.

The comparison cost will be reduced to O(logk) for every pop and insertion to priority queue. But finding the node with the smallest value just costs) O(1) time.
There are NN nodes in the final linked list.
Space complexity :

O(n) Creating a new linked list costs O(n) space.
O(k) The code above present applies in-place method which cost O(1) space. And the priority queue (often implemented with heaps) costs O(k) space (it's far less than NN in most situations). 

#### Optimal Solution
Algorithm

Convert merge \text{k}k lists problem to merge 2 lists (\text{k-1}k-1) times. Here is the merge 2 lists problem page.

Complexity Analysis

Time complexity : O(kN) where k is the number of linked lists.

We can merge two sorted linked list in O(n) time where nn is the total number of nodes in two lists.
Sum up the merge process and we can get: O(\sum_{i=1}^{k-1} (i*(\frac{N}{k}) + \frac{N}{k})) = O(kN)O(∑ 
i=1
k−1
​    
​    (i∗( 
​    k
​    N
​    
​    )+ 
​    k
​    N
​    
​    ))=O(kN).
​    Space complexity : O(1)
​    
​    We can merge two sorted linked list in O(1) space. 

#### Testing The Solutions OR Driver For Solution

TODO :bug:


