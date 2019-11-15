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

### 2. Word Break

Source: [LeetCode](https://leetcode.com/problems/word-break/)

#### Scenario

Given a **non-empty** string s and a dictionary wordDict containing a list of 
**non-empty** words, determine if s can be segmented into a space-separated 
sequence of one or more dictionary words.

* Dictionary does not contain duplicate words.
* Same word may be used multiple times.

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

```java
boolean wordBreak(String s, List<String> wordDict) {
    // your code here
}
```

```python3
def word_break(s: str, wordDict: list) -> bool:
    # your code here
```

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

### 2. Word Break

Source: [LeetCode](https://leetcode.com/problems/word-break/)

#### Solution

```python3
def word_break(s: str, wordDict: list) -> bool:
    wordDict = set(wordDict)
    lengths = sorted(set(len(word) for word in wordDict))
    dp = set()
    dp.add(0)
    for i in range(1, len(s) + 1):
        for length in lengths:
            if i - length in dp and s[i - length: i] in wordDict:
                dp.add(i)
                break
    return len(s) in dp
```

#### Driver For Solution

The Python driver and solution is [here](./word_break/word_break.py).

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
