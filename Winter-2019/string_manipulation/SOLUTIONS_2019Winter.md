# String Manipulation

Problems and solutions for String Manipulation session on January 25, 2019.

## Problems

### 1. Longest Unique Substring

Source: [LeetCode](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

#### Scenario

Given a string, find the length of the longest substring without repeating characters.

#### Example Input

Example 1:
```
    Input: "abcabcbb"
    Output: 3 
    Explanation: The answer is "abc", with the length of 3.
```

Example 2:
```
    Input: "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.
```

#### Function Signature

C++:

```c++
int longUniqueSubstring(string s);
```

Java:

```java
public int lengthOfLongestSubstring(String s) {}
```

### 2. Anagram Checker

Source: [GeeksForGeeks](https://www.geeksforgeeks.org/check-whether-two-strings-are-anagram-of-each-other/)

#### Scenario

Write a function to check whether two given strings are anagram of each other or not. An anagram of a string is another string that contains same characters, only the order of characters can be different.

#### Example Input

Example:

```
Input: “listen”, “silent”   Output: true
Input: “abc”, “xyz”         Output: false
```

#### Function Signature

C++:

```c++
bool isAnagram(string s1, string s2);
```

### 3. Mars SOS

Source: [HackerRank](https://www.hackerrank.com/challenges/mars-exploration/problem)

#### Scenario

A Mars Rover’s spaceship crashed on Mars! The rover sends a series of SOS messages to Earth for help.

Letters in some of the SOS messages are altered by cosmic radiation during transmission. Given the signal received by Earth as a string, , determine how many letters of the Mars Rover’s SOS messages have been changed by radiation.

#### Example Input

Example:

```
Input: "SOSTOT"         Output: 2
Input: "SOSSPSSQSSOR"   Output: 3
```

#### Function Signature

C++:

```c++
int marsExploration(string s);
```

## Solutions

### 1. Longest Unique Substring

Source: [LeetCode](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

#### Naive/Simple Solution

The naive solution consists of examining all possible substrings of the input string (ranging in length from 1 to `n` where `n` is the length of the input string). For each possible substring, construct a HashSet of the individual characters to determine if the substring consists entirely of unique characters.

This solution has a time complexity of `O(n^2)`.

#### Optimal Solution

The optimal solution employs a "sliding window" approach, so that the string is processed in linear time and the HashSet of unique characters is updated along the way.

The Java implementation of the method is given as follows:

```java
public int lengthOfLongestSubstring(String s) {
    int n = s.length();
    Set<Character> set = new HashSet<>();
    int ans = 0, i = 0, j = 0;
    while (i < n && j < n) {
        // try to extend the range [i, j]
        if (!set.contains(s.charAt(j))){
            set.add(s.charAt(j++));
            ans = Math.max(ans, j - i);
        }
        else {
            set.remove(s.charAt(i++));
        }
    }
    return ans;
}
```

#### Testing The Solutions

The executable Java drivers for the naive and optimized approaches are available under `Winter-2019/string_manipulation/longest_unique_substring`.

The output for the Java solution is:

```console
$ javac SlidingWindowLUS.java
$ java SlidingWindowLUS
abcabcbb: 3
bbbbb: 1
$
```

### 2. Anagram Checker

Source: [GeeksForGeeks](https://www.geeksforgeeks.org/check-whether-two-strings-are-anagram-of-each-other/)

#### Naive/Simple Solution

A Java implementation is provided which shows a solution of `O(N^2)` time and `O(N*log(N))` time. 

The more complex solution removes an individual character from the second string for each character in the first string; its complexity is due to the runtime of string concatenation.

The `N * log(N)` solution is achieved by sorting the corresponding character arrays of each string and then comparing the sorted arrays for equality. The sort complexity determines the runtime complexity in this case.

#### Optimal Solution

A third optimized solution to this problem is available. The general algorithm is as follows:

```
Create two Map<char> objects
For each character c in s1:
    If c is not a key in map1, add map1[c] = 1
    Else increment map1[c] by one
For each character c in s2:
    If c is not a key in map2, add map2[c] = 1
    Else increment map2[c] by one
Compare maps for equality
```

This solution runs in `O(M+N)` time.

The solution method in C++ is as follows:

```c++
// method definition for solution
bool is_anagram(string s1, string s2) {
    // create map of first string
    map<char, int> map1;
    for (int i = 0; i < s1.length(); i++) {
        try {
            int current = map1.at(s1[i]);
            map1[s1[i]] = current + 1;
        } catch (out_of_range exc) {
            map1[s1[i]] = 1;
        }
    }
    // create map of second string
    map<char, int> map2;
    for (int i = 0; i < s2.length(); i++) {
        try {
            int current = map2.at(s2[i]);
            map2[s2[i]] = current + 1;
        } catch (out_of_range exc) {
            map2[s2[i]] = 1;
        }
    }
    // compare maps; return true when maps are equal
    return map1 == map2;
}
```

#### Testing The Solutions

Executable Python, Java, and C++ solutions are available under `Winter-2019/string_manipulation/anagram_checker`.

The output for the C++ executable is:

```console
$ g++ -o test anagram.cpp
$ ./test
Anagrams? 'banana' and 'aaannb': true
Anagrams? 'debit card' and 'bad credit': true
Anagrams? 'fancy' and 'crafty': false
Anagrams? 'schoolmaster' and 'the classroom': false
$
```

### 3. Mars SOS

Source: [HackerRank](https://www.hackerrank.com/challenges/mars-exploration/problem)

#### Optimal Solution

The problem can be solved in linear time.

Declare a string `sos = "SOS"` and a counter variable. Iterate over the argument string, and compare the current character at index `i` with `s[i % 3]`. If these two characters are not the same, increment the counter.

The solution method for Python is as follows:

```python
def marsExploration(s):
    sos = "SOS"
    count = 0
    for idx,val in enumerate(s):
        if s[idx] != sos[idx % 3]: 
            count += 1
    return count
```

#### Testing The Solutions

The executable Python implementation is available under `Winter-2019/string_manipulation/mars_sos/mars.py`.

The output of the Python solution is:

```console
$ python mars.py
SOSSOSSOS: 0
SOSSPSSQSSRS: 3
SOSTOT: 2
FUNHATSOL: 7
$
```
