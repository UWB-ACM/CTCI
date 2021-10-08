# Sliding Windows

## Table of Contents

### Problems
1. [Maximum Average Subarray 1](https://leetcode.com/problems/maximum-average-subarray-i/) (Easy)
2. [Minumun Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) (Medium)
3. [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) (Medium)


## Problem 1 (Easy)

### Title:
[Maximum Average Subarray 1](https://leetcode.com/problems/maximum-average-subarray-i/)

### Description:
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is **equal to k** that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

### Example:
**Input:** nums = [1,12,-5,-6,50,3], k = 4 <br>
**Output:** 12.75000 <br>
**Explanation:** Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
<br>
<br>
<br>

## Problem 2 (Medium) 

### Title:
[Minumun Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)

### Description:
Given an array of positive integers nums and a positive integer target, return the minimal length of a **contiguous subarray** of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

### Example: 
**Input:** target = 7, nums = [2,3,1,2,4,3] <br>
**Output:** 2 <br>
**Explanation:** The subarray [4,3] has the minimal length under the problem constraint.
<br>
<br>
<br>

## Problem 3 (Medium)

### Title:
[Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

### Description:
Given a string s, find the length of the longest substring without repeating characters.

### Example:
**Input:** s = "abcabcbb" <br>
**Output:** 3 <br>
**Explanation:** The answer is "abc", with the length of 3.
<br>
<br>
<br>

# Solutions

## Solution 1

### Brute-force:
ToDo

### Sliding-window (optimal):

**Approach:** 
For this problem, the sliding window is of fixed length. We know this because the problem states it wants a subarray of length k.

We know the window is going to be size k, so we create window start and window end variables to keep track of where our window is located in the array. 
We also need to keep track of the current sum we have in our window of size k, and the maximum sum we have seen so far in the array. 

To start, we begin looping through the array, and adding the number at nums[end] to our current sum. Once our windoow length has reached size 3, we need to update our maxSum variable by comparing the maxSum and currentSum variables. After our maxSum variable has been updated, we now need to move our window to the next position.

In order to do this, we need to move the starting index forward, but be careful because if we just move the start index forward, the value at the start index is still part of our current sum. The fix to this is easy, we just subtract nums[start] from our current sum. And then we continue the above processes until we have reached the end of the array. 

The maximum average at this point would be the maxSum / k window length.

```
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int currentSum = 0;
        int maxSum = Integer.MIN_VALUE;
        int start = 0;
        int end = 0;   
        
        while (end < nums.length) {
            
            currentSum += nums[end];
        
            // if we have reached the end of k window length
            if (end >= k - 1) {
                maxSum = Math.max(currentSum, maxSum);
                currentSum -= nums[start];
                start++;
            }
            
            end++;
        }
        return (double)maxSum / k;
    }
}
```
<br>
<br>

## Solution 2

### Brute-force:
ToDo
### Sliding-window (optimal):

**Approach:** 
For this problem, the sliding window is dynamic, which means that the window can grow or shrink based on whether or not the curernt subarray is greater than or equal to the targer number.

Knowing that our sliding window is dynamic, we should create a start and end variable to keep track of the windows boundaries. In this case, the end
variable is defined in the for loop and starts at the start variables index.

The question would like to us to return an integer coorespoding to the minimum length subarray thats sum is greater than or equal to the target number. In order to keep track of the current sum, the max xum seen so far, and the minumum window length so far.

We begin by looping through the array and adding to our current sum. Once we reach a current sum that is greater than or equal to the target, we have technically met the criteria, but we want to see if any of the other subarrays are smaller in length. To do this, we begin by getting the current windows length and assigning it to the minWindow variable. Now what we need to do is remove the character from the start of the window and move the windows start index forward, this step happens until the current sum is less than target. Once the current sum is less than tha target, we can increment the end index higher and repeat the same processes described above.

```
class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int start = 0;
        int currentSum = 0;
        int maxSum = Integer.MIN_VALUE;
        int minWindow = Integer.MAX_VALUE;
        
        for (int end = 0; end < nums.length; end++) {
            
            currentSum += nums[end];
            
            while (currentSum >= target) {
                
                minWindow = Math.min(minWindow, (end - start + 1));
                
                // used to check if biggest sum so far is >= target
                maxSum = Math.max(currentSum, maxSum);
                currentSum -= nums[start];
                start++;
            }
        }
        
        if (maxSum < target) {
            return 0;
        }
        return minWindow;
    }
}
```
<br>
<br>

## Solution 3

### Brute-force:
ToDo
### Sliding-window (optimal):

**Approach:** 

The sliding window for this problem is dynamic, which means it can grow or shrink in size depending on what characters are in the current substring.

Knowing that our sliding window is dynamic, we should create a start and end variable to keep track of the windows boundaries. In this case, the end
variable is defined in the for loop and starts at the start variables index.

The question would like us to return an integer which is the length of the longest substring that was found, therefor we don't have to return the substring
and all we have to do is keep track of how long the current substring is, and the longest substring we have seen so far.

We also need some way to keep track of characters that are currently in our sliding windows boundaries. To do this, we can use a HashSet for O(1) lookup.
The HashSet will contain all of the characters in our current sliding window. 

We begin by looping through the string, and adding characters to our HashSet. If the character **isn't** already in the HashSet, we will add it, and increment our
currentSubstring counter. If the character **is** in the HashSet, then we now have a duplicate character and need to adjust our sliding window and the characters being held in the set. To do this, we remove the character from the set cooresponding to the starting index in the window, and we keep doing this until the set no longer contains the same character. For every removal from the set, we need to decrease the currentSubstrings length, and move the starting index forward.

```
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int start = 0;
        int longestSubstring = 0;
        int currentSubstring = 0;
        HashSet<Character> charSet = new HashSet<>();
        
        for (int end = 0; end < s.length(); end++) {
            char c = s.charAt(end);
            currentSubstring++;
            
            while (charSet.contains(c)) {
                charSet.remove(s.charAt(start));
                start++;
                currentSubstring--;
            }
            
            longestSubstring = Math.max(currentSubstring, longestSubstring);
            charSet.add(c);
        }
        return longestSubstring;
    }
}
```
