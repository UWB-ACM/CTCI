<!-- Don't remove -->
<a name="top"/>

# Special Topics

***Problems and solutions for Special Topics session on December 11, 2020.***

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
