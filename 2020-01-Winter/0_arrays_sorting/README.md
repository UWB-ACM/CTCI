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

### 2. Search in Rotated Sorted Array

Source: [LeetCode](https://leetcode.com/problems/search-in-rotated-sorted-array/)

#### Scenario


Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

#### Example Input 1
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

#### Example Input 2

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1


#### Function Signature
int search(vector<int>& nums, int target) {}


<!-- Don't remove -->
Go to [Solution](#s2)   [Top](#top)

<!-- Don't remove -->
<a name="p3"/>

### 3. Spiral Matrix

Source: [LeetCode](https://leetcode.com/problems/spiral-matrix/)

#### Scenario

Given an `M x N` sized matrix, return all elements in spiral order.

#### Example Input

```
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
```

#### Function Signature

**D**esign **I**t **Y**ourself

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

### 2. Search in Rotated Sorted Array

Source: [LeetCode](https://leetcode.com/problems/search-in-rotated-sorted-array/)

#### Optimal Solution

A good approach to this type of problem uses a **sliding window** approach
to conduct a binary search of the array.

A search window is initially declared as the entire array. The middle 
element of the search window is tested against the target value, and the 
search window is narrowed accordingly. The following tests are made:

* If the middle element contains the target, the index of the middle 
  element is returned. 
* If the middle element is larger than the leftmost element, then the 
  array's pivot is contained in the right half. The bounds of the left 
  half are compared to the target value; if the target value is contained 
  within those bounds, the window is narrowed to the left half of the 
  search window. Otherwise, it is narrowed to the right half of the 
  search window.
* Conversely, if the pivot is contained in the left half of the array, 
  the bounds of the right half of the array are compared against the 
  target value and the window is narrowed in a similar fashion.

Because the array is bisected with each search pattern, we have a solution 
which has a time complexity of `O(log N)`.
 
```c++
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            } else {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};
```

#### Testing The Solutions OR Driver For Solution

[The code and tests are provided in this repository.](./search_in_rotated/solution.cpp)

The test method is as follows:

```c++
int main()
{
    Solution test1;
    Solution test2;

    vector<int> testNumbers {4,5,6,7,0,1,2};
    vector<int> testNumbers2 {4,5,6,7,0,1,2};

    cout << test1.search(testNumbers, 0) << endl;
    cout << test2.search(testNumbers2, 3) << endl;
}
```

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s3"/>

### 3. Spiral Matrix

Source: [LeetCode](https://leetcode.com/problems/spiral-matrix/)

#### Solution Approach

In a spiral traversal, the elements at the matrix edges are visited first, 
and inner elements are visited later. It can be useful to think of the circular 
visitation pattern in terms of an _offset_. As successive inner loops of 
the spiral are traversed, the offset increases. Now, members to be visited 
are bounded by the matrix's edges plus the offset on either side. We use 
this information to determine when to change traversal direction in the 
spiral. 

#### Solution

The solution is given in Python.

```python3
def spiral_order(matrix):
    if not matrix or not matrix[0]: return []
    rows = len(matrix)
    cols = len(matrix[0])
    result = []
    i = j = 0       # indices; i corresponds to row# and j to col#
    diff = [0, 1]   # index incrementation values
    cycle = 0       # a count of the number of complete loops traversed so far
    # begin spiral traverse
    for cell in range(rows * cols):
        result.append(matrix[i][j])
        # check if cycle is terminating and new inner spiral is about to start
        # (also corresponds to end of bottom to top traversal in spiral)
        if diff == [-1, 0] and i - cycle == 1:
            cycle += 1
            diff = [0, 1]
        # check if row or col traversal exceeded bounds
        elif diff == [0, 1] and j + cycle >= cols - 1:
            # reached end of left to right traversal
            diff = [1, 0]
        elif diff == [1, 0] and i + cycle >= rows - 1:
            # reached end of top to bottom traversal
            diff = [0, -1]
        elif diff == [0, -1] and j - cycle == 0:
            # reached end of right to left traversal
            diff = [-1, 0]
        i += diff[0]
        j += diff[1]
    return result
```

#### Testing The Solutions

The full solution (including tests) is [available here](./spiral). 

The output for the Python solution is:

```console
Test 4x4 alphabet:
[
     ['a', 'b', 'c', 'd']
     ['e', 'f', 'g', 'h']
     ['i', 'j', 'k', 'l']
     ['m', 'n', 'o', 'p']
]
Result:  ['a', 'b', 'c', 'd', 'h', 'l', 'p', 'o', 'n', 'm', 'i', 'e', 'f', 'g', 'k', 'j']

Test 5x7 ints:
[
     [1, 2, 3, 4, 5]
     [6, 7, 8, 9, 10]
     [11, 12, 13, 14, 15]
     [16, 17, 18, 19, 20]
     [21, 22, 23, 24, 25]
     [26, 27, 28, 29, 30]
     [31, 32, 33, 34, 35]
]
Result:  [1, 2, 3, 4, 5, 10, 15, 20, 25, 30, 35, 34, 33, 32, 31, 26, 21, 16, 11, 6, 7, 8, 9, 14, 19, 24, 29, 28, 27, 22, 17, 12, 13, 18, 23]

Test 3x0 (empty) matrix:
[
     []
     []
     []
]
Result:  []
```

<!-- Don't remove -->
Go to [Top](#top)
