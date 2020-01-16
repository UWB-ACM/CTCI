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

TODO :bug:

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

Source: TODO :bug:

#### Naive/Simple Solution

TODO :bug:

PSUEDOCODE:
```
While in the bounds of the array
    Compare beginning slot to each other
    Increment until nums2 is smaller than nums1
    Push nums1 back
    Insert nums2 into spot
Return merged array
```

EXAMPLE CODE: TODO

Not time optimal, since you will have to push back n number of elements, n times, for each insert.

#### Alternate Solution

TODO: writeup
```
std::vector<int>& merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) 
{
  int backOfArray = nums1.size()-1;

  while(m-1 > 0)
  {
    if(nums1[m-1] < nums2[n-1])
    {
      nums1[backOfArray] = nums2[n-1];
      std::cout << n;
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

#### Optimal solution

TODO: writeup

```
std::vector<int>& merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) 
{
    //starter adding elements after the last one at m
    for(int i = m; i < nums1.size(); i++)
    {
        //i-m gives indexes 0 - end of nums 2 indexes
        
        nums1[i] = nums2[i-m];
    }
    sort(nums1.begin(), nums1.end());
  return nums1;
}
```


#### Testing The Solutions OR Driver For Solution

TODO :bug:
// Note[Erica] Will finish 1/17/2020

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
