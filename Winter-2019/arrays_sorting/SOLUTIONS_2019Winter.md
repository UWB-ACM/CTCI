# Arrays and Sorting

Problems and solutions for Arrays & Sorting session on January 17, 2019.

## Problems

### 1. Two Sum

Source: [LeetCode](https://leetcode.com/problems/two-sum/) 

#### Scenario

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

#### Example Input

Example:

```
Input:   arr = [2, 7, 11, 15]     target = 9
Output:  [0, 1] because arr[0] + arr[1] = 2 + 7 = 9
```

#### Function Signature

Java:

```java
int[] twoSum(int[] arr, int target) {}
```

C++:

```c++
vector<int> twoSum(vector<int> arr, int target);
```

### 2. Rotate Matrix

Source: CTCI 1.7

#### Scenario

You are given an `n x n` 2D matrix representing an image. Rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

#### Example Input

Example:

```
[ [1,2,3],        output     [ [7,4,1],
  [4,5,6],        ----->       [8,5,2],
  [7,8,9] ]                    [9,6,3] ]
```

#### Function Signature

Java:

```java
void rotateMatrix(int[][] mtx) {}
```

C++:

```c++
void rotateMatrix(vector<vector<int>> mtx);
```

## Solutions

### 1. Two Sum

Source: [LeetCode](https://leetcode.com/problems/two-sum/) 

#### Naive/Simple Solution

TODO :bug:

#### Optimal Solution

TODO :bug:

#### Testing The Solutions

TODO :bug:

### 2. Rotate Matrix

Source: CTCI 1.7

#### Solution #1: Swapping

The most intuitive approach dictates that we cycle through the matrix, rotating the four corresponding points which share the same offset from their respective corners (accounting for the rotation).

This solution is a bit tricky to understand due to the way the four corresponding swap points are related to each other, but it is a very efficient solution.

The Python implementation is as follows:

```python
def rotate(mtx):
    length = len(mtx)
    # row iteration
    for i in range(length/2):
        # column iteration
        for j in range(i, length - i - 1):
            # now, we swap 4 items at a time
            # "top" item goes into temp variable
            tmp = mtx[i][j]
            # work backwards
            mtx[i][j] = mtx[length - j - 1][i]
            mtx[length - j - 1][i] = mtx[length - i - 1][length - j - 1]
            mtx[length - i - 1][length - j - 1] = mtx[j][length - i - 1]
            mtx[j][length - i - 1] = tmp
    return mtx
```

#### Solution #2: Transformation

An additional method of rotating the matrix borrows techniques from linear algebra. First, the elements are reflected about the matrix's diagonal, and then the order of the columns are reversed. 

Two simple examples are illustrated below:

```
Clockwise:
Reflect over y = x and reverse column order

       Reflect       Reverse  
1 2 3   ->    1 4 7     ->   7 4 1
4 5 6         2 5 8          8 5 2
7 8 9         3 6 9          9 6 3

Counterclockwise:
Reflect over y = x and reverse row order

       Reflect       Reverse
1 2 3   ->    1 4 7     ->   3 6 9
4 5 6         2 5 8          2 5 8
7 8 9         3 6 9          1 4 7
```

The solution for the clockwise implementation is as follows:

```java
public void rotate(int[][] matrix) {
    if (matrix == null || matrix.length <= 1) {
        return;
    }
    int n = matrix.length;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        int head = 0;
        int tail = n - 1;
        while (head < tail) {
            int temp = matrix[i][head];
            matrix[i][head] = matrix[i][tail];
            matrix[i][tail] = temp;
            head++;
            tail--;
        }
    }
}
```

#### Testing The Solutions

The solutions for both of these techniques are available in `Winter-2019/arrays_sorting/rotate_matrix/`. The swapping method is in `rotate.py` and the transformation method is available in `RotateMatrix.java`. 

The output for both methods are as follows:

```console
$ python rotate.py
Before:
1 2 3 
4 5 6 
7 8 9 
After:
7 4 1 
8 5 2 
9 6 3 
$ javac RotateMatrix.java
$ java RotateMatrix
Before rotation:
[ [ 1, 2, 3 ]
  [ 4, 5, 6 ]
  [ 7, 8, 9 ]
 ]
After rotation:
[ [ 7, 4, 1 ]
  [ 8, 5, 2 ]
  [ 9, 6, 3 ]
 ]
```
