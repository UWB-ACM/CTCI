<!-- Don't remove -->
<a name="top"/>

# Topic Name TODO :bug:

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

### 1. Best Time to Buy and Sell Stock

Source: [LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

#### Scenario

Say you have an array of n elements representing stock prices.

Price of the stock on the first day is the first element, second day is the second element and so on. 

If you were only permitted to complete at most two transactions (i.e., buy one and sell one share of the stock) on any given days, design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Note that you can only sell forwards, not backwards. 

#### Example Input

**Input:** \[7,1,5,3,6,4]

**Output:** 5

**Explanation:** 
Buy on day 2 (price = 1) and sell on day 5 (price = 6), would produce the max profit = 6-1 = 5.
Not 7-1 = 6, as the selling date needs to follow the purchase date.

#### Function Signature

**Java:**

```java
class Solution {
    public int maxProfit(int[] prices) {
        
    }
}

```

**C++:**

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
    }
};

```

<!-- Don't remove -->
Go to [Solution](#s1)   [Top](#top)

<!-- Don't remove -->
<a name="p2"/>

### 2. PROBLEM 2 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

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

### 1. Best Time to Buy and Sell Stock

Source: [LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solution/)

#### Naive/Simple Solution

We need to find out the maximum difference (which will be the maximum profit) between two numbers in the given array. Also, the second number (selling price) must be after the first one (buying price) because you sell in the future, not in the past.

In other terms, we need to find max(prices[j]−prices[i]), for every i and j such that j > i.

```
Approach 1: Brute Force

public int maxProfit(int prices[]) {
        int maxprofit = 0;
        for (int i = 0; i < prices.length - 1; i++) {
            for (int j = i + 1; j < prices.length; j++) {
                int profit = prices[j] - prices[i];
                if (profit > maxprofit)
                    maxprofit = profit;
            }
        }
        return maxprofit;
    }
    
Complexity Analysis

   Time complexity: O(n^2)
  
   Space complexity : O(1). Only two variables - maxprofit and profit are used.

```

#### Optimal Solution

See [solution](/buy_stock/solution.java)

#### Testing The Solutions OR Driver For Solution

See [driver](/buy_stock/driver.java)

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s2"/>

### 2. SOLUTION 2 TODO :bug:

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
