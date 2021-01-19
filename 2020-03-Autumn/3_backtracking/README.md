<!-- Don't remove -->
<a name="top"/>

# Backtracking

***Problems and solutions for Backtracking session on October 30, 2020.***

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

### 1. Palindrome Partitioning

Source: [LeetCode](https://leetcode.com/problems/palindrome-partitioning/)

#### Scenario

Given a string `s`, partition `s` such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of `s`.

#### Example

**Input:** `"aab"`

**Output:** 
```[
	["aa", "b"],
	["a", "a", "b"],
	]```

**Explanation:** 
Returns a list of all possible palindrome substrings of `s`.

#### Function Signature

**C++:** `vector<vector<string>> partition(string s)`

**Java:** ` public List<List<String>> partition(String s)`

<!-- Don't remove -->
Go to [Solution](#s1)   [Top](#top)

<!-- Don't remove -->
<a name="p2"/>

### 2. PROBLEM 2 Subsets

Source: [LeetCode](https://leetcode.com/problems/subsets/)

#### Scenario

Given an integer array nums, return all possible subsets (the power set).

The solution set must not contain duplicate subsets.

#### Example

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

#### Constraints

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

#### Function Signature

C++: vector<vector<int>> subsets(vector<int>& nums)
Java: public List<List<Integer>> subsets(int[] nums)

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

### 1. Subsets

Source: [LeetCode](https://leetcode.com/problems/palindrome-partitioning/)

#### Solution

We must generate all possible substrings of a string by partitioning at every index until we reach the end of the string. 
Example, `abba` can be partitioned as `["a","ab","abb","abba"]`. Each generated substring is considered as a potential candidate if it a Palindrome.


We can implement a DFS algorithm, where we expand a potential candidate until the defined goal is achieved. After that, we backtrack to explore our next potential candidate.

The backtracking algorithms consists of the following steps:

	1. Choose the potential candidate: All substrings that could be generated from the given string `s`
	2. Define a contraint that must be satisfed by the chosen candidate : The string must be a palindrome
	3. Define a goal to each and backtrack after that: Our goal is achieved if we have reach the end of the string
	
For this problem, we can traverse the string in the DFS fashion. For each recursive call:
	1. Iterively generate all possible substrings beginning at `start` index. The `end` index increments from `start` to the end of the string
	2. For each of the generated substrings, check is a palindrome
	3. If the substring is a palindrome, it is considered a potential candidate 
	4. Add the potential candidate to the `currList` and perform a DFS on the remaining substring, making sure to start at index `end + 1`
	5. If the goal is achieved (we have reached the end of the string `s`, or `start` index is greater than the length of string `s`), add the `currList` to `result` and backtrack.
	
```
C++ implementation:
    vector<vector<string>> partition(string s) {
        //The result to return
        vector<vector<string>> result;
        
        //Keeps track of the current candidate 
        vector<string> currList;
        
        //for the initial recursive call, we send the vector to return, the string to check for palindromes
        //The starting index, and the list holding current candidates
        dfs(result, s, 0, currList);
        return result;
    }
    
    void dfs(vector<vector<string>>& result, string& s, int start, vector<string>& currList) {
        //If we have reached the end of the string it means we have achieved our goal
        //Push the currList is a valid list of palindromes and return
        if (start >= s.length()) {
            result.push_back(currList);
            return;
        }
        
        //Generate all possible substrings beginning at index 'start'
        for (int end = start; end < s.length(); end++) {
            
            //if it is palindrome, add the potential candidate to the 'currList' and
            //Perform a DFS on the rest of the substring
            if (isPalindrome(s, start, end)) {
                
                //Add the current potential candidate to 'currList'
                currList.push_back(s.substr(start, end - start + 1));
                
                dfs(result, s, end + 1, currList); //Notice our 'start' index is the next char after the 'end' index
                
                //Backtrack and remove the recently added potential candidate
                currList.pop_back();
            }
        }
        
    }
    
    //Helper funtion checking if a string is palindrome
    bool isPalindrome(string &s, int left, int right) {
        
        while(left < right){
            
            if(s[left] != s[right]){
                
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
```

The time complexity of this solution is  O(N x 2^n). Where `N` is the lenght of the string `s`. This is the worst-case scenario, where all possible substrings are a palindrome.

The space complexity of this solution is O(N),where `N` is the length of the string `s`. This space will be used to store the recursion stack. 
	
#### Testing The Solutions OR Driver For Solution

[Click here for the C++ driver](./QuestionOne/driver.cpp)

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s2"/>

### 2. SOLUTION 2 TODO :bug:

Java Solution

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        
        List<List<Integer>> result = new ArrayList<List<Integer>> ();
        
        result.add(new ArrayList<Integer>());
                
        for (int i = 0; i < nums.length; i++) {
            // call recursion (backtracking) method 
            helper(result, new ArrayList<Integer>(), nums, i);
        }
        
        return result;
    }
    
    public void helper (List<List<Integer>> result, List<Integer> current, int[] nums, int index) {
        // if index hits the end of the list, return
        // because there are no more integers to add into current list
        if (index == nums.length) return;
                    
        // add index-th number into current list
        current.add (nums[index]);
        
        // current list into result list
        result.add (new ArrayList<Integer> (current));
        
        for (int i = index; i < nums.length; i++) {
            // call recursion (backtracking) method
            helper (result, current, nums, i+1);
        }
        
        // remove index-th number from current list
        current.remove (current.size()-1);
        
    }
}

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
