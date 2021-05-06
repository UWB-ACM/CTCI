<!-- Don't remove -->
<a name="top"/>

# Topic Name TODO :bug:

Simple description TODO :bug:

In the style of:
***Problems and solutions for Maze & Dynamic Programming session on March 1, 2019.***

### Table of Contents

* [Problems](#problems)
  * [1](#p1)
  * [2. Letter Combinations of a Phone Number](#p2)
  * [3](#p3)
* [Solutions](#solutions)
  * [1](#s1)
  * [2. Letter Combinations of a Phone Number](#s2)
  * [3](#s3)

<!-- Don't remove -->
<a name="problems"/>

## Problems

<a name="p1"/>

### 1. Combination Sum

Source: [LeetCode] (https://leetcode.com/problems/combination-sum/)

#### Scenario

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

#### Example Input

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

#### Function Signature

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
    }
};

<!-- Don't remove -->
Go to [Solution](#s1)   [Top](#top)

<!-- Don't remove -->
<a name="p2"/>

### 2. Letter Combinations of a Phone Number

Source: [LeetCode] (https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

#### Scenario

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

#### Example Input

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

#### Function Signature

    public List<String> letterCombinations(String digits)

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

### 1. Combination Sum

Source: [LeetCode] (https://leetcode.com/problems/combination-sum/discuss/16496/Accepted-16ms-c%2B%2B-solution-use-backtracking-easy-understand.)

#### Solution

We can find the correct combinations by using a mix of iterative and recursive techniques while using a separate helper method. 

One vector is used to keep track of combinations that are attempted. A separate vector is used to keep track of correct combinations. 

#### Testing The Solutions OR Driver For Solution

TODO :bug:

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s2"/>

### 2. Letter Combinations of a Phone Number Solution

Source: [LeetCode] (https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

#### Naive/Simple Solution


#### Optimal Solution

First, we create a string array to map out the corresponding numbers and letters. Since "0" and "1" don't have any letters attached to them, they may be left as blank or simply filled with "0" and "1" in the array. We then use a helper method to help add combinations to our list. This helper method is recursive and works by appending the current letter to our current string until that string's length is the same as digits' length. Specifically, the helper method uses two variables - one to keep track of the length of the string and one to keep track of the current digit we're on. These are updated each iteration and allow for us to add all combinations using a single for loop that calls the helper method while adding the current letter to the current string.  
This backtracking method will look like this:
  
     int i = s.length();
     int digit = digits[i] - '0';
     for (char letter : dict[digit].toCharArray()) {
       backtrack(combos, digits, s + Character.toString(letter), dict);
     }
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
