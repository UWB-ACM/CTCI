# Maze Problems and Dynamic Programming

Problems and solutions for Maze & Dynamic Programming session on March 1, 2019.

## Problems

### 1. Minimum Platforms

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

**Scenario:**

Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents), and pennies (1 cent), write code to calculate the number of ways of representing `n` cents.

**Function Signature:**

```
int coins(int cents) {}
```


