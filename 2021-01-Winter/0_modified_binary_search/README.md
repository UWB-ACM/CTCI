<!-- Don't remove -->
<a name="top"/>

# Topic Name TODO :bug:

Simple description TODO :bug:

In the style of:
***Problems and solutions for Maze & Dynamic Programming session on March 1, 2019.***

### Table of Contents

* [Problems](#problems)
  * [1](Binary Search)
  * [2](Sqrtx)
  * [3](Find first and last position of element in sorted array)
* [Solutions](#solutions)
  * [1](#s1)
  * [2](#s2)
  * [3](#s3)

<!-- Don't remove -->
<a name="problems"/>

## Problems

<a name="p1"/>

### 1. PROBLEM 1 TODO :bug:

Source: https://leetcode.com/problems/binary-search/

#### Scenario

Given a sorted array of integers, and a target number, write a function to search for target in nums (efficiently)

#### Example Input
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

#### Function Signature

C++: public int search(vector<int>& nums, int target)
Java: public int search(int[] nums, target)

<!-- Don't remove -->
Go to [Solution](#s1)   [Top](#top)

<!-- Don't remove -->
<a name="p2"/>

### 2. Sqrtx

Source: [LeetCode](https://leetcode.com/problems/sqrtx/)

#### Scenario

Implement `int sqrt(int x)`.

Compute and return the square root of `x`, where `x` is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

#### Example Input 1

**Input:** `4`

**Output:** 2

#### Example Input 2

**Input:** `8`

**Output:** 2

**Explanation:** 
The square root of 8 is 2.8284.... Since we are returning an integer, the decimal part is trimmed, and only 2 is returned

The maximum number of consecutive 1s is 3.
#### Function Signature

**C++:** ` int mySqrt(int x)`

**Java:** `public int mySqrt(int x)`

<!-- Don't remove -->
Go to [Solution](#s2)   [Top](#top)

<!-- Don't remove -->
<a name="p3"/>

### 3. Find First and Last Position of Element in Sorted Array

Source: [LeetCode] https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/ 

#### Scenario

Given an array of Integers sorted in ascending order, find the starting and edning position of a given target value.
If the target is not found in the array, return {-1, -1}.

Follow up: Could you write this algorithm in O(log n) runtime complexity?

#### Example Input

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

#### Function Signature

Java: public int[] searchRange(int[] nums, int target)
C++: public:
vector<int> searchRange(Vector<int>& nums, int target)

<!-- Don't remove -->
Go to [Solution](#s3)   [Top](#top)

<!-- Don't remove -->
<a name="solutions"/>

## Solutions

<!-- Don't remove -->
<a name="s1"/>

### 1. SOLUTION 1 TODO :bug:

Source: https://leetcode.com/problems/binary-search/

#### Binary Search Solution

1. First, lets initiate our `left` and `right` variables, our left will start at the 0th index of the array, and right will start at `arrays.length -1` (the very last index of the array.)
2. Lets make a while loop, `while(left <= right)`
3. Inside the while loop we'll initiate the pivot index or what some call the "mid," so `int pivot = (left + right) /2;`
4. Create if statement `if(nums[pivot] == target])`, then we've found target, `return pivot`.
5. Create else if statement, `else if(target < nums[pivot])`, then `right = pivot - 1;`
6. Create else statement, `else`, `left = pivot + 1`.
7. Outside of our while loop, we will `return -1`, when we reach here, we've searched through our whole array and failed to find our target index, so return -1.

Complexity: O(N log N) since we divide the array in half each time.
Space Complexity: o(1) no extra space used 

```
Example Code of Solution
    public int search(int[] nums, int target) {
        int left = 0, right = nums.length - 1; //Initialize two pointers, one at the beginning of the array, and one at the very end.
        while(left <= right){
            int pivot = (left + right) / 2; //Pivot starts at the middle.
            if(nums[pivot] == target)
                return pivot; //Our target is found, return index.
            else if(target < nums[pivot])
                right = pivot - 1; //If our target is less than our pivot, we close out the right side from mid, since we know our target isn't there.
            else
                left = pivot + 1; //Our target is greater than pivot, close out the left side from mid.
        }
        return -1; //Return -1 if not found.
        }

```

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s2"/>

### 2. Sqrtx

Source: [LeetCode]((https://leetcode.com/problems/sqrtx/)

#### Binary Search Solution

For `x > = 2`, the square root is smaller than `x/2` and greater than `0`. 

We can take advantage of this knowledge and iterate over the sorted set of integer numbers from `2` to `x`, dividing the problem in half in each iteration, until we find the square root.

The steps are:

1. If `x < 2`, then return `x`
2. Set a left boundary `left` which is equals to 2
3. Set a right boundary `right` which is equals to `x/2`
4. Create a return int `res`. It will keep track of the closest integer representation of a square root that has decimal numbers (like the case where `x = 8`)
5. While `left <= right`
	5.1. Set a mid point `mid` to be the number in the middle of `left` and `right`
	5.2. If `mid * mid == x` then return `mid`, we have found the exact square root
	5.3. If `mid * mid > x`, then we need to reduce the right boundary because our `mid` is too big, so we update `right` to `right = mid - 1`
	5.4. If `mid * mid < x`, then we need to increase the left boundary because our `mid` is too small, so we update `left` to `left = mid + 1`. We also update `res` to `res = mid`, keeping track of the closes integer representation of the square root of `x`
6. If we go out of the while loop, it means we couldn't find an exact square root for `x`, so we return `res`

Example code of this implementation:

```
int mySqrt(int x) {
        // if x is less than 2, then return x
        if (x < 2) {
            return x;
        }
    
        int left = 2;           //left boundary
        int right = x /2;       //right boundary
        int res = 1;            // result to return if not exact square root is found
        
        
        while (left <= right) {
            //The mid point between left and right boundary
            long mid = (left + right) /2;
            
            // if mid ^ 2 = x then we have found the exact square root
            if (mid * mid == x) {
                return mid;                
            } else if (mid * mid > x) {     //Else if mid ^ 2 is greater than x, we reduce the right boundary by one
                right = mid - 1;
            } else {                        //Else if mid ^ 2 is less than x, we need to increase the left boundary by one
                left = mid + 1; 
                res = mid;                  //Res is mid
            }            
        }
        //if we were not able to find an exact square root, we return the closes estimate (int representation) 
        return res;
    }
```

The time complexity of this solution is O(N log N). Since we are dividing our problem by half on each iteration.
The space complexity is O(1), because we are not using any extra space to store information. 

#### Testing The Solutions OR Driver For Solution

[Click here for the C++ driver](./QuestionOne/driver.cpp)

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s3"/>

### 3. Find First and Last Position Of Element in Sorted Array

Source: [LeetCode] https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#### Binary Search Solution
Since the array that is given to us is already sorted, we can use binary search to find the index of the leftmost and rightmost indices.

```

```

Time Complexity: O(log N) Binary Search used twice, two is a constant, therefore, O(log N)
Space Complexity: O(1) since all work is done in place, memory usage is constant.

#### Linear Scan (Brute Force)
We will first do a linear scan of the numbers on the left, and break once we find an instance of the target, if we never break, then we can return the error case of {-1, -1}. If we find a valid left index, we will do a second linear scan starting from the right side of the array, (Question constraint: IF THERE IS A LEFTMOST TARGET, THERE GUARAUNTEED WILL BE A RIGHTMOST TARGET. We will then return a list that contains the indices of the target being found.

1. Initialize array with error case - `int[] res = {-1. -1};` res stands for result, fyi, name it whatever you want.
2. Write a for loop that goes from 0 to nums.length : `for(int i = 0; i < nums.length; i++){
3. If `(nums[i] == target)` then our result `res[0] = i`. Break here: `break;`
4. In the scenario where we didnt find the target, `if(res[0] == -1)`, then return res.
5. Write a for loop that goes from nums.length-1 to 0: `for(int j = nums.length-1; j >=0; j--){`
6. Inside this loop, `if(nums[j] ==target)` then `res[1] = j;`, break
7. return res. 

```
Example Solution
    public int[] searchRange(int[] nums, int target) {
        int[] res = {-1, -1};
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == target){
                res[0] = i;
                break;
            }
        }
        if(res[0] == -1){
            return res;
        }
        for(int j = nums.length -1; j >= 0; j--){
            if(nums[j] == target){
                res[1] = j;
                break;
                }
        }
        return res;
    }
}
```

Time Complexity: O(n)
Space Complexity: O(1)

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

<!-- Don't remove -->
Go to [Top](#top)
