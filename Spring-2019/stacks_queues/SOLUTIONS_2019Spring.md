# Stacks and Queues

Problems and solutions for Stacks and Queues session on May 10, 2019.

## Problems

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

### 2.  Remove K Digits

Source: [leetcode](https://leetcode.com/problems/remove-k-digits/)

#### Scenario:

Given a non-negative integer num represented as a string, remove `k` digits from the number so that the new number is the smallest possible.

#### Note:

* The length of num is less than 10002 and will be ≥ k.
* The given num does not contain any leading zero.

#### Example Input

```
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain
leading zeroes.
```

#### Function Signature

C++:

```c++
String removeKdigits(String num, int k){}
```

Java:

```java
public String removeKdigits(String num, int k){}
```

### 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

## Solutions

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

### 2. Remove K Digits

Source: [The Fake Geek's Blog](http://shirleyisnotageek.blogspot.com/2016/10/remove-k-digits.html)

#### Optimal Solution

Using a stack, pop out the previous digits that is larger if doesn't exceed n. If the string is in ascending order, pop out any extra chars. Remove all "0"s in the front and return result.

The time complexity of this solution is `O(N)`.

```java
// Solution Method Definition
// Note: this is the optimized solution
public String removeKdigits(String num, int k) {
        if (num.length() == 0) {
            return "0";
        }
        Stack<character> stack = new Stack<>();
        for (char c : num.toCharArray()) {
            while (!stack.isEmpty() && k > 0 && stack.peek() > c) {
                stack.pop();
                k--;
            }
            stack.push(c);
       }
       while (stack.size() > num.length() - k) {
           stack.pop();
       }
       StringBuilder rst = new StringBuilder();
       while (!stack.isEmpty()) {
           rst.append(stack.pop());
       }
       int index = rst.length();
       while (index > 0 && rst.charAt(index - 1) == '0') {
           index--;
       }
       rst.delete(index, rst.length());
       return rst.length() == 0 ? "0" : rst.reverse().toString();
     }
```

#### Testing The Solutions OR Driver For Solution

The executable Java solution for this problem is located under `Spring-2019/stacks_queues/Remove_K_digits/main.java`.

The output for Java solution where `k` = 5 is:

```console
Input1: 765028321
Output1: 221
Input2: 478502841
Output2: 241
```
## 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution 

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:


