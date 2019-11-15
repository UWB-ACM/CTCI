<!-- Don't remove -->
<a name="top"/>

# Dynamic Programming & Math Puzzles

Problems and solutions for Math & Dynamic Programming session on November 15, 2019.

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

### 1. Climbing Stairs

Source: [LeetCode](https://leetcode.com/problems/climbing-stairs/) 
(2-stair variation) and CTCI 8.1 (3-stair variation).

#### Scenario

There is a staircase with `n` stairs. You can climb the stairs 1, 2, 
or 3 at a time. How many different unique combinations of steps can you 
take to reach the top of the stairs?

_Bonus: could you generalize this type of solution for different stair 
intervals, such as 2, 3, and 7 steps?_

#### Example Input

Input: `n = 3`

Output: `4`

Explanation: You could have any of the following ordered combinations 
of steps:

```
{ 3 },  { 2, 1 },  { 1, 2 },  { 1, 1, 1 }
```

#### Function Signature

C++:

```c++
int stepCombos(int n) {
    // your code here
}
```

Python:

```python3
def step_combos(n: int) -> int:
    # your code here
```

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

### 1. Climbing Stairs

Source: [LeetCode](https://leetcode.com/problems/climbing-stairs/) 
(2-stair variation) and CTCI 8.1 (3-stair variation).

#### Naive Solution

We solve this problem on paper as follows:

1. We start with `k` stairs where `k = n`.
2. We choose the first step we take (either 1, 2, or 3 stairs). We 
    subtract that number from `k`.
3. We repeat step 2 until `k` equals 0. At that point, we will 
    have climbed the entire staircase and found a unique pattern of 
    steps to take.
4. When we have solved the problem for each possible step iteration 
    at each step, we will have a way to determine how many combinations 
    of steps are possible.

This process can be written in code recursively as follows:

```python3
def step_combos_naive(n: int):
    if n < 0:
        # we have exceeded the number of steps in the staircase
        return 0
    if n == 0:
        # we have completed a unique stair pattern
        return 1
    return step_combos_naive(n - 1) + \
           step_combos_naive(n - 2) + \
           step_combos_naive(n - 3)
```

#### Memoization Solution

Working through an example like `n = 5`, we can see that there may be 
multiple times where `k = 3` must be solved multiple separate times. 
If we store the value of the recursive calls for any `k` we encounter, 
we can reference that result instead of solving the same subproblem 
multiple times.

The improved solution is given as follows:

```python3
def step_combos(n: int):
    combos = [0 for i in range(n)]
    return combos_helper(n, combos)

def combos_helper(n: int, combos: list):
    if n < 0:
        return 0
    if n == 0:
        return 1
    if combos[n - 1] == 0:
        val = combos_helper(n - 1, combos) + \
              combos_helper(n - 2, combos) + \
              combos_helper(n - 3, combos)
        combos[n - 1] = val
    return combos[n - 1]
```

#### Bonus

_Bonus: could you generalize this type of solution for different stair 
intervals, such as 2, 3, and 7 steps?_

The stair intervals we use are encoded in the recursive call 
declarations. We can calculate the unique step combinations for any 
step size of our choosing by changing the recursive calls' argument. 

If it was required, you could dynamically call the recursive function 
using values in an additional argument (such as a set or array).

#### Testing The Solutions

The Python [solution](./stairs/solution.py) and [driver](./stairs/driver.py) 
are included in this repository. The driver uses the `timeit` module 
to demonstrate the speedup of the dynamic programming solution.

The test output is as follows:

```console
$ python3 driver.py
Testing with n values: [3, 5, 6, 17]
Naive solution results: [4, 13, 24, 19513]
Dynamic programming solution results: [4, 13, 24, 19513]
Running timeit tests for the solutions.
Naive solution for 4 N and 10,000 repetitions: 110.048652 seconds
Dynamic programming solution for 4 N and 10,000 repetitions: 0.469553 seconds
```

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
