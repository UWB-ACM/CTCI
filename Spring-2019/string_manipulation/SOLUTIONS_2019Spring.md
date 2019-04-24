# String Manipulation

Problems and solutions for Maze & Dynamic Programming session on April 26, 2019.

## Problems

### 1. URLify

Source: CTCI 1.3

#### Scenario:

Write a method to replace all spaces in a string with `%20`. You may assume:

* The string exists in an array of characters
* The string has sufficient space at the end to hold the additional characters
* You are given the true length of the string

_Note: if implementing in Java, implement the solution so that the operation is performed in-place on a character array._

#### Function Signature:

C++:

```c++
char* urlify(char* str[], int length);
```

Java:

```java
char[] urlify(char[] arr, int length) {}
```

### 2. Coins

Source: TODO :bug:

**Scenario:** 

Problem Statement TODO :bug:

**Example Input:**

If the problem is simple enough, remove this section. TODO :bug:

**Function Signature:**

TODO :bug:

### 3. Unique Paths II

Source: TODO :bug:

**Scenario:** 

Problem Statement TODO :bug:

**Example Input:**

If the problem is simple enough, remove this section. TODO :bug:

**Function Signature:**

TODO :bug:

## Solutions

### 1. URLify

Source: CTCI 1.3

#### Optimal solution:

The solution that allows for in-place editing without extra memory allocation is a two-pass approach. The first pass determines how many spaces are in the string of interest, which tells us how many extra indeces we will need. The second pass, done in reverse, allows us to replace characters in the array without overwriting characters that we have not encountered yet.

The solution method in C++ is as follows:

```c++
char* urlify(char* str, int length) {
    // First pass: space counting
    int spaceCount = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') spaceCount++;
    }
    // Edge case: no replacement is needed
    if (spaceCount == 0) return str;
    // Second pass: replacement
    int newLength = length + (spaceCount * 2);
    int oldIdx = length - 1;
    for (int i = newLength - 1; i > 0; i--) {
        if (str[oldIdx] == ' ') {
            // replace with %20
            str[i] = '0';
            str[i-1] = '2';
            str[i-2] = '%';
            i = i - 2;
        } else {
            // replace with existing char
            str[i] = str[oldIdx];
        }
        oldIdx--;
        if (oldIdx == i) break;
    }
    return str;
}
```

#### Driver For Solution

A C++ implementation is available in the CTCI repository under `Spring-2019/string_manipulation/urlify/urlify.cpp`.

Compile and run the example like so:

```console
$ cd CTCI/Spring-2019/string_manipulation/urlify/
$ g++ -o test urlify.cpp
$ ./test
'hi there  '
'hi%20there'
'can I get a heal        '
'can%20I%20get%20a%20heal'
$
```

### 2. Coins

Source: TODO :bug:

**Naive/Simple Solution:** 

TODO :bug:

**Optimal solution:**

TODO :bug:

**Testing The Solutions:** OR **Driver For Solution**  

TODO :bug:

## 3. Unique Paths II

Source: TODO :bug:

**Naive/Simple Solution:** 

TODO :bug:

**Optimal solution:**

TODO :bug:

**Testing The Solutions:** OR **Driver For Solution**  

TODO :bug:


