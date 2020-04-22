<!-- Don't remove -->
<a name="top"/>

# String Manipulation

Practice solving string related problems. Session on April 24, 2020.

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

### 1. Reverse String

[LeetCode](https://leetcode.com/problems/reverse-string/)
#### Scenario

Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array **in-place** with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

#### Example Input

**Input:** \["h","e","l","l","o"]

**Output:** \["o","l","l","e","h"]

#### Function Signature

**Java:**
```
class Solution {
    public void reverseString(char[] s) {
        
    }
}

```

**Python:**
```
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        
```

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

### 1. Reverse String

Source: [LeetCode](https://leetcode.com/problems/reverse-string/solution/)
 
#### Optimal Solution

<details>
<summary>Click to see solution</summary>
 
**What does in-place mean?**

By definition, an in-place algorithm is an algorithm which transforms input using no auxiliary data structure.
 
**Two Pointers Approach:**

In this approach, two pointers are used to process two array elements at the same time. Usual implementation is to set one pointer in the beginning and one at the end and then to move them until they both meet.

**Algorithm:**

Set pointer left at index 0, and pointer right at index n - 1, where n is a number of elements in the array.

While left < right:

Swap char[left] and char[right].

Move left pointer one step right, and right pointer one step left.

**Java:**
```
class Solution {
    public void reverseString(char[] s) {
        int left = 0, right = s.length - 1;
        while (left < right) {
            char tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
        }
    }
}

```

**Python:**

```
class Solution:
    def reverseString(self, s):
        left, right = 0, len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left, right = left + 1, right - 1
```

**Complexity Analysis:**

Time complexity: O(N) to swap N/2 element.

Space complexity: O(1), it's a constant space solution.

</details>
 
#### Testing The Solutions OR Driver For Solution

See [driver](./reverse_string/Driver.java)

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s2"/>

### 2. SOLUTION 2 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution
<!-- Don't remove the tags below -->

<details>
<summary>Click to see solution</summary>
 
TODO :bug:

</details>

#### Optimal Solution

<details>
<summary>Click to see solution</summary>
 
TODO :bug:

</details>

#### Testing The Solutions OR Driver For Solution

TODO :bug:

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s3"/>

### 3. SOLUTION 3 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution 
<!-- Don't remove the tags below -->

<details>
<summary>Click to see solution</summary>
 
TODO :bug:

</details>

#### Optimal Solution
<details>
<summary>Click to see solution</summary>
 
TODO :bug:

</details>

#### Testing The Solutions OR Driver For Solution

TODO :bug:

<!-- Don't remove -->
Go to [Top](#top)
