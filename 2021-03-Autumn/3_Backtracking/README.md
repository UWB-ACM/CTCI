# Backtracking

## Table of Contents

### Problems
1. [Subsets II](https://leetcode.com/problems/subsets-ii/) (Medium)
2. [Permutations](https://leetcode.com/problems/permutations/) (Medium)
3. [Permutations II](https://leetcode.com/problems/permutations-ii/) (Medium)
4. [Combinations](https://leetcode.com/problems/combinations/) (Medium)
5. [Combination Sum](https://leetcode.com/problems/combination-sum/) (Medium)

## Problem 1

### Title:
[Subsets II](https://leetcode.com/problems/subsets-ii/) (Medium)

### Description:
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

### Example 1:
**Input:**  nums = [1,2,2] <br>
**Output:** [[],[1],[1,2],[1,2,2],[2],[2,2]]

<br>
<br>
<br>

## Problem 2

### Title:
[Permutations](https://leetcode.com/problems/permutations/) (Medium)

### Description:
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

### Example 1:
**Input:**  nums = [1,2,3] <br>
**Output:** [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

<br>
<br>
<br>

## Problem 3

### Title:
[Permutations II](https://leetcode.com/problems/permutations-ii/) (Medium)

### Description:
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

### Example 1:
**Input:**  nums = [1,1,2] <br>
**Output:** [[1,1,2], [1,2,1], [2,1,1]]

<br>
<br>
<br>

## Problem 4

### Title:
[Combinations](https://leetcode.com/problems/combinations/) (Medium)

### Description:
Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.

### Example 1:
**Input:**  n = 4, k = 2 <br>
**Output:** [[2,4], [3,4], [2,3], [1,2], [1,3], [1,4],]

<br>
<br>
<br>

## Problem 5

### Title:
[Combination Sum](https://leetcode.com/problems/combination-sum/) (Medium)

### Description:
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

### Example 1:
**Input:**  candidates = [2,3,6,7], Target = 7 <br>
**Output:** [[2,2,3],[7]] <br>
**Explanation:** 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

<br>
<br>
<br>

# Solutions

## Solution 1

### Backtracking:

**Approach**
1. First, sort the array in ascending order.
2. Use a recursive helper function subsetsWithDupHelper to generate all possible subsets. The subsetsWithDupHelper has the following parameters:
  - Output list of subsets (subsets).
  - Current subset (currentSubset).
  - nums array.
  - the index in the nums array from where we should start scanning elements at that function call (index).
3. At each recursive function call:
  - Add the currentSubset to the subsets list.
  - Iterate over the nums array from index to the array end.
    - If the element is considered for the first time in that function call, add it to the currentSubset list. Make a function call to subsetsWithDupHelper with index = current element position + 1.
    - Otherwise, the element is a duplicate. So we skip it as it will generate duplicate subsets (refer to the figure above).
    - While backtracking, remove the last added element from the currentSubset and continue the iteration.
4. Return subsets list.

```
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> subsets = new ArrayList<>();
        List<Integer> currentSubset = new ArrayList<>();

        subsetsWithDupHelper(subsets, currentSubset, nums, 0);
        return subsets;
    }

    private void subsetsWithDupHelper(List<List<Integer>> subsets, List<Integer> currentSubset, int[] nums, int index) {
        // Add the subset formed so far to the subsets list.
        subsets.add(new ArrayList<>(currentSubset));

        for (int i = index; i < nums.length; i++) {
            // If the current element is a duplicate, ignore.
            if (i != index && nums[i] == nums[i - 1]) {
                continue;
            }
            currentSubset.add(nums[i]);
            subsetsWithDupHelper(subsets, currentSubset, nums, i + 1);
            currentSubset.remove(currentSubset.size() - 1);
        }
    }
}
```
<br>
<br>

## Solution 2

### Backtracking:

**Approach**
1. If the first integer to consider has index n that means that the current permutation is done.
2. Iterate over the integers from index first to index n - 1.
    - Place i-th integer first in the permutation, i.e. swap(nums[first], nums[i]).
    - Proceed to create all permutations which starts from i-th integer : backtrack(first + 1).
    - Now backtrack, i.e. swap(nums[first], nums[i]) back.
```
class Solution {
  public void backtrack(int n,
                        ArrayList<Integer> nums,
                        List<List<Integer>> output,
                        int first) {
    // if all integers are used up
    if (first == n)
      output.add(new ArrayList<Integer>(nums));
    for (int i = first; i < n; i++) {
      // place i-th integer first 
      // in the current permutation
      Collections.swap(nums, first, i);
      // use next integers to complete the permutations
      backtrack(n, nums, output, first + 1);
      // backtrack
      Collections.swap(nums, first, i);
    }
  }

  public List<List<Integer>> permute(int[] nums) {
    // init output list
    List<List<Integer>> output = new LinkedList();

    // convert nums into list since the output is a list of lists
    ArrayList<Integer> nums_lst = new ArrayList<Integer>();
    for (int num : nums)
      nums_lst.add(num);

    int n = nums.length;
    backtrack(n, nums_lst, output, 0);
    return output;
  }
}
```
<br>
<br>

## Solution 3

### Backtracking:

**Approach**
1. Given the above insight, in order to find out all the unique numbers at each stage, we can build a hash table (denoted as counter), with each unique number as the key and its occurrence as the corresponding value.
2. To implement the algorithm, first we define a function called backtrack(comb, counter) which generates all permutations, starting from the current combination (comb) and the remaining numbers (counter).
3. Once the function is implemented, it suffices to invoke the function with the initial empty combination and the hash table we built out of the input array, to solve the problem.

```
class Solution {

    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();

        // count the occurrence of each number
        HashMap<Integer, Integer> counter = new HashMap<>();
        for (int num : nums) {
            if (!counter.containsKey(num))
                counter.put(num, 0);
            counter.put(num, counter.get(num) + 1);
        }

        LinkedList<Integer> comb = new LinkedList<>();
        this.backtrack(comb, nums.length, counter, results);
        return results;
    }

    protected void backtrack(
            LinkedList<Integer> comb,
            Integer N,
            HashMap<Integer, Integer> counter,
            List<List<Integer>> results) {

        if (comb.size() == N) {
            // make a deep copy of the resulting permutation,
            // since the permutation would be backtracked later.
            results.add(new ArrayList<Integer>(comb));
            return;
        }

        for (Map.Entry<Integer, Integer> entry : counter.entrySet()) {
            Integer num = entry.getKey();
            Integer count = entry.getValue();
            if (count == 0)
                continue;
            // add this number into the current combination
            comb.addLast(num);
            counter.put(num, count - 1);

            // continue the exploration
            backtrack(comb, N, counter, results);

            // revert the choice for the next exploration
            comb.removeLast();
            counter.put(num, count);
        }
    }
}
```
<br>
<br>

## Solution 4

### Backtracking:

**Approach**
- If the current combination is done - add it to output.
- Iterate over the integers from first to n.
  - Add integer i into the current combination curr.
  - Proceed to add more integers into the combination : backtrack(i + 1, curr).
  - Backtrack by removing i from curr.
```
class Solution {
  List<List<Integer>> output = new LinkedList();
  int n;
  int k;

  public void backtrack(int first, LinkedList<Integer> curr) {
    // if the combination is done
    if (curr.size() == k)
      output.add(new LinkedList(curr));

    for (int i = first; i < n + 1; ++i) {
      // add i into the current combination
      curr.add(i);
      // use next integers to complete the combination
      backtrack(i + 1, curr);
      // backtrack
      curr.removeLast();
    }
  }

  public List<List<Integer>> combine(int n, int k) {
    this.n = n;
    this.k = k;
    backtrack(1, new LinkedList<Integer>());
    return output;
  }
}
```
<br>
<br>

## Solution 5

### Backtracking:

**Approach**
1. For the first base case of the recursive function, if the remain==0, i.e. we fulfill the desired target sum, therefore we can add the current combination to the final list.
2. As another base case, if remain < 0, i.e. we exceed the target value, we will cease the exploration here.
3. Other than the above two base cases, we would then continue to explore the sublist of candidates as [start ... n]. For each of the candidate, we invoke the recursive function itself with updated parameters.
    - Specifically, we add the current candidate into the combination.
    - With the added candidate, we now have less sum to fulfill, i.e. remain - candidate.
    - For the next exploration, still we start from the current cursor start.
    - At the end of each exploration, we backtrack by popping out the candidate out of the combination.
 
```
class Solution {

    protected void backtrack(
            int remain,
            LinkedList<Integer> comb,
            int start, int[] candidates,
            List<List<Integer>> results) {

        if (remain == 0) {
            // make a deep copy of the current combination
            results.add(new ArrayList<Integer>(comb));
            return;
        } else if (remain < 0) {
            // exceed the scope, stop exploration.
            return;
        }

        for (int i = start; i < candidates.length; ++i) {
            // add the number into the combination
            comb.add(candidates[i]);
            this.backtrack(remain - candidates[i], comb, i, candidates, results);
            // backtrack, remove the number from the combination
            comb.removeLast();
        }
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> results = new ArrayList<List<Integer>>();
        LinkedList<Integer> comb = new LinkedList<Integer>();

        this.backtrack(target, comb, 0, candidates, results);
        return results;
    }
}
```
<br>
<br>
