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

### 3. Reverse Substrings In Parentheses

Source: [LeetCode](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/) 

#### Scenario

You are given a string `s` that consists of lower case English letters 
and brackets. 

Reverse the strings in each pair of matching parentheses, starting 
from the innermost one.

Your result should not contain any brackets.

<a name="constraints">

Constraints:

* `s` only contains lower case English characters and parentheses.
* It's guaranteed that all parentheses are balanced.

#### Example Input

```
Input: s = "(u(love)i)"
Output: "iloveu"
```

We begin by reversing the inner characters (`love` becomes `evol`), 
and then reverse the entire string (`uevoli` becomes `iloveu`).

#### Function Signature

C++:

```c++
string reverseParentheses(string s) {
    // your code here
}
```

Java:

```java
public String reverseParentheses(String s) {
    // your code here
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

```python3
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

```python3
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

### 3. Reverse Substrings In Parentheses

Source: [LeetCode](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/) 

#### Solution Approach

The essential problem here is to determine the order of strings to 
reverse, since we expect arbitrary parenthesis pairs to be nested 
within each other. The nature of this problem lends itself to stacks 
very well.

If you create a stack that represents instances of opening parentheses 
(by, for example, recording the index location of that character), you 
will be able to pop the most recent index location when you find a 
closing parenthesis. 

When you have this index pair, you can reverse the contained substring 
and continue searching for the next parenthesis (open or closed).

The remaining problem we have is how to ensure the contained string 
is updated properly so that higher levels of nested strings reverse the 
string properly. The solution provided here updates the string in-place 
and manages the traversal index manually to account for removed 
parentheses. Other implementations for this subproblem exist.

_Note: the given [constraints](#constraints) are particularly useful 
for this problem statement and remove a lot of the edge case checking 
we would need for a more robust solution._

#### Solution

The C++ solution in its entirety is:

```c++
// Solution function.
string reverseParentheses(string s) {
    // Create a stack to store the index position of all open parentheses.
    stack<int> open; 
    for (int i = 0; i < s.length(); i++) {
        // We have reached a new subset for reversal.
        // Add this index to the stack.
        if (s[i] == '(') {
            open.push(i);
        // We have finished traversing a subset to be reversed; 
        // now, reverse it.
        } else if (s[i] == ')') {
            int start = open.top();
            open.pop();
            // Use utility function to reverse found substring.
            // NOTE: here, we intentionally exclude the parentheses.
            string result = reverseString(s.substr(start + 1, i - start - 1));
            // We then modify the string in-place (replacing 
            // parentheses grouping with reversed inner string),
            // and update our index value to account for the removed 
            // characters.
            s.replace(start, i - start + 1, result);
            i -= 2;
        }
    }
    return s;
}

// Helper function.
// NOTE: could use std::reverse instead.
string reverseString(string r) {
    stringstream s;
    for (int i = r.length() - 1; i >= 0; i--) {
        s << r[i];
    }
    return s.str();
}
```

#### Testing The Solution

[The C++ solution is included in the repository.](./reverse_substrings/reverse.cpp)

The solution's output is:

```console
$ g++ -o test reverse.cpp && ./test
Input: (abcd)                   Output: dcba
Input: (u(love)i)               Output: iloveu
Input: (ed(et(oc))el)           Output: leetcode
Input: ab(gf(cde))hij(lk)mno    Output: abcdefghijklmno
Input: 	                        Output: 
Input: hello	                Output: hello
Input: hap(k((ul(go))c)yp)y	    Output: happygolucky
```
