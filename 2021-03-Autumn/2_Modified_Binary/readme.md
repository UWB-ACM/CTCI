# Modified Binary

## Table of Contents

### Problems
1. [Find the Smallest Divisor Given a Threshold](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/) (Medium)
2. [Sum of Mutated Array Closest to Target](https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/) (Medium)
3. [Minimum Number of Days to Make m Bouqets](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/) (Medium)
4. [Find Peak Element](https://leetcode.com/problems/find-peak-element/) (Medium)
5. [Missing Element in Sorted Array](https://leetcode.com/problems/missing-element-in-sorted-array/) (Medium)
6. [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) (Medium)

## Problem 1

## Problem 2 (Medium)

### Title:
[Sum of Mutated Array Closest to Target](https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/) (Medium)

### Description:
Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.

In case of a tie, return the minimum such integer.

Notice that the answer is not neccesarilly a number from arr.

### Example:
**Input:** arr = [4,9,3], Target = 10 <br>
**Output:** 3 <br>
**Explanation:** When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.
<br>
<br>
<br>

## Problem 3 

## Problem 4

### Title:
[Find Peak Element](https://leetcode.com/problems/find-peak-element/) (Medium)

### Description:
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.

### Example:
**Input:** nums = [1,2,3,1] <br>
**Output:** 2 <br>
**Explanation:** 3 is a peak element and your function should return the index number 2.
<br>
<br>
<br>

## Problem 5

### Title:
[Missing Element in Sorted Array](https://leetcode.com/problems/missing-element-in-sorted-array/) (Medium)

### Description:
Given an integer array nums which is sorted in ascending order and all of its elements are unique and given also an integer k, return the kth missing number starting from the leftmost number of the array.

### Example:
**Input:** nums = [4,7,9,10], k = 3 <br>
**Output:** 8 <br>
**Explanation:** The missing numbers are [5,6,8,...], hence the third missing number is 8.
<br>
<br>
<br>

## Problem 6

### Title:
[Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) (Medium)

### Description:
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

### Example:
**Input:** nums = [4,5,6,7,0,1,2], target = 0 <br>
**Output:** 4 <br>
<br>
<br>
<br>

# Solutions

## Solution 1

## Solution 2

### Binary-Search:

**Approach**

```
class Solution {
    public int findBestValue(int[] arr, int target) {
        int max = 0;
        int sum = 0;
        
        // Find the max value and the upper bound of the seach range.
        for(int num : arr) {
            max = Math.max(max, num);
            sum += num;
        }
        
        // If the sum is smaller than the target the greatest number is the answer.
        if(sum <= target) {
            return max;
        }
        
        // Prepare the binary search
        int left = 0;
        int right = sum;
        int leftSum = getSum(arr, left);
        int rightSum = getSum(arr, right);
        
        
        // Eventually it will narrow down to 2 Consecutive numbers.
        // The smaller one's sum is smaller than the target while the greater one's is greater than the target.
        // Unless we locate a middle value's sum is equal to target.
        while(Math.abs(left - right) != 1) {
            
            int middle = left + (right - left) / 2;
            int midSum = getSum(arr, middle);
            
            if(midSum < target) {
                left = middle;
                leftSum = midSum;
            } else if(midSum > target) {
                right = middle;
                rightSum = midSum;
            } else {
                return middle;
            }
        }
        
        // Determine which one is closer to the target.
        if(Math.abs(leftSum - target) <= Math.abs(rightSum - target)) {
            return left;
        } else {
            return right;
        }
        
    }
    
    // Get the sum of the chosen number
    private int getSum(int[] arr, int number) {
        int sum = 0;
        
        for(int num : arr) {
            sum += Math.min(num, number);
        }
        
        return sum;
    }
}
```
<br>
<br>

## Solution 3

## Solution 4

### Iterative Binary Search

**Approach**

```
public class Solution {
    public int findPeakElement(int[] nums) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
}
```
<br>
<br>

## Solution 5

### Binary-search

**Approach**
The idea is  that if K > nums.length; then the result is nums[nums.length - 1] + (k - nums.length)
so we need to find a largest index that missing number count < k 
as equal condition is in right that we need to use (j - i + 1) / 2 + i
```
class Solution {
    
    public int missingElement(int[] nums, int k) {
        int i = 0;
        int j = nums.length - 1;
        while (i < j) {
            int mid = (j - i + 1) / 2 + i;
            // nums[mid] - nums[0] + 1 total number count, mid + 1 total number we have (nums[mid] - nums[0] + 1) - (mid + 1) = missing number count;
            if (nums[mid] - nums[0] - mid >= k) {   
                j = mid - 1;
            } else {
                i = mid;
            }
        }        
        // nums[i] + (k - missing number count before i) = nums[i] + (k - (nums[i] - nums[0] - i))
        return k + nums[0] + i;     
    }
}
```
<br>
<br>

## Solution 6

### Binary Search

**Approach**
The idea is that when rotating the array, there must be one half of the array that is still in sorted order.
For example, 6 7 1 2 3 4 5, the order is disrupted from the point between 7 and 1. So when doing binary search, we can make a judgement that which part is ordered and whether the target is in that range, if yes, continue the search in that half, if not continue in the other half.

The steps:
1. Set left to 0.
2. Set right which is equal to the length of the array.
3. While `left <= right`, set a Mid to be the number of `left + (left + right) / 2`. 
4. If the number at Mid already match the target, return Mid.
5. Check if which part of the array is the sorted order by checking if the value at Mid is greater that value at Left `if(nums[mid] > nums[left]` so the left side is in sorted order.
6. Check in the left side, if the target is greater than the value at mid = just move the left after the mid OR if the target is still smaller than the left most value, so the target is not there, move the left after the mid.
7. re-define the mid and repeat 4-6
8. If we go outside the loop, it means that we couldn't find the target in the array, so return -1. 
```
class Solution {
    public int search(int[] nums, int target) {
        int lo = 0, hi = nums.length - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (target == nums[mid])
                return mid;
            
            if (nums[mid] < nums[lo]) {
                if (target < nums[mid] || target >= nums[lo])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            } else {
                if (target > nums[mid] || target < nums[lo])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        return -1;
    }
}
```
