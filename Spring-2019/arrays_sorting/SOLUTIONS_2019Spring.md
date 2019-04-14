# Arrays and Sorting

Problems and solutions for Arrays & Sorting session on April 12, 2019.

## Problems

### 1. Array Products

Source: [Crazy for Code](http://www.crazyforcode.com/array/)

#### Scenario:

Given an array of `n` integers where `n > 1`, return an array where each index contains the integer product of all items in the original array except the integer at the given index.

#### Function Signature:

C++:

```c++
#include <vector>
using namespace std;

vector<int> arrayProduct(vector<int> start);
```

Java:

```java
public int[] arrayProduct(int[] start) {}
```

### 2. Search in Rotated Array

Source: CTCI 10.3

#### Scenario:

Given a sorted array of `n` integers that has been rotated an unknown number of times, write code to find an element in the array.

#### Example Input:

Find `5` in `[15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14]`

#### Function Signature:

C++:

```c++
int rotatedSearch(int arr[], int size);
```

Java:

```java
int rotatedSearch(int[] arr) {}
```

### 3. Zero Matrix

CTCI 1.8

#### Scenario

Write an algorithm such that if an element in an `M x N` matrix is 0, its entire row and column are set to 0.

#### Example Input

```
[ [ 1  4  -3 2  5 ]
  [ 2  0  4  6  3 ]
  [ 10 12 6  4  9 ] ]
```

After running a valid solution, the matrix would become:

```
[ [ 1  0  -3 2  5 ]
  [ 0  0  0  0  0 ]
  [ 10 0  6  4  9 ] ]
```


#### Function Signature

C++:

```c++
#include <vector>
using namespace std;

vector<vector<int>*>* zeroes(vector<vector<int>*>*);
```

Java:

```java
int[][] zeroes(int[][] arr) {}
```

## Solutions

### 1. Array Products

Source: [Crazy for Code](http://www.crazyforcode.com/array/)

#### Naive/Simple Solution

Pseudocode:
```
for item in original:
    product = 1
    for all other items in original:
        product *= other item value
    append product to new array
```

The time complexity of this solution is `O(N^2)`.

#### Optimal Solution

The optimal solution for this problem only calculates the array's product once, and divides the total product by the value in the original array to find the correct value for the resulting array.

The time complexity of this solution is `O(N)`.

_Note: this implementation requires special handling of an edge case: one or more zeroes in the original array._

```java
// Solution Method Definition
// Note: this is the optimized solution
public int[] arrayProduct(int[] start) {
    int total = 1;
    int nonZeroTotal = 1;
    int zeroCount = 0;
    // get total product of array
    for (int i = 0; i < start.length; i++) {
        if (start[i] == 0) {
            zeroCount++;
            total = 0;
        } else {
            total *= start[i];
            nonZeroTotal *= start[i];
        }
    }
    // create new array to store result
    int[] result = new int[start.length];
    for (int i = 0; i < start.length; i++) {
        if (start[i] == 0) {
            if (zeroCount == 1) {
                result[i] = nonZeroTotal;
            } else {
                result[i] = 0;
            }
        } else {
            result[i] = total / start[i];
        }
    }
    return result;
}
```

#### Testing The Solutions

The executable Java solution for this problem is located under `Spring-2019/arrays_sorting/product_of_array/GetProduct.java`.

The output for the Java solution is:

```console
$ javac GetProduct.java
$ java GetProduct
Original is:	1 2 3 4 5 6 
Result is:	720 360 240 180 144 120 
Original is:	2 5 9 1 0 6 -3 12 -1 
Result is:	0 0 0 0 19440 0 0 0 0 
$
```

### 2. Search in Rotated Array

Source: CTCI 10.3

#### Naive/Simple Solution

The naive solution iterates over the entire array and checks whether the current index contains the search item.

```c++
int rotatedSearch(int searchItem, int arr[], int size) {
    int result = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchItem) {
            result = i;
            break;
        }
    }
    return result;
}
```

#### Optimal Solution

There are two approaches to creating an optimal solution to this problem. 

**Approach #1: Improving the Naive Solution**

The naive solution to this problem will iterate over the entire array regardless of whether the sorted quality of the array tells us whether it would be fruitful to keep searching.

There are a few edge cases that can be considered when writing an improved solution to the problem:
- Is the `searchItem` greater than the maximum element of the array?
- Would the `searchItem` belong between the current index and previous index?
- If the `searchItem` is smaller than the current element, has the "rotation point" of the array been found yet?

The improved solution is as follows:

```c++
int rotatedSearchImproved(int searchItem, int arr[], int size) {
    int result = -1;
    bool cycle = false;
    int max;
    for (int i = 0; i < size; i++) {
        if (i > 0 && arr[i] < arr[i - 1]) {
            cycle = true;
            max = arr[i - 1];
            if (searchItem > max) break;
        }
        else if (cycle && arr[i] > searchItem) break;
        else if (i > 0 && arr[i] > searchItem && arr[i - 1] < searchItem) break;
        if (arr[i] == searchItem) {
            result = i;
            break;
        }
    }
    return result;
}
```

This solution has more conditionals at each index step, but allows the search to terminate as soon as is practical, which can lead to significant gains in search time when the array's size is very large.

**Approach #2: Binary Search of the Array**

A binary search of the array is the most efficient solution, with the runtime complexity being `O(log N)` if all elements are unique.

Duplicate items cause the runtime complexity to increase up to `O(N)`.

The basic premise of the solution is the same as standard binary search techniques, but handling the unknown rotation points and duplicate items complicates the logic slightly.

Here is the code for the optimal solution using binary search:

```c++
// Most optimal solution for problem: Binary Search
int rotatedBinarySearch(int arr[], int left, int right, int searchItem) {
    // find the midpoint between the left and right indeces
    int mid = (left + right) / 2;
    // element has been found
    if (searchItem == arr[mid]) return mid;
    // smallest possible increment of the array has been processed
    if (right < left) return -1;

    // We know, because the array is sorted, that the LHS or RHS of
    // the array must be normally ordered.
    // Use the bounds of the normally ordered half to determine which 
    // half should be searched for the desired value.
    if (arr[left] < arr[mid]) {         // LHS is normally ordered
        if (searchItem >= arr[left] && searchItem < arr[mid]) {
            // searchItem is within left-mid range; search this range
            return rotatedBinarySearch(arr, left, mid - 1, searchItem);
        } else {
            // if searchItem is not within ordered LHS range, search RHS
            return rotatedBinarySearch(arr, mid + 1, right, searchItem);
        }
    } else if (arr[mid] < arr[left]) {        // RHS is normally ordered
        if (searchItem > arr[mid] && searchItem <= arr[right]) {
            // searchItem is within mid-right range; search here
            return rotatedBinarySearch(arr, mid + 1, right, searchItem);
        } else {
            // if searchItem is not within ordered RHS range, search LHS
            return rotatedBinarySearch(arr, left, mid - 1, searchItem);
        }
    } else if (arr[left] == arr[mid]) {     // edge case: LHS or RHS is entirely repeated items
        if (arr[mid] != arr[right]) {
            return rotatedBinarySearch(arr, mid + 1, right, searchItem);
        } else {        // both halves should be searched here
            int result = rotatedBinarySearch(arr, left, mid - 1, searchItem);
            if (result == -1) {
                return rotatedBinarySearch(arr, mid + 1, right, searchItem);
            } else {
                return result;
            }
        }
    }
    return -1;
}
```

#### Testing The Solutions

The executable C++ solution for this problem is located under `Spring-2019/arrays_sorting/rotated_search/RotatedSearch.cpp`.

The output for the C++ solution is:

```console
$ g++ -o test RotatedSearch.cpp
$ ./test
Input array: [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14]
Searched for 5	Found at 8
Optimized solution terminated at index 8

Input array: [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14]
Searched for 22	Found at -1
Optimized solution terminated at index 4

Input array: [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14]
Searched for 0	Found at -1
Optimized solution terminated at index 6

Input array: [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14]
Searched for 14	Found at 11
Optimized solution terminated at index 11

Input array: [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14]
Searched for 144	Found at -1
Optimized solution terminated at index 5

$
```

### 3. Zero Matrix

CTCI 1.8

#### Solution

At first glance, it is tempting to loop through the entire matrix, nullifying rows and columns as you go. However, this leads to rows and columns being nullified further in the process when the original matrix does not dictate that to happen! The question becomes how to track the rows and columns that need to be nullified before the array is changed.

A simple solution that utilizes more space is to track the index pairs of rows and columns to process in a `vector` or `list` structure, and then nullify those rows and columns later. However, this solution increases the space complexity of our solution substantially (up to `O(MxN)` additional space being allocated).

The more elegant solution is to change the column and row headers in-place and then nullify rows and columns based on the headers. This requires special handling of zeroes in the first row and column, but reduces the space complexity of the solution.

Here is the solution method:

```java
// Method definition for solution
public int[][] zeroes(int[][] arr) {
    // Edge case: empty array
    if (arr.length == 0 || arr[0].length == 0) {
        return arr;
    }
    boolean nulCol0 = false;
    boolean nulRow0 = false;
    // First, locate zeroes in the matrix, and replace row/col header 
    // with zeroes when they occur for indeces 1-m and 1-n.
    // Replacement in this fasion will let us go back to the first 
    // row and first column of the matrix to replace full row/col.
    for (int i = 0; i < arr.length; i++) {
        for (int j = 0; j < arr[0].length; j++) {
            if ((i == 0 || j == 0) && arr[i][j] == 0) {
                // we need to know whether to nullfiy the first 
                // row or first column
                if (i == 0) nulRow0 = true;
                if (j == 0) nulCol0 = true;
            } else if (arr[i][j] == 0) {
                arr[0][j] = 0;
                arr[i][0] = 0;
            }
        }
    }
    // Now that our first row and column has zeroes marking the 
    // rows and columns that require replacement, iterate over the 
    // first row and first column to replace the respective column 
    // or row with zeroes.
    // NOTE: arr.length    ---> row index
    // NOTE: arr[0].length ---> column index
    // Nullify rows below row 0
    for (int i = 1; i < arr.length; i++) {
        if (arr[i][0] == 0) {
            for (int j = 0; j < arr[0].length; j++) {
                arr[i][j] = 0;
            }
        }
    }
    // Nullify all columns
    for (int i = 1; i < arr[0].length; i++) {
        if (arr[0][i] == 0) {
            for (int j = 0; j < arr.length; j++) {
                arr[j][i] = 0;
            }
        }
    }
    // if boolean conditional for first row/col was true, 
    // nullify first row or col respectively
    if (nulRow0) {
        for (int i = 0; i < arr[0].length; i++) {
            arr[0][i] = 0;
        }
    }
    if (nulCol0) {
        for (int i = 0; i < arr.length; i++) {
            arr[i][0] = 0;
        }
    }
    return arr;
}
```

#### Testing The Solutions

The executable Java solution for this problem is located under `Spring-2019/arrays_sorting/zero_matrix/ZeroMatrix.java`, with a utility class located in the same folder under `PrintUtil.java`.

The output for the Java solution is:

```console
$ javac *.java
$ java ZeroMatrix 
First Example: basic example
Printing Grid:
[ [   1   4  -3   2   5 ]
  [   2   0   4   6   3 ]
  [  10  12   6   4   9 ] ]
Printing Grid:
[ [   1   0  -3   2   5 ]
  [   0   0   0   0   0 ]
  [  10   0   6   4   9 ] ]

Second Example: 0 in arr[0][0]
Printing Grid:
[ [   0   3   6  18  44   2   9 ]
  [  19  12   3   2   4   9   9 ]
  [  66  -3   2   4  19   0   1 ]
  [   1   6  13   4  10  -3   2 ]
  [  14   8  19   2  66   2   9 ]
  [   5   2   1   3 666  22   1 ] ]
Printing Grid:
[ [   0   0   0   0   0   0   0 ]
  [   0  12   3   2   4   0   9 ]
  [   0   0   0   0   0   0   0 ]
  [   0   6  13   4  10   0   2 ]
  [   0   8  19   2  66   0   9 ]
  [   0   2   1   3 666   0   1 ] ]
Second Example: 0 in first row and first column (not [0][0]
Printing Grid:
[ [   3   6   9  12   0   4   2 ]
  [  14   6   3  22   5   2   4 ]
  [   0   2   9   6  14   3  11 ]
  [  -1   2   7   6   4   9   3 ] ]
Printing Grid:
[ [   0   0   0   0   0   0   0 ]
  [   0   6   3  22   0   2   4 ]
  [   0   0   0   0   0   0   0 ]
  [   0   2   7   6   0   9   3 ] ]

Third Example: null arrays
Printing Grid:
[  ]
Printing Grid:
[  ]
Printing Grid:
Printing Grid:
$
```
