<!-- Don't remove -->
<a name="top"/>

# String Manipulation

Practice solving string related problems. Session on April 24, 2020.

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

You may assume that all array indices contain printable ASCII characters.

#### Example Input

**Input:** \["h","e","l","l","o"]

**Output:** \["o","l","l","e","h"]

#### Function Signature

**Java:**
```
class Solution {
    public void reverseString(char[] s) {
       //Do not return anything, modify s in-place instead
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

### 3. Add Strings

Source: [Leetcode](https://leetcode.com/problems/add-strings/)

#### Scenario

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

* The length of both num1 and num2 is < 5100.
* Both num1 and num2 contains only digits 0-9.
* Both num1 and num2 does not contain any leading zero.
* **You must not use any built-in BigInteger library or convert the inputs to integer directly.**

#### Example Input

num1 = '0'; num2 = '0'; output = '0';
num1 = '123'; num2 = '9'; output = '132';

#### Function Signature

```c++
class Solution {
public:
    string addStrings(string num1, string num2) {
        
    }
};
```
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

- Set pointer left at index 0, and pointer right at index n - 1, where n is a number of elements in the array.

- While left < right:

   - Swap char[left] and char[right].

   - Move left pointer one step right, and right pointer one step left.

**Java:**
```java
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

```python
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
 
#### Driver For Solution

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

### 3. Add String

#### Optimal Solution

<details>
<summary>Click to see solution</summary>

C++ Solution

Since we are not allowed to use library tools to convert our strings to integers we can evaluate the last string values individually and build our answer forward with ASCII conversion. By starting our loop with the end values it allows us to build a new string that accounts for a resulting string that may be longer than arugument strings.

ASCII conversion translates that the string "0" equals the ASCII code of 48. This builds 1 single digit value equivilantly, up to ASCII value of 57 which equates to the string value of "9".

In each conditional if statement in our while loop, we check that there are more values to be parsed from the string. If so, we take the current string character and remove the ASCII value of '0', leaving us with an interger equivilant answer of that character. 

We add those 2 integer values together into sum and add in the value from our remain (if there is one). Next we create a value for remain by perform an integer division of 10, which results in 0 if our value sum is less than 10, or a number of 1-8 otherwise. 

Next we convert those values back to string by adding the string character "0" (which is ASCII 48) to the sum value modded by 10 (to give us a digit value).

The after we exit the while loop we simply reverse the string we have and return that answer.

```C++
class Solution {
public:
    string addStrings(string num1, string num2) {
    // create integers that represent strings length
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;
        int remain = 0;
        string ans;
        // loops through while any condition is true
        while(n1 >= 0 || n2 >= 0 || remain) {
        int d1;
        int d2;
        // checks if values are left in num1
            if (n1 >= 0){
            // if so- turn d1 into int diff of string ASCII and '0'
                d1 = num1[n1--] - '0';
                } else {
                d1 = 0;
            }
            // Ternary equivalent
            // int d1 = (n1 >= 0) ? num1[n1--] - '0' : 0;
            if (n2 >= 0){
                int d2 = num2[n2--] - '0';
                } else {
                int d2 = 0;
            }
            // Ternary equivalent
            // int d2 = (n2 >= 0) ? num2[n2--] - '0' : 0;
            
            int sum = d1 + d2 + remain;
            // remain is 0 in integer division if value is less than 10
            remain = sum/10;
            ans += '0' + (sum % 10); 
        }
        // reverse the string to form appropriate return value
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
</details>

#### Testing The Solutions OR Driver For Solution

<!-- Don't remove -->
Go to [Top](#top)
