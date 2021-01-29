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

### 1. Permutations

Source: Source: [LeetCode](https://leetcode.com/problems/permutations/)

#### Scenario

Given an array `nums` of distinct integers, return all the possible permutations. You can return the answer in any order.

#### Example

**Input:** `nums = [1,2,3]`

**Output:** `[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]`

**Explanation:** 
Returns a list of all possible permutations of `nums`.

#### Function Signature
**Java:** `public List<List<Integer>> permute(int[] nums)`

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

### 1. Permutations

Source: [LeetCode](https://leetcode.com/problems/permutations/)

#### Solution

This solution puts the original array as an argument into 
the backtrack method, which creates a list of ints from the 
original array by using a for loop that adds the elements of 
the array in order, one at a time, while checking to see if 
each element is already in the array. If it is already in
the array, it's skipped and the for loop goes to the next
iteration. Then it puts this list as an argument back into 
the backtrack method, which checks to see if the list is 
the same length as the original array. If it is, it’s added 
to the final list that’s going to be returned. 

Then the backtrack method creates the next list of ints by 
removing elements from the previous list, one at a time, because 
the previous list is full. The current for loop iteration changes the order 
that the elements are added so they aren’t consecutive like in 
the original array, because the method took in a full list, 
and the first list/original array copy list started the process 
with an empty list. It repeats the steps of adding a current 
list to the final list when the current list is full, until 
all permutated lists are found.

```
Java implementation:
class Solution { 
    public List<List<Integer>> permute(int[] nums) {
        //Create final list to be returned
        List<List<Integer>> list = new ArrayList<>();

        //Call backtrack function
        backtrack(list, new ArrayList<>(), nums);

        //Return final list
        return list;
}

private void backtrack(List<List<Integer>> list, List<Integer> tempList, int [] nums) {
    //Add current list to final list if same length as original array
    if(tempList.size() == nums.length) {
        list.add(new ArrayList<>(tempList));
    } 
    else {
        for(int i = 0; i < nums.length; i++) {
            //If element already exists, skip
            if(tempList.contains(nums[i])) continue;
            tempList.add(nums[i]);
            backtrack(list, tempList, nums);
            tempList.remove(tempList.size() - 1);
        }
    }
} 
}
```

The time complexity of this solution is O(2^N). Where `N` is the length of the array `nums`. This is the worst-case scenario, because all permutations need to be found.

The space complexity of this solution is O(N),where `N` is the length of the string `nums`. This space will be used to store the recursion stack. 

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
