# String Manipulation

Problems and solutions for String Manipulation session on October 18, 2019.

## Problems

### 1. Palindrome Permutation:

Source: CTCI 6th edition 1.4

#### Scenario

Given a string, write a function to check if it is a permutation of a palindrome. 
A palindrome is a word or phrase that is the same forwards and backwards. 
A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

#### Example Input

EXAMPLE
Input: Tact Coa
Output: True (permutations:"taco cat'; "atco cta '; etc)

#### Function Signature

java:
```
boolean isPermutationOfPalindrome(String phrase) {

}
```

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

### 3. Longest Substring

Source: [GeeksForGeeks](https://www.geeksforgeeks.org/longest-common-substring-dp-29/)

#### Scenario

Given two strings, find the longest common substring between them.

#### Example Input

_Example 1:_

```
s1: "123"
s2: "312"
```

Output: `12` is the common substring and `[0, 1]` 
is the inclusive character range of the substring's location in `s1`.

_Example 2:_

Input: 

```
s1: "hi this is a sentence"
s2: "you might not like it but this is a hrng;lsdkfja;lkejs;ldj"
```

Output: ` this is a ` is the common substring and `[2, 12]` is the inclusive 
character range of the substring's location in `s1`.

#### Function Signature

Design the function signature to return the most useful result. 
Yes, this is left as an exercise to you.

## Solutions

### 1. Palindrome Permutation

Source: CTCI 6th edition 1.4

#### Solution #1

Implementing this algorithm is fairly straightforward. We use a hash table to count how many times each character 
appears. Then, we iterate through the hash table and ensure that no more than one character has an odd count.

*Note: this solution hand-implements a hash table to illustrate the solution; an equivalent solution using 
Java libraries would make use of Java's `HashMap<char, int>`, `Character.toLowerCase()`, and `Character.isLetter()` 
utilities.*

Solution (java):

```java
boolean isPermutationOfPalindrome(String phrase) { 
    int[] table = buildCharFrequencyTable(phrase); 
    return checkMaxOneOdd(table);
}

/* Check that no more than one character has an odd count. */
boolean checkMaxOneOdd(int[] table) {
    boolean foundOdd = false;
    for(int count:table) {
        if(count % 2 == 1) {
            if(foundOdd) {
                return false;
            }
            foundOdd = true;
        }
    }
    return true;
}

/* Map each character to a number.a-)0Jb-)IJC-) 2Jetc. 
* This is case insensitive. Non-letter characters map to -1. */
int getCharacterNumber(Character c) {
    int a = Character.getNumericValue('a');
    int z = Character.getNumericValue('z');
    int val = Character.getNumericValue(c);
    if (a <= val && val <= z) {
        return val - a;
    }
    return -1;
}

/* Count how many times each character appears. */ 
int[] buildCharFrequencyTable(String phrase) {
    int[] table = new int[Character.getNumericValue('z') - Character.getNumericValue('a') + 1];
    for(char c : phrase.toCharArray()) {
        int x = getCharacterNumber(c);
        if(x != -1) {
            table[x]++;
        }
    }
    return table;
}
```
This algorithm takes `O(N)` time, where `N` is the length of the string.

#### Solution #2

We can't optimize the big 0 time here since any algorithm will always have to look through the entire string. 
However, we can make some smaller incremental improvements. Because this is a relatively simple problem, it can be 
worthwhile to discuss some small optimizations or at least some tweaks. Instead of checking the number of odd counts 
at the end, we can check as we go along. Then, as soon as we get to the end, we have our answer.

```java
boolean isPermutationOfPalindrome(String phrase) {
    int countOdd = 0;
    int[] table = new int[Character.getNumericValue('z') - Character.getNumericValue('a') + 1];
    for(char c : phrase.toCharArray()) {
        int x = getCharNumber(c);
        if(x != -1) {
            table[x]++;
            if(table[x] % 2 == 1) {
                countOdd++;
            } else {
                countOdd--;
            }
        }
    }  
    return countOdd <= 1;          
}

```
It's important to be very clear here that this is not necessarily more optimal. It has the same big 0 time and might 
even be slightly slower. We have eliminated a final iteration through the hash table, but now we have to run a few 
extra lines of code for each character in the string. You should discuss this with your interviewer as an alternate, 
but not necessarily more optimal, solution.


#### Solution #3

If you think more deeply about this problem, you might notice that we don't actually need to know the counts.We just 
need to know if the count is even or odd. Think about flipping a light on/off (that is initially off). If the light 
winds up in the o f f state, we don't know how many times we flipped it, but we do know it was an even count.

Given this, we can use a single integer (as a bit vector). When we see a letter, we map it to an integer between 0 and 
26 (assuming an English alphabet). Then we toggle the bit at that value. At the end of the iteration, we check that at 
most one bit in the integer is set to 1. 

We can easily check that no bits in the integer are 1: just compare the integer
to o. There is actually a very elegant way to check that an integer has exactly one bit set to 1. 

Picture an integer like 00010000. We could of course shift the integer repeatedly to check that there's only a single 1.
Alternatively, if we subtract 1 from the number, we'll get 00001111. What's notable about this is that there is no 
overlap between the numbers (as opposed to say 00101000, which, when we subtract 1 from, we get 00100111.) So, we can 
check to see that a number has exactly one 1 because if we subtract 1 from it and then AND it with the new number, 
we should get 0.

`00010000 - 1 = 00001111`

`00010000 & 00001111 = 0`

This leads us to our final implementation.

```java
boolean isPermutationOfPalindrome(String phrase) {
    int bitVector = createBitVector(phrase) ;
    return bitV ector == 6 || checkExactlyOneBitSet(bitVector);
}

/* Create a bit vector for the string. For each letter with value 1, toggle the
* ith bit. */
int createBitVector(String phrase) {
    int bitVector = 0;
    for(char c : phrase.toCharArray()) {
        int x = getCharNumber(c);
        bitVector = toggle(bitVector, x);
    }
    return bitVector;
}

/* Toggle the ith bit in the integer. */
int toggle(int bitVector, int index) { 
    if (index < 6) return bitVector;
    int mask = 1 << index;
    if ((bitVector & mask) == 0) {
        bitVector |= mask;
    } else {
        bitVector &= ~mask;
    }
    return bitVector;
}

/* Check that exactly one bit is set by subtracting one from the integer and
* ANDing it with the original integer. */ 

boolean checkExactlyOneBitSet(int bitVector) {
    return (bitVector & (bitVector - 1)) == 6; 
}
```
Like the other solutions, this is `O( N).`
It's interesting to note a solution that we did not explore. We avoided solutions along the lines of "create all 
possible permutations and check if they are palindromes:'While such a solution would work, it's entirely infeasible in 
the real world. Generating all permutations requires factorial time (which is actually worse than exponential time), 
and it is essentially infeasible to perform on strings longer than about 10- 15 characters.

I mention this (impractical) solution because a lot of candidates hear a problem like this and say, "In order to check 
if A is in group B, I must know everything that is in Band then check if one of the items equals A:' That's not always 
the case, and this problem is a simple demonstration of it. You don't need to generate all permutations in order to 
check if one is a palindrome.

#### Testing The Solutions

The executable java solution for this problem is located under:
`2019-03-Autumn/2_string_manipulation/palindrome_permutation`

The output for the Java solution is:

```console
$ javac Palindrome_Test.java
$ java Palindrome_Test
Solution Results:

test of string: Step on no pets
result = true

test of string: No lemon, no melon
result = true

test of string: Mississippi
result = true

test of string: aacbb
result = true

test of string: a cat I saw was it
result = true

test of string: 01010101010
result = true

test of string: Tact Coa
result = true

test of string: Step on some ramen
result = false

test of string: No lemon, service
result = false

test of string: Rpairing
result = false

test of string: Maden
result = false

test of string: Wiki
result = false

test of string: ham and cheese
result = false

```

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

### 3. Longest Substring

Source: [GeeksForGeeks](https://www.geeksforgeeks.org/longest-common-substring-dp-29/)

#### Simple Solution 

A naive approach to solving this problem takes the following steps:

```
1. Find all possible substring combinations of s1
2. For each substring, check whether that substring exists in s2.
3. Return identifiers for the longest substring that was found.
```

A code implementation in Python is as follows:

```python3
# a naive implementation
def longest_substring(s1: str, s2: str) -> tuple:
    indeces = (-1, -1)
    # get all possible substrings in s1
    length = len(s1)
    for i in range(length):
        for j in range(i, length):
            # for each possible substring, check for presence in s2
            substr = s1[i : j + 1]
            if _check_substring(substr, s2) and len(substr) >= indeces[1] - indeces[0]:
                indeces = (i, i + len(substr))
    return indeces

# helper function
def _check_substring(substr: str, s2: str) -> bool:
    # search s2 for desired substring
    for i in range(len(s2) - len(substr) + 1):
        if s2[i : i + len(substr)] == substr:
            return True
    return False

```

This strategy has an average-case time complexity of `O(n * m^2)` 
where `m` is `len(s1)` and `n` is `len(s2)`. In this Python 
implementation, our complexity is even more greedy because string slicing 
is a linear-time operation.

We want to do better than this if we can, though the techniques to do 
so are much less intuitive.

#### Optimized Solution

Two additional strategies exist to improve on our naive solution:

1. Use memoization to record solutions to previous subproblems.
2. Use a suffix tree.

We will discuss the memoization strategy; investigating suffix trees 
is left as an exercise to interested students.

##### What is "Memoization"?

Memoization is a strategy from **dynamic programming**.

When we solve a small subset of a problem, we would like to have easy 
access to this solution so that we don't have to resolve the problem 
all over again later. This goes to the heart of **memoization**: we create 
a mechanism to reference the same solution later.

##### Using Memoization in This Solution

Our memoization strategy is to record the number of consecutive 
preceding characters for each possible comparison between `s1` and `s2`. 

Because this comparison must be made for each combination of indeces in `s1` 
and `s2`, we will use a 2-dimensional array to store these values. 

When we can reference this array which we will call `found`, we can 
perform the following steps:

1. Loop over `s1` and `s2` to get all possible index combinations (`i` and `j`)
2. For each index pair:
    a. If either `i` or `j` is `0`, we can't possibly check preceding characters, so we enter `0` in `found[i][j]`
    b. Otherwise, if `s1[i] == s2[j]`, we have found part of a common substring.
    c. If we have a common substring, we check the preceding character pair `s1[i - 1]` and `s2[j - 1]`; if these are equal, the substring extends to previous characters. We take the value in `found[i - 1][j - 1]`, add 1 to it, and store it in `found[i][j]`.
    d. If `s1[i] != s2[j]`, we store `0` in `found[i][j]`.
    e. Last but not least, we want to update our `result` value if `s1[i] == s2[j]` and our previous `result` value represents a shorter string. We can easily use the value in `found[i][j]` to determine the substring's length, the indeces of the substring's location, or the substring itself. The implementation of this is dependent on what you chose to return from the function; the example provided here returns the index bounds of the substring in `s1` so we can produce any of the 3 interesting outputs.

A Python implementation of this is as follows:

```python3
# an implementation with memoization
def longest_substring_dynamic(s1: str, s2: str, found: list) -> tuple:
    indeces = (-1, -1)
    for i in range(len(s1)):
        for j in range(len(s2)):
            # base case: beginning of string, can't check previous chars
            if i == 0 or j == 0:
                found[i][j] = 0
            # general case: check for identical neighbors in each string
            elif s1[i] == s2[j] and s1[i - 1] == s2[j - 1]:
                # increment if characters are consecutive
                found[i][j] = found[i - 1][j - 1] + 1
            # failure case: consecutive char count resets
            else:
                found[i][j] = 0
            indeces = (i - found[i][j], i + 1) if found[i][j] + 1 >= indeces[1] - indeces[0] and s1[i] == s2[j] else indeces
    return indeces
```

#### Driver For Solution

[The solution functions are located here](./longest_substring/solution.py), and [the solution driver is here](./longest_substring/driver.py).

The output of the provided solution is as follows:

```console
$ python3 driver.py
S1: s1
S2: s2
Naive solution:		Indeces: (0, 1)	Substring: 's'
Dynprog solution:	Indeces: (0, 1)	Substring: 's'

S1: 
S2: 123
Naive solution:		Indeces: (-1, -1)	Substring: 'None'
Dynprog solution:	Indeces: (-1, -1)	Substring: 'None'

S1: BADBADNOTGOODFlightoftheConchordsRivalConsolesFourTetAesopRock
S2: RivalConsolesAesopRockFlightoftheConchordsBADBADNOTGOOD
Naive solution:		Indeces: (13, 33)	Substring: 'FlightoftheConchords'
Dynprog solution:	Indeces: (13, 33)	Substring: 'FlightoftheConchords'

S1: hi this is a sentence
S2: you might not like it but this is a hrng;lsdkfja;lkejs;ldj
Naive solution:		Indeces: (2, 13)	Substring: ' this is a '
Dynprog solution:	Indeces: (2, 13)	Substring: ' this is a '

S1: 123
S2: 312
Naive solution:		Indeces: (0, 2)	Substring: '12'
Dynprog solution:	Indeces: (0, 2)	Substring: '12'

S1: 1s
S2: 193587s
Naive solution:		Indeces: (1, 2)	Substring: 's'
Dynprog solution:	Indeces: (1, 2)	Substring: 's'

S1: x;lakfjaduwbothellacmafscrackingthecodinginterview
S2: codingwithuwbothellacm
Naive solution:		Indeces: (9, 21)	Substring: 'uwbothellacm'
Dynprog solution:	Indeces: (9, 21)	Substring: 'uwbothellacm'

S1: abcdefg1
S2: hijklmnopqrstuv1
Naive solution:		Indeces: (7, 8)	Substring: '1'
Dynprog solution:	Indeces: (7, 8)	Substring: '1'
```
