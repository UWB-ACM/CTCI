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

### 2. PROBLEM 2 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

### 3. PROBLEM 3 Validate Stack Sequences

Source: [LeetCode](https://leetcode.com/problems/validate-stack-sequences/)

#### Scenario

Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

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

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

### 2. PROBLEM 2 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

## 3. PROBLEM 3 Validate Stack Sequences

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
