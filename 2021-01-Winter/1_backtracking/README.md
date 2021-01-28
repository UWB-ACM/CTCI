<!-- Don't remove -->
<a name="top"/>

# Topic Name TODO :bug:

Simple description TODO :bug:

In the style of:
***Problems and solutions for Maze & Dynamic Programming session on March 1, 2019.***

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

### 2. Subsets

Source: [LeetCode](https://leetcode.com/problems/subsets/)

#### Scenario

Given an integer array nums, return all possible subsets (the power set).
The solution set must not contain duplicate subsets.

#### Example Input

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

```
C++: vector<vector<int>> subsets(vector<int>& nums)
Java: public List<List<Integer>> subsets(int[] nums)
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

### 2. SOLUTION 2
Time Complexity: O(2^N) where N is the length of the Array nums.

Java Solution:

```
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        
        List<List<Integer>> result = new ArrayList<List<Integer>> ();
        
        // add empty list
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
```


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
