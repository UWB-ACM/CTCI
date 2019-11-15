<!-- Don't remove -->
<a name="top"/>

# Dynamic Programming & Math Puzzles

Problems and solutions for Math & Dynamic Programming session on November 15, 2019.

### Table of Contents

* [Problems](#problems)
  * [1](#p1)
  * [2](#p2)
* [Solutions](#solutions)
  * [1](#s1)
  * [2](#s2)

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

### 2. Word Break

Source: [LeetCode](https://leetcode.com/problems/word-break/)

#### Scenario

Given a **non-empty** string `s` and a dictionary `wordDict` containing a list of 
**non-empty** words, determine if `s` can be segmented into a space-separated 
sequence of one or more dictionary words.

* Dictionary does **not** contain duplicate words.
* Same word may be used *multiple* times.

#### Example Input

```
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
```

```
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
```

#### Function Signature

C++:

```c++
bool wordBreak(string s, vector<string>& wordDict) {
    // your code here
}
```

Python:

```python3
def word_break(s: str, wordDict: list) -> bool:
    # your code here
```

<!-- Don't remove -->
Go to [Solution](#s2)   [Top](#top)

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

### 2. Word Break

Source: [LeetCode](https://leetcode.com/problems/word-break/)

#### Naive Approach

A naive approach would be to start from index `0`, check if the substrings 
`s[0:1]` through `s[0:length of s]` is in `wordDict`. If a match is found, call 
the function recursively but to start at the index where the previous match was 
found. The function returns **true** up the call stack if `s[x:length of s]` is 
in `wordDict`. Otherwise we would return **false** and continue the search until 
`s[0:length of s]` is not found in `wordDict`, then the search terminates and 
**false** is returned.

#### Memoization Solution

We can leverage a memo to store indices each time we find a word match in the 
sequence. As we loop through the sequence, we need to compare the substrings 
**only** if the *`current index`* **-** *`word length`* is marked previously.

For instance:  
`Input: s = "applepenapple", wordDict = ["apple", "pen"]`  
* At index `3`, the check for *`current index`* **-** *`word length`* becomes 
`true` (`0` is marked, since the start of the sequence is a valid starting 
location for a word to insert), so we take the substring `s[0:3]` (***'app'***) 
and check if it's in the dictionary. It is not, so `3` isn't marked.
* At index `5`, the check becomes `true` again. We check if `s[0:5]` 
(***'apple'***) is in the dictionary. It is, so we mark `5`.
* At index `8`, the check `___`(fill it in yourself). We then check if 
`s[?:8]`(what is `?`) (***'pen'***) is in `___`. It `___`, so we `___`.
* And so on...
* Finally, we check if the length of the sequence is marked. If it is we return 
`true`, otherwise we return `false`.

Here's the solution in Python:

```python3
def word_break(s: str, wordDict: list) -> bool:
    wordDict = set(wordDict)    # fast lookup
    lengths = sorted(set(len(word) for word in wordDict))   # limit search range
    dp = set()  # memo
    dp.add(0)   # starting index
    for i in range(1, len(s) + 1):  # iterate range [1, length of s]
        for length in lengths:
            if i - length in dp and s[i - length: i] in wordDict:
                dp.add(i)   # mark new match
                break
    return len(s) in dp
```

**Note:** While this solution is sufficient for more general cases, inputs such 
as `s = "abbbbbbbbbbbbbbb...", wordDict = ["a"]` causes unnecessary work to be 
done since we don't need to check further after we couldn't find a match at 
index `2`. Time complexity doesn't change in any case.

#### Driver For Solution

The Python driver and solution is [here](./word_break/word_break.py).

<!-- Don't remove -->
Go to [Top](#top)
