# String Manipulation

Problems and solutions for String Manipulation session on October 18, 2019.

## Problems

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

### 2. Custom Sort String

Source: [LeetCode](https://leetcode.com/problems/custom-sort-string/)

#### Scenario

`S` and `T` are strings composed of *lowercase letters*. In `S`, no letter 
occurs more than once.

`S` was sorted in some custom order previously. We want to permute the 
characters of `T` so that they match the order that `S` was sorted. More 
specifically, if letter `x` occurs before `y` in `S`, then `x` should occur 
before `y` in the returned string.

Return any permutation of `T` that satisfies this property.

#### Example Input

```
Input:      S = "cba"
            T = "abcd"

Output:     "cbad"     // or "dcba", "cdba", "cbda"
```

#### Function Signature

DIY (Design it yourself).

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

### 2. Custom Sort String

Source: [LeetCode](https://leetcode.com/problems/custom-sort-string/)

#### Solution

The solution for this problem is nothing more than counting sort with certain characters taking precedence:
```
1. Count the occurrences of each character in T
2. For each character in S:
    a. While count of character is greater than 0:
        I. Append the character to the result
        II. Decrement the count
3. For all 26 lowercase characters:
    a. While count of character is greater than 0:
        I. Append the character to the result
        II. Decrement the count
```

Here's an implementation in C++:
```c++
string customSortString(const string& S, const string& T) {
    int charCounts[26];
    fill(charCounts, charCounts + 26, 0);

    // count char occurrences in T
    for (const char& c: T) charCounts[c - 'a']++;

    ostringstream resStream;
    // append the chars present in S
    for (const char& c: S)
        while (charCounts[c - 'a']-- > 0)
            resStream << c;
    // append the chars for the rest
    for (char c = 'a'; c <= 'z'; c++)
        while (charCounts[c - 'a']-- > 0)
            resStream << c;
            
    return resStream.str();
}
```

Alternatively, we can append the extra characters present in `T` to the end of 
`S`. This way, we can avoid traversing the entire `charCounts` array if the 
characters in the strings are highly homogeneous.

#### Driver For Solution

[The C++ driver and solution is here.](./custom_sort_string/custom_sort_string.cpp)

```console
$ g++ -o test custom_sort_string.cpp
$ ./test
Test1 - S=cba T=abcd
Result: cbad
Test2 - S=cbafg T=abcd
Result: cbad
Test3 - S=disqyr T=iwyrysqrdj
Result: disqyyrrjw
```

### 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution 

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:


