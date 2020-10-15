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
