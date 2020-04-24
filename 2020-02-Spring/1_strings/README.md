<!-- Don't remove -->
<a name="top"/>

# Strings

Simple description TODO :bug:

In the style of:
***Problems and solutions for Maze & Dynamic Programming session on March 1, 2019.***

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

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

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

### 3. PROBLEM 3 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

<!-- Don't remove -->
Go to [Solution](#s3)   [Top](#top)

<!-- Don't remove -->
<a name="solutions"/>

## Solutions

<!-- Don't remove -->
<a name="s1"/>

### 1. SOLUTION 1 TODO :bug:

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
<summary>Click to see solution 2</summary>

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
<summary>Click to see solution 1</summary>

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
<summary>Click to see solution 2</summary>


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

### 3. SOLUTION 3 TODO :bug:

Source: TODO :bug:

#### Naive/Simple Solution 

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions OR Driver For Solution

TODO :bug:

<!-- Don't remove -->
Go to [Top](#top)
