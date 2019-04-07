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

### 3. Unique Paths II

Source: TODO :bug:

**Scenario:** 

Problem Statement TODO :bug:

**Example Input:**

If the problem is simple enough, remove this section. TODO :bug:

**Function Signature:**

TODO :bug:

## Solutions

### 1. Array Products

Source: http://www.crazyforcode.com/array/

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

```
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

The naive solution to this problem will iterate over the entire array regardless of whether the sorted quality of the array tells us whether it would be fruitful to keep searching.

There are a few edge cases that can be considered when writing an optimized solution to the problem:
- Is the `searchItem` greater than the maximum element of the array?
- Would the `searchItem` belong between the current index and previous index?
- If the `searchItem` is smaller than the current element, has the "rotation point" of the array been found yet?

The optimized solution is as follows:

```c++
int rotatedSearchOptimized(int searchItem, int arr[], int size) {
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

#### Testing The Solutions

The executable C++ solution for this problem is located under `Spring-2019/arrays_sorting/rotated_search/RotatedSearch.cpp`.

The output for the C++ solution is:

```
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

## 3. Unique Paths II

Source: TODO :bug:

**Naive/Simple Solution:** 

TODO :bug:

**Optimal solution:**

TODO :bug:

**Testing The Solutions:** OR **Driver For Solution**  

TODO :bug:


