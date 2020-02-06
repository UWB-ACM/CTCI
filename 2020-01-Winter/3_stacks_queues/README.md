<!-- Don't remove -->
<a name="top"/>

# Stacks & Queues

Problems and solutions for Stacks & Queues session on February 7, 2020.

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

### 2. PROBLEM 2 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

<!-- Don't remove -->
Go to [Solution](#s2)   [Top](#top)

<!-- Don't remove -->
<a name="p3"/>

### 3. Trapping Rain Water 

Source: [LeetCode](https://leetcode.com/problems/trapping-rain-water/)

#### Scenario

Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

#### Example Input

![alt text](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png "Example")

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.

Input: [0,1,0,2,1,0,1,3,2,1,2,1] </br>
Output: 6

#### Function Signature

C++:

```c++
public:
    int trap(vector<int>& height) {
        # your code here
    }
```

Python:

```python
def trap(self, height):
    # your code here
```

Java:

```java
public int trap(int[] height) {
       # your code here 
    }
```

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

### 2. SOLUTION 2 TODO :bug:

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
<a name="s3"/>

### 3. Trapping Rain Water 

Source: [LeetCode](https://leetcode.com/problems/trapping-rain-water/)

#### Solution

We check the left most bar and right most bar, if the left most bar is smaller or equal to the right most bar, 
we know that the water level on the right side of the left most bar should be at the left most bar's level. 
At this point, we can check the height of our new left most bar without the right most bar. 
We keep doing this until those 2 pointers meet each other.

```python
def trap(self, height):
        s = 0
        l, r = 0, len(height)-1
        while l < r:
            i = 1
            if height[l] < height[r]:
                while height[l] > height[l+i]:
                    s += height[l] - height[l+i]
                    i += 1
                l += i
            else:
                while height[r] > height[r-i]:
                    s += height[r] - height[r-i]
                    i += 1
                r -= i
        return s
 ```
 

#### Driver For Solution

The solution code is [in the repository]()


It produces the following output:

```console
$ python TrappingRainWater.py
Test Begins
Test 1
[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
6
Test 2
[0, 3, 2, 1, 0, 4, 6, 2, 0, 1, 2, 3, 1]
13
```

<!-- Don't remove -->
Go to [Top](#top)
