<!-- Don't remove -->
<a name="top"/>

# Linked List Manipulation

Practice solving linked list related problems. Session on May 1, 2020.

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

### 2. Remove Zero Sum Consecutive Nodes from Linked List

Source: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

#### Scenario

Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

(Note that in the examples below, all sequences are serializations of ListNode objects.)

#### Example Input
##### Example 1: <br>
```
Input: head = [1,2,-3,3,1]
Output: [3,1]
```
##### Example 2:<br>
```
Input: head = [5,-3,-4,1,6,-2,5]
Output: [5,-2,5]
```
#### Function Signature
##### C++:
```
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
ListNode* removeZeroSumSublists(ListNode* head) {
     // your code goes here

}
```
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
<details>
<summary>Click to see solution</summary>

TODO put your solution here :bug:

</details>


#### Optimal Solution

<details>
<summary>Click to see solution</summary>

TODO put your solution here :bug:

</details>

#### Testing The Solutions OR Driver For Solution

TODO :bug:

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s2"/>

### 2. Remove Zero Sum Consecutive Nodes from Linked List

#### Naive/Simple Solution
The idea is to locate the sublist of nodes that sum to 0 and de-list them.<br>
- Starting at the edging node, find lower-bound and upper-bound node of the sublist that sum to 0.
- if found, de-list nodes from [LBound, UBound], including by re-link PreLBound->next = UBound->next;
- If not found, move forward and check the next node.
For every i-th node of N nodes, the algorithm iterates from node i-th to the last node for the total of N*(N-i) times.
- This solution has time complexity of O(N<sup>2</sup>).

<details>
<summary>Click to see solution</summary>

```C++
ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode *Edge, *PreLBound, *UBound;
    // create edging node
    Edge= new ListNode(0);
    Edge->next = head;
    PreLBound = Edge;
    UBound = head;
    int Sum=0;
    while(UBound)
    {
        Sum = Sum + UBound->val;

        // if found zero sum range [LBound,UBound]
        // where LBound == PreLBound->Next;
        // then re-link from Prev to UBound->Next
        if(Sum == 0) {
            PreLBound->next = UBound->next;
        }
        UBound = UBound->next;
        // no zero-sum found in the range [Prev, End]
        // continue checking from [Prev->next, End]
        if(UBound == NULL)
        {
            PreLBound = PreLBound->next;
            // end of list
            if(PreLBound == NULL) break;
            UBound = PreLBound->next;
            Sum=0;
        }
    }
    // returning the result without the edging node
    return Edge->next;
}
```

</details>

#### Optimal Solution
One approach is to calculate the accumulated sum that is defined by Sum<sub>i</sub> = Sum <sub>i - 1</sub> + List <sub>i</sub> -> val. The accumulated Sum is tracked by using the hash table SumMap.
- if Sum is found in SumMap (accumulated Sum is repeated), this means there is a zero-sum range existing between the two nodes, then we remove all nodes between those two(s) and continue scanning until no zero-sum range found.
- if Sum is not repeated, this means there is NO zero-sum range existing between the two nodes, therefore, we will record the accumulated sum and examine the next node. <br>
- Instead of going through from (N-i) nodes for every i-th node explained in the previous solution, this solution uses a hash table to record the node before the zero-sum range and only goes through the list once.
- Time complexity of this solution is O(N). <br>

###### The following diagram illustrates how the algorithm works.

![Algorithm Illustration](2020-02-Spring/2_linked_lists/ZeroSumConsec/Algorithm_Illustration.png)

<details>
<summary>Click to see solution</summary>

```
ListNode* removeZeroSumSublists(ListNode* head) {
    // create edging node. Reason explained above.
    ListNode* Edge =new ListNode(0);
    Edge->next=head;
    // unordered map is faster with inserting/removing
    unordered_map<int,ListNode*> SumMap;
    SumMap[0] = Edge;
    int Sum = 0;

    while(head != nullptr){
        Sum += head->val;
        // if found zero-sum range: [LBound,head]
        // then delete from SumMap Sums recorded between [LBound,head]
        // then re-link from Prev to UBound->Next
        if(SumMap.find(Sum) != SumMap.end()) {
            ListNode* LBound = SumMap[Sum];
            ListNode* PreLBound = LBound;

            //delete Sums recorded in range [LBound, head]
            int subSum = Sum;
            while(LBound != head){
                LBound = LBound->next;
                subSum += LBound->val;
                if(LBound != head) SumMap.erase(subSum);
            }
            // remove nodes from Lbound to head
            PreLBound->next = head->next;
        } else {
            // if zero-sum range NOT exist
            // record Sum for further tracking
            SumMap[Sum] = head;
        }
        // examine next node
        head = head->next;
    }
    // returning the result without the edging node
    return Edge->next;
}
```

</details>

#### Driver For Solution

See [Driver](./ZeroSumConsec/ZeroSumConsec.cpp)

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s3"/>

### 3. SOLUTION 3 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution

<details>
<summary>Click to see solution</summary>

TODO put your solution here :bug:

</details>

#### Optimal Solution

<details>
<summary>Click to see solution</summary>

TODO put your solution here :bug:

</details>

#### Testing The Solutions OR Driver For Solution

TODO :bug:

<!-- Don't remove -->
Go to [Top](#top)
