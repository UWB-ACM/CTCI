<!-- Don't remove -->
<a name="top"/>

# Sliding Window

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

### 1. Max Consecutive Ones

Source: [LeetCode](https://leetcode.com/problems/max-consecutive-ones/)

#### Scenario

Given a binary array, find the maximum number of consecutive 1s in this array.

Note that the input array will only contain `0` and `1`.

#### Example Input

**Input:** `[1,1,0,1,1,1,0,1,0]`

**Output:** 3

**Explanation:** 
The first two digits or the last three digits are consecutive 1s.

The maximum number of consecutive 1s is 3.

#### Function Signature

**C++:** `int findMaxConsecutiveOnes(vector<int>& nums)`

**Java:** `int findMaxConsecutiveOnes(int[] nums)`

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

### 1. Max Consecutive Ones

Source: [LeetCode](https://leetcode.com/problems/max-consecutive-ones/)

#### Brute Force Solution

The direct solution would go through the array, find the first 1, and 
start counting all 1s after it until the cursor reaches 0. This solution
works, however, leads to very bad time complexity (O(N^2)).

```
int findMaxConsecutiveOnes(vector<int>& nums) {
    int max = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 1) {
            for (int j = i; j < nums.size(); ++j){
                if (nums[j] == 1) {
                    count++;
                } else {
                    max = std::max(count, max);
                    count = 0;
                    break;
                }
            }
        }
    }
    return max;
}
```


#### Better Solution

At the first glance of this question, we can see that the program wants to 
count the most 1s that are grouped together. As we go through the binary 
array, we can count along the way: If it is a 0, we would stop counting 
and reset the counter to 0. Otherwise, we would increment the counter by 1. 
The maximum number of the counter will always be stored in a variable called 
`max`. (Time complexity: O(N))

```
int findMaxConsecutiveOnes(vector<int>& nums) {
    int max = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 1) {
            count++;
            max = std::max(count, max);
        } else {
            count = 0;
        }
    }
    return max;
}
```

#### Optimal Solution

Instead of counting the maximum numbers of 1s in a group, we can also define 
where the group is for faster calculation. In the following solution, the 
program uses two indices to keep track of the start and the end of a group 
of 1s. This is called the "Sliding window" technique. You can move this 
window around while going through the binary array, checking its value and 
update the maximum variable. (Time complexity: O(N))

```
int findMaxConsecutiveOnes(vector<int>& nums) {
    int start = 0;
    int end = 0;
    int max = 0;
    while (end < nums.size()) {
        while (end < nums.size() && nums[end] == 1)
            end++;
        max = std::max(end - start, max);
        end++;
        start = end;
    }
    return max;
}
```

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
