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

### 2. Minimum Swaps to Group All 1's Together

Source: [GeeksforGeeks](https://www.geeksforgeeks.org/minimum-swaps-required-group-1s-together/)

#### Scenario

Given an array of **0’s** and **1’s**, we need to write a program to find the 
**minimum** number of swaps required to group all 1’s present in the array 
together.

#### Example Input

Input: `[1, 0, 1, 0, 1]`  
Output: `1`  
Explanation `swap a[1] and a[4] results in [1, 1, 1, 0, 0]`

#### Function Signature

Python example:

```python
def min_swaps(array):
    # your code here
```

Java example:

```java
public int minSwaps(int[] array) {
    // your code here
}
```

### 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

## Solutions

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

### 2. Minimum Swaps to Group All 1's Together

Source: [GeeksforGeeks](https://www.geeksforgeeks.org/minimum-swaps-required-group-1s-together/)

#### Naive/Simple Solution

##### Steps

Our goal is to (somehow) swap the 1's in the array so that all of the 1's are 
next to each other. So, we can think in reverse and figure out the thing we are 
looking for is the subarray with length *`1's count`* that already contains the 
most 1's (aka the destination). The count of 0's in that subarray will then be 
the minimum swaps required.

##### Implementation

```python
def min_swaps_naive(array):
    # count total number of 1's
    total_count = 0
    for num in array:
        if num == 1:
            total_count += 1
    
    max_count_in_subarray = 0
    # iterate thru `len(array) - total_count + 1` subarrays
    for i in range(len(array) - total_count + 1):
        
        one_count = 0

        # count number of 1's in a subarray
        for j in range(total_count):
            if array[i + j] == 1:
                one_count += 1
        
        if one_count > max_count_in_subarray:
            max_count_in_subarray = one_count

    # count of 0's is the actual answer
    return total_count - max_count_in_subarray
```

#### Optimal Solution

##### Steps

Optimize the naive solution using the **sliding window** approach. We first 
count the number of 1's in the first subarray. Then we just advance the right 
and left side of the window, adding the right element to `running_count` and 
subtracting the left element from `running_count` followed by a check for max. 
This approach improves by cutting down the number of times of inspecting each 
element of the array.

##### Implementation

```python
def min_swaps_efficient(array):
    # count total number of 1's
    total_count = 0
    for num in array:
        if num == 1:
            total_count += 1

    running_count = 0
    # need to count the first subarray
    for i in range(total_count):
        if array[i] == 1:
            running_count += 1
    
    max_count_in_subarray = running_count
    
    # sliding window
    left = 0
    right = total_count
    while right < len(array):

        if array[left] == 1:
            running_count -= 1
        if array[right] == 1:
            running_count += 1

        if running_count > max_count_in_subarray:
            max_count_in_subarray = running_count
        left += 1
        right += 1

    return total_count - max_count_in_subarray
```

An implementation in Python which makes use of language features and compresses 
some of the verbosity of the optimal solution is as follows:

```python
def min_swaps_pythonic(array):
    total_count = array.count(1)
    running_count = array[:total_count].count(1)
    max_count_in_subarray = running_count
    for left, right in zip(array, array[total_count:]):
        running_count += right - left
        max_count_in_subarray = max(max_count_in_subarray, running_count)
    return total_count - max_count_in_subarray
```

#### Time Complexity

The naive solution has a **best case of `O(n)`** in cases of 1 `1` and all `1`'s; 
however, if half of the elements are `1's`, time complexity becomes the **worst 
case of `O(n^2)`**.
The average case would be `O(n^2)`.

`(n/2 elements per subarray) * (n/2 + 1 subarrays) = (n^2 + 2n)/4 = O(n^2)`

The efficient solution **maintains `O(n)`** for the worst case, since we adopted the 
sliding window approach, every element will only be accessed at most twice 
during calculation of `running_count`.

#### Testing The Solutions

[The python implementation is available here.](./min-group1s/min-group1s.py)

## 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution 

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:


