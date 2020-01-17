<!-- Don't remove -->
<a name="top"/>

# Arrays & Sorting

Problems and solutions for Arrays & Sorting session on January 17, 2020.

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

### 1. Merge Sorted Array

Source: [LeetCode](https://leetcode.com/problems/merge-sorted-array/)

#### Scenario

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

**Note:**

- The number of elements initialized in nums1 and nums2 are m and n respectively.
- You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

#### Example Input

```
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
```

#### Function Signature

`std::vector<int>& merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)`

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

### 1. Merge Sorted Array

[LeetCode](https://leetcode.com/problems/merge-sorted-array/)

#### Naive/Simple Solution

A simple solution to the problem is expressed in the following psuedocode:
```
Create a tracker for nums2
For the length of the nums1 array
    Check if nums2 is smaller than nums1, or equal to nums1
    If yes
        Push all nums1 items from current position back one
        Insert nums2 into current posistion
        Increment current nums1 character counter
        Increment nums2 tracker
    Otherwise, go through the array until you reach end of nums1 character counter
        All nums2 larger than nums1 at this point
        Insert all nums2 at end
Return merged array
```
This solution is space optimal, with O(1) space. However, this solution is not time optimal. For each insertion operation you make, you will have to push back N number of objects, N number of times. This implementation would have a runtime of O(N^2)

Example code of this implementation:
```c++
std::vector<int> &merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
  int tracker = 0;
  
  for(int i = 0; i < nums1.size(); i++)
  {
    if(nums2[tracker] < nums1[i] || nums2[tracker] == nums1[i])
    {
      for(int k = m-1; k >= i; k--)
      {
        nums1[k+1] = nums1[k];
      }
    
      nums1[i] = nums2[tracker];
      m++;
      tracker++;
    }
    else if (i > m-1)
    {
      nums1[i] = nums2[tracker];
      tracker++;
    }
  }

  return nums1;
}
```


#### Optimal solution

A better solution can hit both the space requirements, while being time optimal. It requires starting from the back of the array, rather than stepping forward from the front, and is expressed in the following psuedocode:
```
Start from the back of the nums1 array

While the number of characters nums1 has stored is greater than 0
    Check if the last character of nums1 is smaller than nums2 last character
        If true, place nums2 last element in the back of the array
        Decrement nums2 character counter
        Set back of the array to be before the newly added character
    Otherwise, check if nums1 last character is bigger than nums2 last character
        If so, move nums1 last character to back of array
        Set nums1 previous position to 0
        Decrement nums1 character counter
        Set back of the array to be before the newly added character
    Otherwise, nums1 and nums 2 characters are the same
        Set back of array equal to nums2 last charact
        Decrement both nums1 and nums2 character counter
When all done, return the newly merge nums1

``` 

This implementation has a runtime of O(N), and space complexity of O(1). The full implementation in C++ is as follows:

```c++
std::vector<int>& merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) 
{
  int backOfArray = nums1.size()-1;

  while(m-1 > 0)
  {
    if(nums1[m-1] < nums2[n-1])
    {
      nums1[backOfArray] = nums2[n-1];
      n--;
      backOfArray--;
    }
    else if (nums1[m-1] > nums2[n-1])
    {
      nums1[backOfArray] = nums1[m-1];
      nums1[m-1] = 0;

      m--;
      backOfArray--;
    }
    else
    {
      nums1[backOfArray] = nums2[n-1];
      n--;
      m--;
      backOfArray--;
    }
  }
  return nums1;
}
```

#### Testing The Solutions OR Driver For Solution

The full solution to the optomized solution can be found at `CTCI/2020-01-Winter/0_arrays_sorting/Merge_Sorted_Arrays/mergeSortArr.cpp`.

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
