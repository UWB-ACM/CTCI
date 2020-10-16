<!-- Don't remove -->
<a name="top"/>

# Pointer Techniques

***Problems and solutions for Pointer Techniques session on October 16, 2020.***

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

### 1. Remove Duplicates from Sorted Array

Source: [LeetCode](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

#### Scenario

Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.
You must do this by modifying the input array in-place with O(1) extra memory.


**Note:**

The input array is passed in by reference, which means a modification to the input array will be known to the caller as well.

#### Example Input 1

```
Input: 
nums = [ 1, 1, 2 ]
Output: 
2
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned length.

```
#### Example Input 2
```
Input: 
nums = [ 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 ]

Output: 
Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

```

#### Function Signature

`int removeDuplicates(vector<int>& nums)`

<!-- Don't remove -->
Go to [Solution](#s1)   [Top](#top)

<!-- Don't remove -->
<a name="p2"/>

### 2. Linked List Cycle

Source: [LeetCode]https://leetcode.com/problems/linked-list-cycle/

#### Scenario

Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by 
continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node 
that tail's `next` pointer is conected to. **NOTE that** `pos` **is not passed as a parameter.**

#### Example Input
![githubSSTest](https://user-images.githubusercontent.com/56414351/96056908-9c6abe80-0e3c-11eb-82fd-4c6faeb2d3f4.PNG)

**Input:** head = [3,2,0,-4], pos = 1
**Output:** true
**Explanation:** There is a cycle in the linked list, where the tail connects to the 1st node (first index)

#### Function Signature

**C++:** `bool hasCycle(ListNode *head)`

**Java:** `public boolean hasCycle(ListNode head)`

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

### 1. Remove Duplicates from Sorted Array

[LeetCode](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

#### Optimal solution 

Utilizing fast and slow pointers.

Since the array is already sorted, we can keep two pointers, `left` and `right`, where `left` is the slow runner and `right` is the fast runner. As long as `nums[left] == nums[right]`, `right` will continue moving one element forward, skipping the duplicate. 

When we find that `nums[left] != nums[right]`, we have passed all duplicate numbers, then we need to copy the new, different value to `nums[left + 1]`. After the values has been copied, `left` and `right` move one element forward, until right reaches the end of the vector.


Example code of this implementation:
```c++
	int removeDuplicates(vector<int>& nums) {
        
        if (nums.size() == 0) {
            return 0;
        }
        
        //Pointer to the last, unique element in the array
        int left = 0;
        int right = 1; 
        int size = nums.size();
        
        //Iterate through the entire vector
        while (right < size) {
            
            if (nums[right] == nums[left]) {
                right++;
            } else {
                left++;
                nums[left] = nums[right];                
                right++;
            }
        }
        //return the total unique elements in the array
        return left + 1;
    }
```
The time complexity of this solution is O(n), where n =  the number of elements in the vector. The space complexity is O(1), since we are modifying the given array, avoiding allocating extra memory for another array.

#### Testing The Solutions OR Driver For Solution

[Click here for the C++ driver](./QuestionOne/driver.cpp)

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s2"/>

### 2. Linked List Cycle

Source: [LeetCode]https://leetcode.com/problems/linked-list-cycle/

#### O(n) space solution

**C++ Solution**

```
bool hasCycle(ListNode *head) {
    unordered_set<ListNode *> mySet;
    while (head) {
        if (mySet.find(head) != mySet.end()) {
            return true;
        mySet.insert(head);
        head = head->next;
    }
    return false;
}
```

**Java Solution**

We go through each node one by one and record each node's reference (or memory address)
in a hash table. If the current node is `null`, we have reached the end of teh list and
it must not be cyclic. If current node's reference is in the hash table, then return true.

Time Complexity: O(n). We visit each of the n elements in the list at most once. Adding
a node to the hash table costs only O(1) time.
Space Compexity: O(n). The space depends on the number of elements added to the hash table,
which contains at most n elements.

```
public boolean hasCycle(ListNode head) {
    Set<ListNode> nodesSeen = new HashSet<>();
    while (head != null) {
        if (nodesSeen.contains(head)) {
            return true;
        } else {
            nodesSeen.add(head);
        }
        head = head.next;
    }
    return false;
}
```

#### O(1) space solution

**C++ Solution**
```
bool hasCycle(ListNode* head) {
    ListNode *fast, *slow;
    fast = slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}
```

**Java Solution**

To solve this problem we can use a slow and fast pointer technique. This technique moves two pointers 
along our list at different paces. We move our slow pointer one node at a time (slow = slow.next) and 
we move our fast pointer two nodes at a time (fast = fast.next.next). If the list contains a cycle, 
then at some point slow and fast will meet. Otherwise, if the list does not contain a cycle, eventually 
fast will reach the end of our list and we can return accordingly based on these two possibilities.

Time Complexity: O(n). Where n is the number of nodes in our list.

Space Compexity: O(n). Or constant.

```
public boolean containsCycle(ListNode head) {
    ListNode slow = head;
    ListNode fast = head;
    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow == fast) {
            return true;
        }
    }

    return false;
}
```

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
