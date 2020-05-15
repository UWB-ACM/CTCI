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

### 1. Remove Nth Node From End of List

Source: [LeetCode](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

#### Scenario

Given a linked list, remove the n-th node from the end of list and return its head.

#### Example Input

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second to last node, the linked list becomes 1->2->3->5.

**Note:** Given n will always be valid.

**Optional:** Could you do this in one pass?

#### Function Signature

**Java:**

```java

//Definition for singly-linked list.
public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
    }
}

```

**Python:**

```python

#Definition for singly-linked list.
class ListNode:
  def __init__(self, x):
    self.val = x
    self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        
```
<!-- Don't remove -->
Go to [Solution](#s1)   [Top](#top)

<!-- Don't remove -->
<a name="p2"/>

### 2. Remove Zero Sum Consecutive Nodes from Linked List

Source: [LeetCode](https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/)

#### Scenario

Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences in the list.

After removing all consecutive nodes that sum to 0, print the final linked list (e.g. [1,2,1]). If all nodes are removed, print out an empty list (e.g. []).

(Note that in the examples below, all sequences are serializations of ListNode objects.)

#### Example Input
##### Example 1:
```
Input: head = [1,2,-3,3,0,1]
Output: [1,2,1]
```
##### Example 2:
```
Input: head = [5,-3,-4,1,6,-2,5]
Output: [5,-2,5]
```
#### Function Signature
```C++
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

### 3. Reorder List

Source: [LeetCode](https://leetcode.com/problems/reorder-list/)

#### Scenario

Given a singly linked list

![Starting linked list](https://github.com/UWB-ACM/CTCI/blob/3ec09954a8dfff8efc184dbb041e31656cb7ed68/2020-02-Spring/2_linked_lists/images/start_ll.gif)

Reorder it to: 

![Ending linked list](https://github.com/UWB-ACM/CTCI/blob/94bf9cc8b21e9feea21672a3bdcd78baa259d061/2020-02-Spring/2_linked_lists/images/end_ll.png)



You may **not** modify the values in the list's nodes. 
Only the pointers of the nodes may be changed.

#### Example Input

Given 1->2->3->4, reorder to 1->4->2->3.

Given 1->2->3->4->5, reorder to 1->5->2->4->3.

#### Function Signature

```java
// Definition for singly linked list
public class ListNode {
  int val;
  ListNode next;
  ListNode(int x) { val = x; }
}

void reorderList(ListNode head) {
  // Your code here
}
```

```cpp
// Definition for singly linked list
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
  ~ListNode() {
      delete next;
  }
};

void reorderList(ListNode* head) {
  // Your code here
}
```

<!-- Don't remove -->
Go to [Solution](#s3)   [Top](#top)

<!-- Don't remove -->
<a name="solutions"/>

## Solutions

<!-- Don't remove -->
<a name="s1"/>

### 1. Remove Nth Node From End of List

Source: [LeetCode](https://leetcode.com/problems/remove-nth-node-from-end-of-list/solution/)

#### Optimal Solution

<details>
<summary>Click to see solution</summary>

### One-Pass Algorithm

**Algorithm:**

We will use the two pointers approach for this problem. The first pointer advances the list by n+1 steps from the beginning, while the second pointer starts from the beginning of the list. Now, both pointers are exactly separated by n nodes apart. We maintain this constant gap by advancing both pointers together until the first pointer arrives past the last node. The second pointer will be pointing at the n-th node counting from the last. We relink the next pointer of the node referenced by the second pointer to point to the node's next next node:


![Algorithm ilustration](./remove_node_from_end/example.png)


**Java:**

```java

public ListNode removeNthFromEnd(ListNode head, int n) {
    ListNode dummy = new ListNode(0);
    dummy.next = head;
    ListNode first = dummy;
    ListNode second = dummy;
    // Advances first pointer so that the gap between first and second is n nodes apart
    for (int i = 1; i <= n + 1; i++) {
        first = first.next;
    }
    // Move first to the end, maintaining the gap
    while (first != null) {
        first = first.next;
        second = second.next;
    }
    second.next = second.next.next;
    return dummy.next;
}

```

**Complexity Analysis:**

- Time complexity : O(N).

- The algorithm makes one traversal of the list of N nodes. Therefore time complexity is O(N).

- Space complexity : O(1).

- We only used constant extra space.

</details>

#### Testing Driver For Solution

See [Driver](./remove_node_from_end/Driver.java)

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s2"/>

### 2. Remove Zero Sum Consecutive Nodes from Linked List

#### Naive/Simple Solution

<details>
<summary>Click to see solution</summary>

// NOTE: This solution does not take into account memory leaks. <br>
The idea is to use an outer loop iterating through N nodes, at every node i-th we use a nested loop iterating to the end of the list to check whether or not that node and the following nodes cause a zero-sum. The list of nodes causes zero-sum if "the accumulated sum of all nodes in that list equals zero". The inner loop stops as the accumulated sum equals 0 ``Sum == 0`` or it reaches the end of the list.
- If zero-sum list is found by the inner loop ``Sum == 0``, we remove nodes between [LBound, UBound] including the LBound node and the UBound node, where the node UBound is the node that the inner loop stopped at as the ``Sum == 0``.
- If ``Sum != 0``, the inner loop continues till the end of the list ``UBound == NULL``, which means there is no zero-sum found, then the outer loop will repeat the same searching process beginning at the next nodes till the end of the list.

For every i-th node of N nodes, the algorithm iterates from node i-th to the last node for the total of ``N*(N-i)`` times. Therefore, this solution has time complexity of ``O(N^2)``. Space complexity is ``O(1)``.

```c++

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

        // if  zero-sum list of nodes is found [LBound,UBound]
        // where LBound == PreLBound->Next;
        // then modify the list to remove nodes from LBound to UBound
        if(Sum == 0) {
            PreLBound->next = UBound->next;
        }
        UBound = UBound->next;
        // no zero-sum found in the range [Prev, End]
        // outer loop continues checking beginning at the next node
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
<details>
<summary>Click to see solution</summary>

// NOTE: This solution does not take into account memory leaks. <br>
Another approach is to check for the repetition of the accumulated sum that is defined by ``Sum = Sum + head->val``. Tracking the accumulated sum of each node is optimized by using the hash table ``map<int,NodeList*> SumMap``.

- If the accumulated sum at node ``head`` is found in ``SumMap`` (accumulated Sum is repeated), this means there is a zero-sum list between the two nodes ``[LBound, head]`` that needs to be removed. After removing the zero-sum list, make sure you reset the node before the ``LBound`` to the one after the ``head``.

- If ``Sum`` is not repeated (not found in SumMap), this means the current node is not contributing to the zero-sum list, the accumulated sum at the current is recorded ``SumMap[Sum] = head``, and the loop continues till the end of the list.

Instead of going through ``N-i`` nodes for every node i-th to calculate the accumulated sum that is explained in the first solution, this solution uses a hash table to record the accumulated sum of visited nodes and only goes through the list once. Time complexity of this solution is ``O(N)``. The space complexity of ``O(N)`` is the trade-off.

###### The following diagram illustrates how the algorithm works.

![Algorithm Illustration](./ZeroSumConsec/Algorithm_Illustration.png)

```c++

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
        // then re-link PrevLBound to head->Next
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


### 3. Reorder List Solution

<details>
<summary>Click to see solutions and solution explanation</summary>

#### Algorithm Overview

This problem is a combination of three common linked list manipulations:

* Finding the middle of a linked list
* Reversing a linked list
* Merging two linked lists


##### Finding the Middle of a Linked List

#### Naive/Simple Solution

<details>
<summary>Expand to see diagram</summary>

![Middle of Linked List Diagram](https://github.com/UWB-ACM/CTCI/blob/94bf9cc8b21e9feea21672a3bdcd78baa259d061/2020-02-Spring/2_linked_lists/images/find_middle_node.PNG)

</details>

##### Reversing the Second Half of the Linked List

<details>
<summary>Expand to see diagrams</summary>

![Start of reversing list](https://github.com/UWB-ACM/CTCI/blob/94bf9cc8b21e9feea21672a3bdcd78baa259d061/2020-02-Spring/2_linked_lists/images/reverse_start.PNG)

<details>
<summary>Step 1 of Reversing the List</summary>

![Reversing list step 1](https://github.com/UWB-ACM/CTCI/blob/94bf9cc8b21e9feea21672a3bdcd78baa259d061/2020-02-Spring/2_linked_lists/images/reverse_part_1.PNG)

</details>

<details>
<summary>Step 2 of Reversing the List</summary>

![Reversing list step 2](https://github.com/UWB-ACM/CTCI/blob/94bf9cc8b21e9feea21672a3bdcd78baa259d061/2020-02-Spring/2_linked_lists/images/reverse_part_2.PNG)

</details>

<details>
<summary>Step 3 of Reversing the List</summary>

![Reversing list step 3](https://github.com/UWB-ACM/CTCI/blob/94bf9cc8b21e9feea21672a3bdcd78baa259d061/2020-02-Spring/2_linked_lists/images/reverse_part_3.png)

</details>


![End of reversing list](https://github.com/UWB-ACM/CTCI/blob/94bf9cc8b21e9feea21672a3bdcd78baa259d061/2020-02-Spring/2_linked_lists/images/reverse_result.png)

</details>


##### Merging Two Linked Lists

<details>
<summary>Expand to see diagram</summary>

![Merging lists](https://github.com/UWB-ACM/CTCI/blob/94bf9cc8b21e9feea21672a3bdcd78baa259d061/2020-02-Spring/2_linked_lists/images/merge_sorted_lists.png)

</details>

##### Final Result

![Final result diagram](https://github.com/UWB-ACM/CTCI/blob/94bf9cc8b21e9feea21672a3bdcd78baa259d061/2020-02-Spring/2_linked_lists/images/reorder_list_final.PNG)


#### Complexity Analysis

* ***Time Complexity***: `O(N)`

    * O(N) - Finding the middle node of the linked list (N / 2 operations, which is asymptotically O(N))
    * O(N) - Reversing the second half of the linked list (N / 2 operations, which is asymptotically O(N))
    * O(N) - Merging the in-order list and reversed linked list (N / 2 operations, which is asymptotically O(N))

* ***Space Complexity***: `O(1)`

    * No new data structures are created. Only pointers are used to manipulate the nodes of the linked list. 


<details>
<summary>Click to see Java solution</summary>

```java

    public static void reorderList(ListNode head) {
        // Edge case handling
        if (head == null) return;
        
        // Find the middle node of the linked list
        // 1->2->3->4->5->6, find 4
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Reverse the second half of the linked list
        // 1->2->3->4->5->6 ----> 1->2->3->4, 6->5->4
        ListNode previous = null, current = slow, temp;
        while (current != null) {
            temp = current.next;
            current.next = previous;
            previous = current;
            current = temp;
        }

        // Merge the two linked lists
        // 1->2->3->4, 6->5->4 ----> 1->6->2->5->3->4
        ListNode first = head, second = previous;
        while (second.next != null) {
            temp = first.next;
            first.next = second;
            first = temp;

            temp = second.next;
            second.next = first;
            second = temp;
        }
    }

```

</details>



<details>

<summary>Click to see C++ solution with manual memory management</summary>

```cpp
void reorderList(ListNode *head) {
    // Find the middle element of the linked list
    // 1->2->3->4->5->6, find 4
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    // 1->2->3->4->5->6 ----> 1->2->3->4, 6->5->4
    ListNode *previous = nullptr, *current = slow, *temp;
    while (current) {
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }

    // Merge the two linked lists
    // 1->2->3->4, 6->5->4 ----> 1->6->2->5->3->4
    ListNode *first = head, *second = previous;
    while (second->next) {
        temp = first->next;
        first->next = second;
        first = temp;

        temp = second->next;
        second->next = first;
        second = temp;
    }
};

```
</details>


<details>
<summary>Click to see C++ solution with shared pointers</summary>

```cpp

void reorderList(std::shared_ptr<ListNode> head) {
    // Find the middle node of the linked list
    // 1->2->3->4->5->6, find 4
    std::shared_ptr<ListNode> slow = head, fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

     // Reverse the second half of the linked list
    // 1->2->3->4->5->6 ----> 1->2->3->4, 6->5->4
    std::shared_ptr<ListNode> previous = nullptr, current = slow, temp;
    while (current) {
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }

    // Merge the two linked lists
    // 1->2->3->4, 6->5->4 ----> 1->6->2->5->3->4
    std::shared_ptr<ListNode> first = head, second = previous;
    while (second->next) {
        temp = first->next;
        first->next = second;
        first = temp;

        temp = second->next;
        second->next = first;
        second = temp;
    }
};

```

</details>

#### Tests for Solution

##### Java 

See [the full solution file](./reorder_list/java/Solution.java) for helper methods.

```java

    public static void main(String[] args) {
        ArrayList<Integer> list1 = new ArrayList<>({1, 2, 3, 4});
        ListNode testCase1 = makeBasicList(list1);
        System.out.print("Before: ");
        printList(testCase1);
        reorderList(testCase1);
        
        System.out.print("After: ");
        printList(testCase1); // Expected: 1, 4, 2, 3

        ArrayList<Integer> list2 = new ArrayList<>({1, 2, 3, 4, 5});
        ListNode testCase2 = makeBasicList(list2);
        System.out.print("Before: ");
        printList(testCase2);
        reorderList(testCase2);
        
        System.out.print("After: ");
        printList(testCase2); // Expected: 1, 5, 2, 4, 3
    }

```

##### C++

See [the full solution file](./reorder_list/cpp/Solution_Manual.cpp) for helper methods.

```cpp

int main() {
    std::vector<int> vec{1, 2, 3, 4};
    ListNode* testCase1 = createBasicList(vec);
    std::cout << "Before: ";
    printList(testCase1);
    reorderList(testCase1);

    std::cout << "After: ";
    printList(testCase1); // Expected: 1, 4, 2, 3


    std::vector<int> vec2{1, 2, 3, 4, 5};
    ListNode* testCase2 = createBasicList(vec2);

    std::cout << "Before: ";
    printList(testCase2);
    reorderList(testCase2);

    std::cout << "After: ";
    printList(testCase2); // Expected: 1, 5, 2, 4, 3

    delete testCase1;
    delete testCase2;
}

```

</details>



<!-- Don't remove -->
Go to [Top](#top)
