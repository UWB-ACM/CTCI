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

### 2. GROUP ANAGRAMS:

Source:  [LeetCode](https://leetcode.com/problems/group-anagrams/)

#### Scenario

Given an array of strings, group anagrams together.

All inputs will be in lowercase.

The order of your ouput does not matter.

#### Example Input

```
Input = ["eat","tea","tan","ate","nat","bat"]

Output = [
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
```

#### Function Signature

Java:
```
public List<List<String>> groupAnagrams(String[] strs){
	//Your code here
}
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

### 2. GROUP ANAGRAMS

Source:  [LeetCode](https://leetcode.com/problems/group-anagrams/)

Two strings are anagrams if their sorted strings are equal. Then, one way
to solve this problem is by categorizing by sorting arrays.

1. Check for an empty array, if the array is not empty, then use a hashtable
where the key is the sorted string, and the value is the string that once is sorted, 
it matches the key.

2. Iterate through the array of strings. For each string in the array of strings,
create an array of chars, using the .toCharArray() function. 

3. Sort the char array, and convert it into a string. This string will be used as the
key for the key-value pair of the hashtable.

4. If the hashtable does not contains the key(string value of sorted char array), add it to the map. 

5. Add the original (unsorted) string as a new value of the key.
 
6. Return the list of list of anagrams

```
 public static List<List<String>> groupAnagrams(String[] strs) {
        if (strs.length == 0){
            return new ArrayList<>();
        }
        
        Map<String, List> map = new HashMap<>();
        
        for (String st:strs){
            
            char[] chars = st.toCharArray();
            
            Arrays.sort(chars);
            
            String key = String.valueOf(chars); // Converting the sorted char sequence into string
            
            if (!map.containsKey(key)) {
                map.put(key, new ArrayList());
            }
            
            map.get(key).add(st);
        }
        return new ArrayList(map.values());
    }
	```
Time Complexity: The outer loop has complexity O(N) as we iterate through each string. 
Then, we sort each string in O(K log K) time, where K is the length of each string.
For many entries, we can assume K is the average length, resulting in a total complexity
of O(N * K log K). However, K can be treated as a constant if we take it as the average 
string length in our array. Then, N would be the best (greater) complexity indicator,
resulting in complexity of O( N log N).

Space Complexity: O(N)

#### Optimal Solution

Two strings are anagrams only if the characters counts are the same. 

Another way to solve this problem is by transforming each string into a character count 
"count", consisting of 26 non-negative integers representing the 
number of times each character occurs in each string. 

We can transform each string s into a character count, count, consisting of 26 non-negative
integers representing the number of a's, b's, c's, etc. 
We use these counts as the basis for our hash map.

In Java, the hashable representation of our count will be a string delimited with '#' characters.
For example, abbccc will be #1#2#3#0#0#0...#0 where there are 26 entries total.

```java
public static List<List<String>> groupAnagramsOpt(String[] strs) {
    if (strs.length == 0) {
        return new ArrayList<>();
    }
    Map<String, List<String>> map = new HashMap<>();    
    for (String st:strs) {
        char[] chars = st.toCharArray();    
        Arrays.sort(chars);    
        String key = String.valueOf(chars); // Converting the sorted char sequence into string    
        if (!map.containsKey(key)) {
            map.put(key, new ArrayList<String>());
        }    
        map.get(key).add(st);
    }
    return new ArrayList(map.values());
}
```

Time Complexity: O(NK). Counting every string in the array is O(N), and counting each character
in each string is O(K), where K is the max length of a string in the string array.

Space Complexity: O(N)

#### Testing The Solutions OR Driver For Solution

[Available in the repository.](./2_string_manipulation/2. Anagrams/Anagram.java)


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
