<!-- Don't remove -->
<a name="top"/>

# String Manipulation

Problems and solutions for String Manipulation session on January 31, 2020.

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

### 1. Validate IP Address

Source: [Leetcode](https://leetcode.com/problems/validate-ip-address/)

#### Scenario

Write a function to check whether an input string is a valid IPv4 address. 

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, 
each ranging from 0 to 255, separated by dots ('.'), e.g., `172.16.254.1`.

Leading zeros in the IPv4 is invalid. For example, the address `172.16.254.01` is invalid.

Note: You may assume there is no extra space or special characters in the input string.

#### Function Signature

```python
def isValidIP(IP):
    # your code here
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

### 3. Minimum Window Substring

Source: [LeetCode](https://leetcode.com/problems/minimum-window-substring/)

#### Scenario

Given a string S and a string T, find the minimum window in S which 
will contain all the characters in T in complexity O(n).

#### Example Input

```
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
```

#### Function Signature

C++:

```c++
std::string minimumWindow(std::string S, std::string T) {
    // your code here
}
```

Python:

```python3
def minimum_window(s, t):
    # your code here
```

<!-- Don't remove -->
Go to [Solution](#s3)   [Top](#top)

<!-- Don't remove -->
<a name="solutions"/>

## Solutions

<!-- Don't remove -->
<a name="s1"/>

### 1. Validate IP Address

Source: [Leetcode](https://leetcode.com/problems/validate-ip-address/)

#### Solution
Python is an excellent language for string manipulation owing to its powerful and intuitive built-in string library. 

We can start this problem by calling the `.split('.')` function on our IP string parameter to separate the input by `.` symbols. 

From there, we can perform a quick check of the length of the list returned from the `.split()` using the `len()` function (length). 
If we don't have exactly four elements in our list, we know the input is invalid.

Otherwise, we will traverse through the four values, checking each one for leading zeros using the `[0]` index operator. 
Then we  can cast each string value to an int to check that the values are between 0 and 255.

If we are able to traverse through all four values without setting off any of these conditions, we know we have a valid 
IPv4 address. 
```python
def isValidIP(IP):
    values = IP.split('.')
    if len(values) != 4:
        return False
    for str_val in values:
        if len(str_val) > 1 and str_val[0] == '0':
            return False
        int_val = int(str_val)
        if int_val < 0 or int_val > 255:
            return False
    return True
```

#### Driver For Solution

The solution code is [in the repository](./validate_IP/validate_IP.py)

It produces the following output:

```console
$ python3 validate_IP.py
IP Address Test Cases:
Testing 192.168.1.1 (Valid - home <3), Result: True
Testing 0.0.0.0 (Valid - standalone zeros are ok), Result: True
Testing 88.088.088.88 (Invalid - leading zeros), Result: False
Testing 192.168.0 (Invalid - less than 4 values), Result: False
Testing 355.0.168.0 (Invalid - value greater than 255), Result: False
```

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

### 3. Minimum Window Substring

Source: [LeetCode](https://leetcode.com/problems/minimum-window-substring/)

#### Simple Solution 

The problem statement was:

> Given a string S and a string T, find the minimum window in S which 
> will contain all the characters in T in complexity O(n).

We proceed to solve the problem by creating a window in S which contains 
all the characters in T. We can compress the window from the left until the window no 
longer contains all characters in T, and expand the window to the right and consume 
characters that have not been visited yet. This is known as the **sliding 
window** approach.

As we compress and expand the substring window, we track the shortest 
substring which contains all of T's characters.

To compare the window's contents to T's contents, this solution builds 
**frequency maps** of the characters occuring in T and in the window. 
We can check that the window's frequency map contains, at a minimum, 
all the elements that T contains.

The frequency map creation and comparison are implemented as subroutines, 
as seen below.

```python3
def freq(x):
    return { c: x.count(c) for c in x }

def is_dict_subset(stable, new):
    """
    Determine if one dictionary is a subset of another dictionary.
    
    For this to be true, all keys in 'stable' must be present in 'new' 
    and the frequency count of all elements in 'stable' must be included 
    in 'new'.
    """
    for k in stable:
        if k not in new or new[k] < stable[k]:
            return False
    return True
```

The solution for the minimum window problem is given as follows:

```python3
def minimum_window(s, t):
    if not s or not t: return ""
    # s is a long string that we must search for minimum window
    # t is a string containing all characters to be searched
    left = right = 0    # indeces
    window = ""
    frequency_table = freq(t)
    while right < len(s):
        curr = freq(s[left:right + 1])
        if is_dict_subset(frequency_table, curr):
            if not window or right - left < len(window):
                window = s[left:right + 1]
            left += 1
        else:
            right += 1
    return window
```

#### Optimal Solution

Two other solutions are available 
[in the LeetCode page for the problem](https://leetcode.com/problems/minimum-window-substring/solution/).
They are also variations on the **sliding window** implementation, and have 
better performance characteristics than the simple solution given here.

#### Testing The Solutions OR Driver For Solution

The solution provided here [is available in the repository](./minimum_window/solution.py), 
along with [a driver for testing](./minimum_window/driver.py). 
There are additional solutions [available on LeetCode](https://leetcode.com/problems/minimum-window-substring/solution/).

<!-- Don't remove -->
Go to [Top](#top)
