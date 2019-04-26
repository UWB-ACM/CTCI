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

### 2. English Integer

Source: CTCI 16.8

#### Scenario

Given any integer, print an English phrase that describes the integer.

#### Example Input

Input: `-34682`

Output: `Negative Thirty Four Thousand Six Hundred Eighty Two`

#### Function Signature

C++:

```c++
#import <string>
using namespace std;

string englishInteger(int num);
```

Java:

```java
String englishInteger(int num) {}
```

## Solutions

### 1. URLify

Source: CTCI 1.3

#### Optimal solution

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

## 2. English Integer

Source: CTCI 16.8

#### Optimal solution

This is a tricky logic question that requires handling the integer value in specific ways. The logic is the emphasis over runtime complexity, though consideration of the complexity is always important.

The fundamental algorithm is as follows:

```
for (each grouping in [billion, million, thousands, n<1000]):
    determine the "triplet" value in that grouping (triplet >= 0)
    if triplet > 0:
        convert the "triplet" to an english integer
        add the suffix appropriate for the grouping
    decrement the original integer to reflect the processing of the "triplet"
```

A C++ implementation of the parent method `englishInteger()` is:

```c++
string englishInteger(int num) {
    stringstream s;
    // Special case: num is 0 (not handled in triplet function)
    if (num == 0) {
        s << "Zero";
        return s.str();
    }
    // Special case: if value is negative, print negative and convert 
    // to positive value for processing
    if (num < 0) {
        s << "Negative ";
        num *= -1;
    }
    // Due to the C/C++ Standard, most compilers only allow a maximum 
    // of ~2bn as an integer value. So, we will use these limits in our 
    // implementation.
    int marker = 1000000000;        // One billion
    string mString = "Billion ";    // Text value
    // Process number set until all increments have been converted to string
    while (num != 0) {
        // Get triplet value
        int val = num / marker;
        // Convert to string if triplet value is non-zero
        if (val > 0) {
            s << tripletString(val);
            s << mString;
        }
        // Subtract processed triplet from number argument
        num = num % marker;
        // Get next marker level down to determine triplet value in 
        // next occurence of while loop
        marker /= 1000;
        // For the next round of triplet values, set the triplet string 
        // to be the next grouping down (eg million -> thousand)
        if (marker == 1000000) mString = "Million ";
        else if (marker == 1000) mString = "Thousand ";
        else if (marker == 1) mString = "";

    }
    return s.str();
}
```

The C++ version of the "triplet" helper method is:

```c++
string tripletString(int triplet) {
    // Returns strings like:
    // Six Hundred Forty
    // Ninety Seven
    // Three Hundred Thirteen
    stringstream s;
    string small[10]{"", "One ", "Two ", "Three ", "Four ", "Five ", 
                     "Six ", "Seven ", "Eight ", "Nine "};
    string teens[10]{"Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", 
                     "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", 
                     "Nineteen "};
    string mults[10]{"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", 
                     "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    // Handle hundreds first
    if (triplet > 99) {
        int val = triplet / 100;
        s << small[val];
        s << "Hundred ";
    }
    // subtract hundreds multiple from triplet value
    triplet -= (triplet / 100) * 100;
    // Handle teens next (1-99)
    // NOTE: special case if 10 <= n <= 19
    if (triplet > 19) {
        s << mults[triplet / 10];
        // Subtract teens value from triplet
        triplet -= (triplet / 10) * 10;
        // s << small[triplet];
    } else if (triplet > 9) {
        s << teens[triplet - 10];
        // Subtract full value from triplet (since single term suffices)
        triplet -= triplet;
    }
    // Handle single digit values last (if n < 10 or n >= 20)
    if (triplet > 0) {
        s << small[triplet];
    }
    return s.str();
}
```

#### Driver For Solution

A C++ implementation is available in the CTCI repository under `Spring-2019/string_manipulation/english_integer/englishInt.cpp`.

Compile and run the example like so:

```console
$ cd CTCI/Spring-2019/string_manipulation/english_integer/
$ g++ -o test englishInteger.cpp
$ ./test
The maximum integer value for this environment is: 
2147483647
-3,841,182 is Negative Three Million Eight Hundred Forty One Thousand One Hundred Eighty Two 
765,800 is Seven Hundred Sixty Five Thousand Eight Hundred 
765,349,011 is Seven Hundred Sixty Five Million Three Hundred Forty Nine Thousand Eleven 
-89,001,001 is Negative Eighty Nine Million One Thousand One 
1,001,499,819 is One Billion One Million Four Hundred Ninety Nine Thousand Eight Hundred Nineteen 
$
```
