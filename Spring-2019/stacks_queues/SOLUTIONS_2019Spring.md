# Stacks and Queues

Problems and solutions for Stacks and Queues session on May 10, 2019.

## Problems

### 1.  Remove K Digits

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

### 2. Validate Stack Sequences

Source: [LeetCode](https://leetcode.com/problems/validate-stack-sequences/)

#### Scenario

Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack. Each item can only be pushed once and popped once.

#### Example Input

Example 1:
```
Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true

Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
```
Example 2:
```
Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false

Explanation: 1 cannot be popped before 2.
```
#### Function Signature

C/C++
```c++
bool validateStackSequences(vector<int>& pushed, vector<int>& popped);
```

Java
```java
bool validateStackSequences(int[] pushed, int[] popped) {
    // your solution here
}
```

## Solutions

### 1. Remove K Digits

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
Input3: 1432219
Output3: 1219
Input4: 10200
Output4: 200
```

## 2. Validate Stack Sequences

Source: [LeetCode](https://leetcode.com/problems/validate-stack-sequences/)

#### Naive/Simple Solution 

For each value, push it to the stack.

Then, greedily pop values from the stack if they are the next values to pop.

At the end, we check if we have popped all the values successfully.

```java
public boolean validateStackSequences(int[] pushed, int[] popped) {
    int N = pushed.length;
    Stack<Integer> stack = new Stack<Integer>();

    int j = 0;
    for (int x: pushed) {
        stack.push(x);
        while (!stack.isEmpty() && j < N && stack.peek() == popped[j]) {
            stack.pop();
            j++;
        }
    }

    return j == N;
}
```

#### Testing The Solutions OR Driver For Solution

The Driver for this solution can be found under the `validate_stack_sequences` directory, and will yield the following output:

```
Pushed: [1, 2, 3, 4, 5], Popped: [4, 5, 3, 2, 1], Output: true
Pushed: [1, 2, 3, 4, 5], Popped: [4, 3, 5, 1, 2], Output: false
Pushed: [10, 11, 12, 13, 14, 15, 16], Popped: [10, 11, 12, 13, 14, 15, 16], Output: true
Pushed: [10, 11, 12, 13, 14, 15, 16], Popped: [13, 16, 15, 14, 12, 11, 10], Output: true
Pushed: [10, 11, 12, 13, 14, 15, 16], Popped: [10, 11, 12, 13, 14, 15, 17], Output: false
Pushed: [10, 11, 12, 13, 14, 15, 16], Popped: [16, 16, 16, 16, 16, 16, 16], Output: false
```
