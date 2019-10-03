# Arrays and Sorting

Problems and solutions for the Arrays & Sorting session on October 4, 2019.

## Problems

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

### 2. PROBLEM 2 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

### 3. Sub Sort

Source: CTCI 16.16

#### Scenario

Given an array of integers, write a method to find indeces `m` and `n` 
such that if you sorted elements `m` through `n`, the entire array would 
be sorted. Minimize `n - m` (that is, find the smallest such sequence).

#### Example Input

Input: `[ 1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19 ]`
Output: `(3, 9)`

#### Function Signature

No function signature is provided as part of the problem statement.

In interviews, you are typically expected to design your own function 
signature and explain the reasoning behind your decision.

## Solutions

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

### 2. PROBLEM 2 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

### 3. Sub Sort

Source: CTCI 16.16

#### Solution

###### Steps

To solve this problem, we must find a starting point for our middle subarray 
which is unsorted. The easiest way to do this is to check the LHS and RHS 
subarrays for the longest fully sorted segment. (For now, we will not think about 
whether the LHS and RHS are sorted relative to each other.)

Having found two index markers for our inner, unsorted array (anywhere from 
two elements to the entire array minus two elements), we must determine what 
the largest and smallest elements in our unsorted array are. These two values 
will determine how far we have to expand the bounds into the LHS and RHS subarrays.

Then, we expand outwards, comparing our `unsorted_min` to `arr[lhs]` and decrementing `lhs` until `arr[lhs] <= unsorted_min`. Likewise, `unsorted_max` must be less than `arr[rhs]`.

###### Implementation

```java
public static int[] subsort(int[] array) {
    // edge case
    // if array is empty or length 1, no sorting is required. 
    // return -1 as indeces (or null, if the client can guarantee null checking)
    if (array.length <= 1) return new int[]{-1, -1};

    // find bounds for sorted LHS 
    int lhs = getSortedLhs(array);
    // if LHS spans entire array, we can return a minimal window of 0 length
    if (lhs >= array.length - 1) return new int[]{-1, -1};

    // find bounds for sorted RHS
    int rhs = getSortedRhs(array);
    // find min and max in center section
    int min = array[lhs];
    int max = array[rhs];
    for (int i = lhs; i <= rhs; i++) {
        if (array[i] < min) min = array[i];
        if (array[i] > max) max = array[i];
    }
    // Shrink LHS and RHS segments so that 
    // all LHS items are less than min and 
    // all RHS items are greater than max.
    while (lhs > 0 && array[lhs - 1] > min) lhs--;
    while (rhs < array.length - 1 && array[rhs + 1] < max) rhs++;

    return new int[]{lhs, rhs};
}

private static int getSortedLhs(int[] arr) {
    for (int i = 1; i < arr.length; i++)
        if (arr[i] < arr[i-1]) return i - 1;
    // because we move right, maximum bound is array's last idx
    return arr.length - 1;
}

private static int getSortedRhs(int[] arr) {
    for (int i = arr.length - 1; i > 0; i--)
        if (arr[i - 1] > arr[i]) return i;
    // because we move left, minimum bound is 0
    return 0;
}
```

#### Testing The Solutions 

[The java implementation is available here.](./subsort/Subsort.java)
