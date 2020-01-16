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
