# Stacks and Queues

Problems and solutions for Stacks & Queues session on October 25, 2019.

## Problems

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

### 2. Backspace String Compare

Source: [LeetCode](https://leetcode.com/problems/backspace-string-compare/)

#### Scenario

Given two strings `S` and `T`, return if they are equal when both are typed into empty text editors. `#` means a backspace character.

Bonus: can you do it in O(1) space?

#### Example Input

```
Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
```
```
Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
```

#### Function Signature

C++:
```c++
bool backspaceCompare(string S, string T) {
    // your code here
}
```

Java:
```java
boolean backspaceCompare(String S, String T) {
    // your code here
}
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

### 2. Backspace String Compare

Source: [LeetCode](https://leetcode.com/problems/backspace-string-compare/)

#### Stack Solution

```python
def backspace_compare_stack(S: str, T: str) -> bool:
    def ending_string(sequence: str) -> str:
        stack = []
        for char in sequence:
            if char == '#':
                if stack:       # only pop if stack isn't empty
                    stack.pop()
            else:
                stack.append(char)
        return ''.join(stack)
    
    return ending_string(S) == ending_string(T)
```

#### O(1) Space Solution

```python
def backspace_compare_constant(S: str, T: str) -> bool:
    s_count, t_count = 0, 0     # running count of '#'
    s_ptr, t_ptr = len(S) - 1, len(T) - 1

    while True:
        # jump to next char that won't be deleted
        while s_ptr >= 0 and (s_count > 0 or S[s_ptr] == '#'):
            s_count += 1 if S[s_ptr] == '#' else -1
            s_ptr -= 1

        # for T too
        while t_ptr >= 0 and (t_count > 0 or T[t_ptr] == '#'):
            t_count += 1 if T[t_ptr] == '#' else -1
            t_ptr -= 1

        # check if they're done
        s_done, t_done = s_ptr == -1, t_ptr == -1
        if s_done & t_done:
            return True

        # only one done or the char is different
        if s_done ^ t_done or S[s_ptr] != T[t_ptr]:
            return False

        # the chars match, so decrement both
        s_ptr -= 1
        t_ptr -= 1
```

#### Testing The Solutions OR Driver For Solution

TODO :bug:

### 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution 

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:


