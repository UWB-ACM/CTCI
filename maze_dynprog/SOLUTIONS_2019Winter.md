# Maze Problems and Dynamic Programming

Problems and solutions for Maze & Dynamic Programming session on March 1, 2019.

## Problems

### 1. Minimum Platforms

Source: [GeeksForGeeks](https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/)

**Scenario:** 

Given arrival and departure times of all trains that reach a railway station, find the minimum number of platforms required for the railway station so that no train waits.

We are given two arrays which represent arrival and departure times of trains that stop, and n representing the total amount of trains that travel through.

**Example Input:**

```
    arr[]  = {900,  940, 950,  1100, 1500, 1800}
    dep[]  = {910, 1200, 1120, 1130, 1900, 2000}
    n = 6
```

For the above input, the correct result is `3`, which applies to the time slot from 11:00 to 11:20.

**Function Signature:**

```
int minimum_platforms(int[] arrivals, int[] departures, int n);
```

### 2. Coins

Source: CTCI 8.11

**Scenario:**

Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents), and pennies (1 cent), write code to calculate the number of ways of representing `n` cents.

**Function Signature:**

```
int coins(int cents) {}
```

### 3. Unique Paths II

**Scenario:** 

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?

**Example Input:**

```
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
```

Output: 2

Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

**Function Signature:**

C++
```cpp
int uniquePaths(vector<vector<int>>& grid);
```
Java
```java
int uniquePaths(int[][] grid);
```
## Solutions

### 1. Minimum Platforms

**Simple Solution:** 
```
A Simple Solution is to take every interval one by one and find the number of intervals that overlap with it. Keep track of maximum number of intervals that overlap with an interval. Finally return the maximum value. Time Complexity of this solution is O(n^2).
```

**Optimal solution:**
```cpp
#include <bits/stdc++.h> 
using namespace std; 
  
int findPlatform(int arr[], int dep[], int n) 
{ 
    // Insert all the times (arr. and dep.) 
    // in the multimap. 
    multimap<int, char> order; 
    for (int i = 0; i < n; i++) { 
  
        // If its arrival then second value 
        // of pair is 'a' else 'd' 
        order.insert(make_pair(arr[i], 'a')); 
        order.insert(make_pair(dep[i], 'd')); 
    } 
  
    int result = 0; 
    int plat_needed = 0; 
  
    multimap<int, char>::iterator it = order.begin(); 
  
    // Start iterating the multimap. 
    for (; it != order.end(); it++) { 
  
        // If its 'a' then add 1 to plat_needed 
        // else minus 1 from plat_needed. 
        if ((*it).second == 'a') 
            plat_needed++; 
        else
            plat_needed--; 
  
        if (plat_needed>result) 
            result = plat_needed; 
    } 
    return result; 
} 
```
**Driver For Solution**  
```cpp
int main() 
{ 
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 }; 
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Minimum Number of Platforms Required = "
         << findPlatform(arr, dep, n); 
    return 0; 
} 
```

### 2. Coins

Source: CTCI 8.11

**Naive Solution:**

```python
# Naive Implementation for CTCI Problem 8.11: "Coins"
def coins_naive(amount, denominations, denom_index):
    # base case: we have processed all possible larger coin denominations 
    # for this subproblem, and are only inspecting pennies now
    if denom_index >= len(denominations) - 1:
        return 1
    # create a local variable to track the number of permutations of 
    # smaller coin denominations available for this subproblem
    permutations = 0
    # now, we incrementally create subproblems for the current 
    # denomination we are looking at
    for i in range(0, (amount // denominations[denom_index]) + 1):
        # compute permutations for all subproblems and take the sum
        permutations += coins_naive(amount - (denominations[denom_index] * i), denominations, denom_index + 1)
    # return the permuatation count for this subproblem
    return permutations
```

**Dynamic Programming Solution:**

```python
def coins_dynamic(amount, denoms, denom_index, previously_computed_values):
    if denom_index >= len(denoms) - 1:
        return 1
    # Additional Base Case
    # If the recursive subproblem has already been solved,
    # use the existing value! 
    # NOTE: This is the core component of the dynamic implementation.
    if previously_computed_values[amount][denom_index] > 0:
        return previously_computed_values[amount][denom_index]
    permutations = 0
    for i in range(0, (amount // denoms[denom_index]) + 1):
        permutations += coins_dynamic(amount - (denoms[denom_index] * i), denoms, denom_index + 1, previously_computed_values)
    previously_computed_values[amount][denom_index] = permutations
    return permutations
```

**Testing The Solutions:**

In the repository subdirectory, under `/maze_dynprog/coins`, run `python test_coins.py`. ***NOTE: this test suite requires `numpy`, which can be installed via pip.***

Test output:

```
Testing naive solution:
Input: 5	Expected: 2	    Actual: 2	    Correct? True
Input: 10	Expected: 4	    Actual: 4	    Correct? True
Input: 25	Expected: 13	Actual: 13	    Correct? True
Input: 500	Expected: 19006	Actual: 19006	Correct? True
Testing dynamic solution:
Input: 5	Expected: 2	    Actual: 2	    Correct? True
Input: 10	Expected: 4	    Actual: 4	    Correct? True
Input: 25	Expected: 13	Actual: 13	    Correct? True
Input: 500	Expected: 19006	Actual: 19006.0	Correct? True
Testing timeit for naive solution (N = 500, repetitions = 1000)
6.029917129999376
Testing timeit for dynamic solution solution (N = 500, repetitions = 1000)
2.2468340240011457
```
## 3. Unique Paths II

```java
public int uniquePaths(int[][] obstacleGrid) {

  int R = obstacleGrid.length;
  int C = obstacleGrid[0].length;

  // If the starting cell has an obstacle, 
  // then simply return as there would be
  // no paths to the destination.
  if (obstacleGrid[0][0] == 1) return 0;

  // Number of ways of reaching the starting cell = 1.
  obstacleGrid[0][0] = 1;

  // Filling the values for the first column
  for (int i = 1; i < R; i++)
    obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 
                       && obstacleGrid[i - 1][0] == 1) ? 1 : 0;

  // Filling the values for the first row
  for (int i = 1; i < C; i++)
            obstacleGrid[0][i] = (obstacleGrid[0][i] == 0 
                               && obstacleGrid[0][i - 1] == 1) 
                                ? 1 : 0;

  // Starting from cell(1,1) fill up the values
  // No. of ways of reaching 
  // cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
  // i.e. From above and left.
  for (int i = 1; i < R; i++)
    for (int j = 1; j < C; j++) {
      if (obstacleGrid[i][j] == 0)
        obstacleGrid[i][j] = obstacleGrid[i - 1][j] 
                           + obstacleGrid[i][j - 1];
      else
        obstacleGrid[i][j] = 0;
      }

  // Return value stored in rightmost bottommost cell. 
  // That is the destination.
  return obstacleGrid[R - 1][C - 1];
}
```
