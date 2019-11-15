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

#### Optimized Solution

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
