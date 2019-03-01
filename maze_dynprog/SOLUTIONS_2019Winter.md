# Maze Problems and Dynamic Programming

Problems and solutions for Maze & Dynamic Programming session on March 1, 2019.

## Problems

### 1. Minimum Platforms

Source: [GeeksForGeeks](https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/)

**Scenario:** 

Given arrival and departure times of all trains that reach a railway station, find the minimum number of platforms required for the railway station so that no train waits. We are given two arrays which represent arrival and departure times of trains that stop.

**Example Input:**

```
Input:  arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
        dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
```

For the above input, the correct result is `3`, which applies to the time slot from 11:00 to 11:20.

**Function Signature:**

```
int minimum_platforms(Time[] arrivals, Time[] departures) {}
```

The Time object has an overloaded subtraction operator and an overloaded sort method.

### 2. Coins

Source: CTCI 8.11

**Scenario:**

Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents), and pennies (1 cent), write code to calculate the number of ways of representing `n` cents.

**Function Signature:**

```
int coins(int cents) {}
```

## Solutions

### 1. Minimum Platforms



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
