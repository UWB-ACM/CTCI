# Modified Binary

## Table of Contents

### Problems
1. [Find the Smallest Divisor Given a Threshold](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/) (Medium)
2. [Sum of Mutated Array Closest to Target](https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/) (Medium)
3. [Minimum Number of Days to Make m Bouqets](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/) (Medium)
4. [Find Peak Element](https://leetcode.com/problems/find-peak-element/) (Medium)
5. [Missing Element in Sorted Array](https://leetcode.com/problems/missing-element-in-sorted-array/) (Medium)
6. [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) (Medium)
7. [Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) (Easy)

## Problem 1

### Title: 
[Find the Smallest Divisor Given a Threshold](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/) (Medium)

### Description: 
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result.
Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

It is guaranteed that there will be an answer.

 

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
Example 3:

Input: nums = [21212,10101,12121], threshold = 1000000
Output: 1
Example 4:

Input: nums = [2,3,5,7,11], threshold = 11
Output: 3
 

Constraints:

1 <= nums.length <= 5 * 104
1 <= nums[i] <= 106
nums.length <= threshold <= 106

<br>
<br>
<br>

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

### Title: 
[Minimum Number of Days to Make m Bouqets](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/) (Medium)

### Description:
Given an integer array bloomDay, an integer m and an integer k.

We need to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 

Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let's see what happened in the first three days. x means flower bloomed and _ means flower didn't bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
Example 2:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
Example 3:

Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here's the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.
Example 4:

Input: bloomDay = [1000000000,1000000000], m = 1, k = 1
Output: 1000000000
Explanation: You need to wait 1000000000 days to have a flower ready for a bouquet.
Example 5:

Input: bloomDay = [1,10,2,9,3,8,4,7,5,6], m = 4, k = 2
Output: 9
 

Constraints:

bloomDay.length == n
1 <= n <= 10^5
1 <= bloomDay[i] <= 10^9
1 <= m <= 10^6
1 <= k <= n

<br>
<br>
<br>

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

## Problem 7

### Title:
[Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) (Easy)

### Description:
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= first < second <= numbers.length.

Return the indices of the two numbers, index1 and index2, as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3.
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2.
 

Constraints:

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.

<br>
<br>
<br>


# Solutions

## Solution 1

### Binary Search:

**Approach** 
<br>
We need to find smallest divisor such that sum of arr divided
by divisor is just less than threshold
Here is the pattern to observe
arr = [ 1 ,  2 , 5 , 9  ]
the max elem(9) of the arr which when divided gives= 1+1+1+1=4
so 4 is surely one of the ans.
and the min divisor (i.e 1) can be one which when divided gives = 1+2+5+9=17
which is actually sum of the array
            
so our ans lies in b/w 1 to max elem of arr
            
why binary search:
when divided by 1 :     17
when divided by 2 :     10    (1+1+3+5)
when divided by 3 :     7      (1+1+2+3)
.....
when divided by 9 :     4     (1+1+1+1)
            
we can see a pattern of monotonic decreasing function
this type of question comes under binary search on answer

<br>

```
class Solution {
public:
    int helper(vector<int>& arr,int k){
        int sum=0;
        for(auto &a:arr){
            sum+=(a+k-1)/k;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1,h=1000000;
        while(l<h){
            int mid=l+((h-l)>>1);
            if(helper(nums,mid)>threshold){
                l=mid+1;
            }else{
                h=mid;
            }
        }
        return l;
    }
};
```
<br>
<br>


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

### Binary Search 

**Approach**
<br>
We need m boquets consisting of k flowers
Using binary search we can find the mid point and pass that into solve() and see if nums[i] is less than the mid value
If so then we know nums[i] will bloom before mid and increment count. 
Repeat this process until count is greater than or equal to mid, which count represents the number of flowers that have bloomed.
Return 1 representing mid is an acceptable value or pass 0 representing a bad value. 
Continue this process until l value is greater than r value and return ans that represents the minimum days it will take to complete m boquet order of k flowers.
<br>
```
class Solution {
public:
    bool solve(vector<int>&nums,int m,int k,int mid)
    {
        int i,f=0,count=0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]<=mid)
            {
                f++;
            }
            else
            {
                f=0;
            }
            if(f==k)
            {
                count++;
                f=0;
            }
        }
        if(count>=m)
        {
            return 1;
        }
        return 0;
    }
    int minDays(vector<int>& nums, int m, int k) {
        int i,l=0,r,ans=-1;
        r=*max_element(nums.begin(),nums.end());
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(solve(nums,m,k,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
```
<br>
<br>

## Solution 4

### Linear Scan
**Approach**
Using this approach make sure that there is no two consecutive numbers that is equal.
1. Just check if the number at i is greater than number at i + 1, it means number at i is the peak element, return i;
2. If the number at i is smaller than number at i + 1, the loop will keep going until it found the condition at step 1.
```
public class Solution {
    public int findPeakElement(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] > nums[i + 1])
                return i;
        }
        return nums.length - 1;
    }
```

### Iterative Binary Search
Because we know that the number will 
**Approach**
1. Set left to 0.
2. Set right which is equal to the length of the array - 1.
3. While `left < right`, set a Mid to be the number of `(left + right) / 2`. 
4. Check the index at the middle and compare it with the index after.
5. if the index at the middle is larger than teh index after, it means that it can be the peak number, so move right to the middle also.
6. If the index is smaller than index after, we will reduce the search space by moving the left to the middle + 1, to check the index after middle, because we know that index at the middle aboviously is not the peak number. 
7. By doing this it will reduce the search space until eventually reach a state where only one element is remaining in the search space. This single element is the peak element.
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
The steps:
1. Set left to 0.
2. Set right which is equal to the length of the array - 1.
3. While `left < right`, set a Mid to be the number of `left + (right - left + 1) / 2`. +1 is because we want to do round up instead of round down. 
4. Find how many number from left to mid with the formula `nums[mid] - nums[left] + 1` for example 4,7,9,10 with left at 4 and mid at 9. From 4 - 9 there is 6 number.
5. Find how many number that is just in the array between left and right with the formula `int indexDiff = mid - left + 1`. For example from 4 - 9 there should be 6 number, but in the given array there is just 3 (4,7,9).
6. Check if the totalIndex - index is less than k, so the missing number within the count is not in the left - mid. So move the left to the mid.
7. If the totalIndex - index not less than k, so it means the missing index in within range from left to mid.
8. Because we move left it means that the starting point also move so we have to modify the k by finding how many lost number before the mid by minus the k with the totalIndex - index.
9. last return the left index now + updated k.
```
class Solution {
     public int missingElement(int[] nums, int k) {
        int left = 0;
        int right = nums.length - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            int totalIndex = nums[mid] - nums[left] + 1;
            int index = mid - left + 1;
            if (totalIndex - index < k) {
                left = mid;
                k -= (totalIndex - index);
            } else {
                right = mid - 1;
            }
        }
        return nums[left] + k;
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
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid])
                return mid;
            
            if (nums[mid] < nums[left]) {
                if (target < nums[mid] || target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                if (target > nums[mid] || target < nums[left])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
}
```
<br>
<br>

## Solution 7

### Binary Search
**Aproach**
<br>
We use two indices, initially pointing to the first and the last element, respectively. Compare the sum of these two elements with target. If the sum is equal to target, we found the exactly only solution. If it is less than target, we increase the smaller index by one. If it is greater than target, we decrease the larger index by one. Move the indices and repeat the comparison until the solution is found.
<br>
```
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
                          
            if (sum == target) {
                return {low + 1, high + 1};
            } else if (sum < target) {
                ++low;
            } else {
                --high;
            }
        }
        // In case there is no solution, return {-1, -1}.
        return {-1, -1};
    }
};
```

<br>
<br>
