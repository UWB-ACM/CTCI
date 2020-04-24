<!-- Don't remove -->
<a name="top"/>

# String Manipulation

Practice solving string related problems. Session on April 24, 2020.

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

### 1. Reverse String

[LeetCode](https://leetcode.com/problems/reverse-string/)
#### Scenario

Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array **in-place** with O(1) extra memory.

You may assume that all array indices contain printable ASCII characters.

#### Example Input

**Input:** \["h","e","l","l","o"]

**Output:** \["o","l","l","e","h"]

#### Function Signature

**Java:**
```java
class Solution {
    public void reverseString(char[] s) {
       //Do not return anything, modify s in-place instead
    }
}
```

**Python:**
```python
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
```

<!-- Don't remove -->
Go to [Solution](#s1)   [Top](#top)

<!-- Don't remove -->
<a name="p2"/>

### 2. Sort Characters By Frequency

Source: [LeetCode](https://leetcode.com/problems/sort-characters-by-frequency/)

#### Scenario

Given a string, sort it in decreasing order based on the frequency of characters.

#### Example Input

**Input**: "tree"
**Output**: "eert"

**Input**: "cccaaa"
**Output**: "cccaaa" or "aaaccc"

**Input**: "Aabb"
**Output**: "bbAa"

#### Function Signature

Java: 

```java
public String frequencySort(String s) {
  // your code here
}

```

```python
def frequency_sort(s : str) -> str:
  # your code here
```

<!-- Don't remove -->
Go to [Solution](#s2)   [Top](#top)

<!-- Don't remove -->
<a name="p3"/>

### 3. Add Strings

Source: [Leetcode](https://leetcode.com/problems/add-strings/)

#### Scenario

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

* The length of both num1 and num2 is < 5100.
* Both num1 and num2 contains only digits 0-9.
* Both num1 and num2 does not contain any leading zero.
* **You must not use any built-in BigInteger library or convert the inputs to integer directly.**

#### Example Input

num1 = '0'; num2 = '0'; output = '0';
num1 = '123'; num2 = '9'; output = '132';

#### Function Signature

```c++
class Solution {
public:
    string addStrings(string num1, string num2) {
        
    }
};
```
<!-- Don't remove -->
Go to [Solution](#s3)   [Top](#top)

<!-- Don't remove -->
<a name="solutions"/>

## Solutions

<!-- Don't remove -->
<a name="s1"/>

### 1. Reverse String

Source: [LeetCode](https://leetcode.com/problems/reverse-string/solution/)
 
#### Optimal Solution

<details>
<summary>Click to see solution</summary>
 
**What does in-place mean?**

By definition, an in-place algorithm is an algorithm which transforms input using no auxiliary data structure.
 
**Two Pointers Approach:**

In this approach, two pointers are used to process two array elements at the same time. Usual implementation is to set one pointer in the beginning and one at the end and then to move them until they both meet.

**Algorithm:**

- Set pointer left at index 0, and pointer right at index n - 1, where n is a number of elements in the array.

- While left < right:

   - Swap char[left] and char[right].

   - Move left pointer one step right, and right pointer one step left.

**Java:**
```java
class Solution {
    public void reverseString(char[] s) {
        int left = 0, right = s.length - 1;
        while (left < right) {
            char tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
        }
    }
}

```

**Python:**

```python
class Solution:
    def reverseString(self, s):
        left, right = 0, len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left, right = left + 1, right - 1
```

**Complexity Analysis:**

Time complexity: O(N) to swap N/2 element.

Space complexity: O(1), it's a constant space solution.

</details>
 
#### Driver For Solution

See [Driver](./reverse_string/Driver.java)

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s2"/>

### 2. Sort Characters By Frequency Solution

#### Algorithm Overview

1. Count the number of times each character occurs in the string
2. Group the characters into strings with identical characters
3. Sort the strings by length in ascending order
4. Create the result string

There are many ways that you can do this. I've covered two solutions that use arrays and maps respectively, but you could also solve this using a priority queue.


**Immutability**

Remember to check if strings are immutable in your language of choice. If strings *are* immutable, you cannot modify them once they are created.

If you perform the following operation in Java:

```java
String websiteName = "This is a tomato site";
websiteName += " for tomato friends";
```

`websiteName` is never actually modified. Instead, an entirely new `String` is created which copies over every character in `websiteName`, throwing away the old `String`. This has a cost of `O(n)`.

Make sure to use `StringBuilder` or similar language constructs so your solution does not have this extra cost.


**Bucket Sort**

There is a way you can solve this problem in `O(n)` time complexity, using bucket sort. Knowing to use bucket sort probably isn't expected for an interview since it's a somewhat obscure sorting algorithm, but still fun to know.

#### Complexity Analysis

**Solution 1 (using arrays)**

* ***Time Complexity***: `O(n log n)`

    * `O(n)` - Converting String to a list of characters
    * `O(n log n)` - Sorting the list of characters lexigraphically
    * `O(n)` - Grouping characters into strings of identical characters
    * `O(n)` - Sorting strings by length (if all of the characters are unique, in the worst case)
    * `O(n)` - Building the result string

* ***Space Complexity***: `O(n)`

    * `O(n)` - Since Strings are immutable, we have to at least create a new string to return the result.

**Solution 2 (using maps)**

Suppose `n` is the length of the input string, and `k` is the number of unique characters in the string.

* ***Time Complexity***: `O(n log n)`

    * `O(n)` - Building the frequency map
    * `O(k log k)` Sorting the frequency map by frequency of character occurrence (large to small)
    * `O(n)` - Traversing over the frequency map keys and building the result string

In the worst case, `k = n`, so we can say the final worst-case time complexity is still `O(n log n)`.

* ***Space Complexity***: `O(n)`
    * `O(n)` - Since Strings are immutable, we have to at least create a new string to return the result. Note that the frequency map is `O(k)`, but that is dominated by `O(n)`.

##### Java

<details>
<summary>Click to see solution 1 (arrays)</summary>

```java
    public static String frequencySort1(String word) {
        // Edge case handling
        if (word == null || word.isEmpty()) {
            return word;
        }

        // Create an array of sorted characters 
        // [ 'h', 'e', 'l', 'l', 'o'] --> ['e', 'h', 'l', 'l' 'o']
        char[] chars = word.toCharArray();
        Arrays.sort(chars); // Sorts lexigraphically by default

        // Combine identical groups of characters into Strings
        // ['e', 'h', 'l', 'l', 'o'] --> ["e", "h", "ll", "o"]
        List<String> identicalGroups = new ArrayList<String>();
        StringBuilder group = new StringBuilder();
        group.append(chars[0]);
        for (int i = 1; i < chars.length; i++) {
            if (chars[i] != chars[i - 1]) {
                identicalGroups.add(group.toString());   // Add the group we just finished
                group = new StringBuilder();     // Start a new group of characters
            }
            group.append(chars[i]);
        }
        identicalGroups.add(group.toString());

        // Sort the groups of characters by length, from longest to shortest
        // ["e", "h", "ll", "o"] --> ["ll", "e", "h", "o"]
        Collections.sort(identicalGroups, (a, b) -> b.length() - a.length());
        
        // Combine the groups of characters into our final result
        // ["ll", "e", "h", "o"] --> "lleho"
        StringBuilder result = new StringBuilder();
        for (String s : identicalGroups) {
            result.append(s);
        }
        return result.toString();
    }
```
</details>


<details>
<summary>Click to see solution 2 (maps)</summary>

```java
    public static String frequencySort2(String word) {
        // Edge case handling
        if (word == null || word.isEmpty()) {
            return word;
        }

        // Create a frequency map that contains the number of times
        // each character occurs in the word
        // [ 't', 'r', 'e', 'e' ] --> { 't' : 1, 'r' : 1, 'e' : 2}
        Map<Character, Integer> counts = new HashMap<>();
        for (char ch : word.toCharArray()) {
            if (!counts.containsKey(ch)) {
                counts.put(ch, 1);
            } else {
                counts.put(ch, counts.get(ch) + 1);
            }
        }

        // Sort the characters by the number of times they occur
        // in ascending order
        // { 't' : 1, 'r' : 1, 'e' : 2} --> { 'e' : 2, 't' : 1, 'r' : 1 }
        List<Character> chars = new ArrayList<>(counts.keySet());
        Collections.sort(chars, (a, b) -> counts.get(b) - counts.get(a));

        // Combine the sorted key-value pairs into our final result
        // { 'e' : 2, 't' : 1, 'r' : 1 }  --> "eetr"
        StringBuilder result = new StringBuilder();
        for (Character ch : chars) {
            int repetitions = counts.get(ch);
            for (int i = 0; i < repetitions; i++) {
                result.append(ch);
            }
        }
        return result.toString();
    }

```

</details>


##### Python
<details>
<summary>Click to see solution 1 (arrays)</summary>

```python

def frequency_sort1(word : str) -> str:
    # Edge case handling
    if not word: return word

    # Create a list of sorted characters
    # [ 'h', 'e', 'l', 'l', 'o'] --> ['e', 'h', 'l', 'l' 'o']
    word = sorted(word)
    
    # Combine identical groups of characters into strings
    # ['e', 'h', 'l', 'l', 'o'] --> ["e", "h", "ll", "o"]
    identical_groups = []
    group = [ word[0] ]

    for ch in word[1:]:
        if group[-1] != ch:
            identical_groups.append("".join(group)) # Add the group we just finished
            group = []                              # Start a new group of characters
        group.append(ch)
    identical_groups.append("".join(group))

    # Sort the groups of characters by length, from longest to shortest
    # ["e", "h", "ll", "o"] --> ["ll", "e", "h", "o"]
    identical_groups.sort(key = lambda string : len(string), reverse = True)
    
    # Combine the groups of characters into our final result
    return "".join(identical_groups)

```


</details>


<details>
<summary>Click to see solution 2 (maps)</summary>


```python

def frequency_sort2(word : str) -> str:
    # Edge case handling
    if not word: return word

    # Create a frequency map that contains the number of times
    # each character occurs in the word
    # [ 't', 'r', 'e', 'e' ] --> { 't' : 1, 'r' : 1, 'e' : 2}
    counts = collections.Counter(word)

    # Sort the characters by the number of times they occur
    # in ascending order
    # { 't' : 1, 'r' : 1, 'e' : 2} --> { 'e' : 2, 't' : 1, 'r' : 1 }
    sorted_counts = counts.most_common()

    # Generate a list of strings with identical characters 
    # in their sorted order
    # Ex: 'e' * 2 --> 'ee'
    # { 'e' : 2, 't' : 1, 'r' : 1 } --> [ 'ee', 't', 'r' ]
    result = []
    for letter, count in sorted_counts:
        result.append(letter * count)

    # Combine the list of strings into our final result
    # ['ee', 't', 'r'] --> 'eetr'
    return "".join(result)

```

</details>

#### Tests for Solutions


##### Java

```java
    public static void main(String[] args) {
        System.out.println(frequencySort("hello"));    // Expected "eert" or "eetr"
        System.out.println(frequencySort("tree"));     // Expected "lleho", "llheo", "llohe", "lloeh", "lleoh", etc
        System.out.println(frequencySort("cccaaa"));   // Expected "aaaccc" or "cccaaa"
        System.out.println(frequencySort("Aabb"));     // Expected "bbAa"
        System.out.println(frequencySort(""));         // Expected ""
    }


```

##### Python

```python

def main():
    print(frequency_sort("hello"))  # Expected "eert" or "eetr"
    print(frequency_sort("tree"))   # Expected "lleho", "llheo", "llohe", "lloeh", "lleoh", etc
    print(frequency_sort("cccaaa")) # Expected "aaaccc" or "cccaaa"
    print(frequency_sort("Aabb"))   # Expected "bbAa"
    print(frequency_sort(""))       # Expected ""
    

if __name__ == "__main__":
    main()


```

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s3"/>

### 3. Add String

#### Optimal Solution

<details>
<summary>Click to see solution</summary>

C++ Solution

Since we are not allowed to use library tools to convert our strings to integers we can evaluate the last string values individually and build our answer forward with ASCII conversion. By starting our loop with the end values it allows us to build a new string that accounts for a resulting string that may be longer than arugument strings.

ASCII conversion translates that the string "0" equals the ASCII code of 48. This builds 1 single digit value equivilantly, up to ASCII value of 57 which equates to the string value of "9".

In each conditional if statement in our while loop, we check that there are more values to be parsed from the string. If so, we take the current string character and remove the ASCII value of '0', leaving us with an interger equivilant answer of that character. 

We add those 2 integer values together into sum and add in the value from our remain (if there is one). Next we create a value for remain by perform an integer division of 10, which results in 0 if our value sum is less than 10, or a number of 1-8 otherwise. 

Next we convert those values back to string by adding the string character "0" (which is ASCII 48) to the sum value modded by 10 (to give us a digit value).

The after we exit the while loop we simply reverse the string we have and return that answer.

```C++
class Solution {
public:
    string addStrings(string num1, string num2) {
    // create integers that represent strings length
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;
        int remain = 0;
        string ans;
        // loops through while any condition is true
        while(n1 >= 0 || n2 >= 0 || remain) {
        int d1;
        int d2;
        // checks if values are left in num1
            if (n1 >= 0){
            // if so- turn d1 into int diff of string ASCII and '0'
                d1 = num1[n1--] - '0';
                } else {
                d1 = 0;
            }
            // Ternary equivalent
            // int d1 = (n1 >= 0) ? num1[n1--] - '0' : 0;
            if (n2 >= 0){
                int d2 = num2[n2--] - '0';
                } else {
                int d2 = 0;
            }
            // Ternary equivalent
            // int d2 = (n2 >= 0) ? num2[n2--] - '0' : 0;
            
            int sum = d1 + d2 + remain;
            // remain is 0 in integer division if value is less than 10
            remain = sum/10;
            ans += '0' + (sum % 10); 
        }
        // reverse the string to form appropriate return value
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
</details>

#### Driver For Solution
See [Driver](./add_strings/AddStrings.cpp)

<!-- Don't remove -->
Go to [Top](#top)
