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

We can use a **stack** to simulate the buffer in a text editor. When user types 
in *non-backspace* characters, we **push** it onto the stack (think of the text 
editor appending the character to the end of the buffer).

When we see a *backspace* character, we **pop** the top of the stack ***if the 
stack is not empty*** (think of typing backspace in the text editor, there's 
nothing to delete if it's empty).

In the end, the stack will represent the string the key sequence produces.

The Python solution is as follows:

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

To solve the problem without a data structure, we can compare the strings while 
working our way **backwards** from the end of the string.

Our approach is to skip over the characters that won't be present in the 
`ending_string`, which includes both the *backspaces* and the *deleted 
characters*, and then compare the characters that will be present in the 
`ending_string`.

We can keep track of the amount of characters about to be deleted by using 
`counter`s. When we see a `'#'` (aka *backspace*), we increment the counter. When we see a 
*non-backspace* character *and* counter is greater than `0`, we will decrement 
the counter (i.e., consuming a backspace). Then, when both condition are not 
satisfied, we will compare the characters.

If we reach the other end of the string (start of the string) for both strings 
and all previous comparisons were successful, that means we have found our 
answer to be true.

The code in Python is as follows:

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

#### Testing The Solutions

[The Python implementation and tests are here.](./backspace_string_compare/backspace_string_compare.py)

The output is:

```console
$ python3 backspace_string_compare.py
Test 1, S=ab#c, T=ad#c
Result: stack: True, constant: True
Test 2, S=a##c, T=#a#c
Result: stack: True, constant: True
Test 3, S=ab##, T=c#d#
Result: stack: True, constant: True
Test 4, S=a#c, T=b
Result: stack: False, constant: False
Test 5, S=###, T=
Result: stack: True, constant: True
Test 6, S=####a, T=a###b#a
Result: stack: True, constant: True
```

### 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution 

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:


