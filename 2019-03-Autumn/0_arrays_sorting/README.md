# Arrays and Sorting

Problems and solutions for the Arrays & Sorting session on October 4, 2019.

## Problems

### 1. Two Sum

Source: [leetcode](https://leetcode.com/articles/two-sum/)

#### Scenario:

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

#### Example Input

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

#### Function Signature:

Java:

```public int[] twoSum(int[] nums, int target) {}```

TODO :bug:

### 2. PROBLEM 2 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

### 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

## Solutions

### 1. PROBLEM 1: Two Sum

Source: [leetcode](https://leetcode.com/articles/two-sum/)

#### Solution 1 (Naive/Simple Solution):
Approach 1: Brute Force

The brute force approach is simple. Loop through each element 
`x` and find if there is another value that equals to `target−x`.

```
public int[] twoSum(int[] nums, int target) {
    for (int i = 0; i < nums.length; i++) {
        for (int j = i + 1; j < nums.length; j++) {
            if (nums[j] == target - nums[i]) {
                return new int[] { i, j };
            }
        }
    }
    throw new IllegalArgumentException("No two sum solution");
}
```
Complexity Analysis

Time complexity : `O(n^2)`. For each element, we try to find its complement by 
looping through the rest of array which takes `O(n)`
time. Therefore, the time complexity is `O(n2)`.

Space complexity : `O(1)`. 


#### Solution 2(Optimal Solution):
Approach 2: Two-pass Hash Table

To improve our run time complexity, we need a more efficient way to check if the complement exists in the array. 
If the complement exists, we need to look up its index. What is the best way to maintain a mapping of each element 
in the array to its index? A hash table.

We reduce the look up time from `O(n)` to `O(1)` by trading space for speed. A hash table is built exactly for this purpose,
it supports fast look up in near constant time. I say "near" because if a collision occurred, a look up could 
degenerate to `O(n)` time. But look up in hash table should be amortized `O(1)` time as long as the hash function was 
chosen carefully.

A simple implementation uses two iterations. In the first iteration, we add each element's value and its index to the 
table. Then, in the second iteration we check if each element's complement `(target−nums[i])` exists in the table. 
Beware that the complement must not be `nums[i]` itself!

```
public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        map.put(nums[i], i);
    }
    for (int i = 0; i < nums.length; i++) {
        int complement = target - nums[i];
        if (map.containsKey(complement) && map.get(complement) != i) {
            return new int[] { i, map.get(complement) };
        }
    }
    throw new IllegalArgumentException("No two sum solution");
}
```
Complexity Analysis:

Time complexity : `O(n)`. We traverse the list containing n elements exactly twice. Since the hash table reduces the look 
up time to `O(1)`, the time complexity is `O(n)`.

Space complexity : `O(n)`. The extra space required depends on the number of items stored in the hash table, which stores 
exactly `n` elements. 

#### Solution 3(Optimal Solution):
Approach 3: One-pass Hash Table

It turns out we can do it in one-pass. While we iterate and inserting elements into the table, we also look back to 
check if current element's complement already exists in the table. If it exists, we have found a solution and return 
immediately.

```
public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        int complement = target - nums[i];
        if (map.containsKey(complement)) {
            return new int[] { map.get(complement), i };
        }
        map.put(nums[i], i);
    }
    throw new IllegalArgumentException("No two sum solution");
}
```
Complexity Analysis:

Time complexity : `O(n)`. We traverse the list containing n elements only once. Each look up in the table costs only 
`O(1)` time.

Space complexity : `O(n)`. The extra space required depends on the number of items stored in the hash table, which stores
at most n elements.

#### Testing The Solutions OR Driver For Solution:
The executable Java solution for this problem is located under `Fall-2019/0_arrays_sorting/two_sum/TwoSumTest/Driver.java`.

The output for the Java solution is:

```Test Case #1
   input: [1, 2, 3, 4, 5]
   Target: 3
   Expected Output: [0, 1]
   
   After array and target passed to twoSum method...
   Output: [0, 1]
   
   Test Case #2
   input: [9, 4, -5, 2, 1]
   Target: 4
   Expected Output: [0, 2]
   
   After array and target passed to twoSum method...
   Output: [0, 2]
   
   Test Case #3
   input: [4, 3, 5, 1, 2]
   Target: 20
   Expected Output: Illegal Argument Exception: No Solution
   
   After array and target passed to twoSum method...
   Exception in thread "main" java.lang.IllegalArgumentException: No two sum solution
   ```

TODO :bug:

### 2. PROBLEM 2 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

## 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution 

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:
