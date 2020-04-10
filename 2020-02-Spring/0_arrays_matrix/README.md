<!-- Don't remove -->
<a name="top"/>

# Array & Matrix

Practice solving array and matrix related problems. Session on April 09, 2020.

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

### 2. Maximum Subarray

Source: https://leetcode.com/problems/maximum-subarray/

#### Scenario

Given an array of integers, find the contiguous subarray (containing at least one number) which has the largest sum and return the sum.

#### Example Input

```
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

#### Function Signature

```java
public int maxSubArray(int[] nums)
```

<!-- Don't remove -->
Go to [Solution](#s2)   [Top](#top)

<!-- Don't remove -->
<a name="p3"/>

### 3. Word Search

Source: [LeetCode](https://leetcode.com/problems/word-search/)

#### Scenario

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

#### Example Input

```
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
```

Given word = "ABCCED", return true.

Given word = "SEE", return true.

Given word = "ABCB", return false.

#### Function Signature

Python: 

```python
def exist(board, word):
    # your code here
```

Java: 
  
```java
public boolean exist(char[][] board, String word) {
    // your code here 
}

```

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

**Brute Force:**
```

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

See [solution](./buy_stock/solution.java)

#### Testing The Solutions OR Driver For Solution

See [driver](./buy_stock/driver.java)

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s2"/>

### 2. Maximum Subarray SOLUTION

Source: https://leetcode.com/problems/maximum-subarray/

We will traverse over the array and keep track of 2 variables: Total maximum sum, and the current sum.<br/>

We will look at each number and add it to the current sum, if the current sum becomes negative, we ignore the numbers that made it negative.<br/>

Resetting the current to 0 is basically saying "Ignore everything we looked at previously because it's not getting us the greatest sum."<br/>
So if we are looking at this array: `[-2,1,-3,4,-1,2,1,-5,4]`<br/>
We will look at -2 and see we have a negative number, so set curr to 0. <br/>
Then we see that 1 is postive, set curr & max to 1. <br/>
Then -3 gives us a curr of -2, set curr to 0, but the max is still 1.<br/>
Then 4 gives us a curr of 4, and update max to 4. Since our curr is now 4, we have ignored all the values before 4 (-2, 1, -3).<br/>
We continue to add numbers -1, 2, 1 and get a sum of (4+-1+2+1 = 6).<br/>
Once we get to -5 it reduces our sum to 1, so we ignore it.<br/>
Our max is 6.

#### Solution

```java
public int maxSubArray(int[] nums) {
    if (nums.length == 1) {
        return nums[0];
    }
    //Keep track of the max sum seen so far, and the current running sum.
    int max = nums[0];
    int curr = 0;
    for (int i = 0; i < nums.length; i++) {
        curr += nums[i];
        //If the current running sum is greater than the total, set it to max.
        if (curr > max) {
            max = curr;
        }
        //If the current running total becomes negative, we ignore all previous numbers
        if (curr < 0) {
            curr = 0;
        }
    }
    return max;
}
```

### Testing
```
    All negative numbers ([ -3 -16 -4 -1 -2 -6])
    Not front-loaded arrays, where the max is at the end of the array ([ -1 1 3 4 5 ])
    A normal-ish array ([ 3 2 6 0 1 -3 1 ])
```

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s3"/>

### 3. Word Search Solution 


This is a typical 2D grid traversal problem that searches the grid for a solution using DFS (Depth-First Search). 
In other words, we want to go as far as possible before we try another direction.

You may recognize this as recursive backtracking. 

#### Algorithm Overview 

For every cell in the grid, we call a `backtrack` function to check if we can obtain a solution starting from that cell.
This is often implemented recursively. 

For each call of the function, we follow the following steps:

1. Check to see if we've reached the base case (i.e, have we found the word we want?)
2. Check to see if we've reached an invalid state (i.e, out of bounds, not part of the word)
3. Continue exploring recursively:

  i) Mark the current cell as visited
  
  ii) Try all four possible directions. 
  
4. At the end of exploration, revert back to our original state. 

The last step is very important. We need to do that so we can have a clean board for trying different directions in other recursive calls.


#### Complexity Analysis

***Time Complexity***: `O(N * 4^L)` where `N` is the number of cells in the board and `L` is the length of the word to be matched.

* `4^L` - There are four possible choices we can take for each recursive call. In the worst case, we may have to try all 4 directions for every character in the word. This forms an 4-nary tree in the worst case. 

* `N` - There are N possible times the `backtrack` function could be called.

***Space Complexity***: `O(L)` where `L` is the length of the word to be matched. This space is occupied by the recursive calls of the `backtrack` function, which occupy space in the call stack. Up to `L` stack frames will be used at any given time during the algorithm.




##### Java
<details>
<summary>Click to see solution</summary>

```java
  public static boolean exist(char[][] board, String word) {
        // For every single cell in the board, we want to try searching for the word.
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (backtrack(board, 0, i, j, word)) {
                    return true;
                }
            }
        }
        return false;
    }

    private static boolean backtrack(char[][] board, int index, int row, int col, String word) {
        // Check the base case (Have we found the word that we're looking for?)
        if (index == word.length()) {
            return true;
        }

        // Check if the boundaries of the board have been exceeded
        if (row < 0 || row >= board.length || col < 0 || col >= board[0].length) {
            return false;
        // Check if we have encountered a character that should not be at this position in the word
        } else if (word.charAt(index) != board[row][col])) {
            return false;
        } else {
            // Mark this cell as visited
            board[row][col] = '*';
            // Recursively explore neighboring cells for the rest of the word
            boolean result = backtrack(board, index + 1, row + 1, col, word) ||
                             backtrack(board, index + 1, row, col + 1, word) ||
                             backtrack(board, index + 1, row - 1, col, word) ||
                             backtrack(board, index + 1, row, col - 1, word);
            // Revert this cell back to its original state after backtracking
            // We do this so other explorations of the board starting can use this cell again
            board[row][col] = word.charAt(index);
            return result;
        }
    }

```
</details>


##### Python

<details>
<summary>Click to see solution</summary>

```python
def exist(board, word):
    """
    :type board: List[List[str]]
    :type word:  str
    :rtype: bool
    """
    rows = len(board)
    cols = len(board[0])
    for row in range(rows):
        for col in range(cols):
            if backtrack(row, col, word, board):
                return True
    return False

def backtrack(row, col, word, board):
    # Check if the word has been found
    if (len(word) == 0):
        return True
    # Check if the boundaries of the board have been reached
    if row < 0 or row == len(board) or col < 0 or col == len(board[0]):
        return False
    # Check if we have found a character that shouldn't be at this position in the word
    if board[row][col] != word[0]:
        return False
    
    result = False
    # Mark current cell as visited
    board[row][col] = '*'
    # Check neighboring cells for the rest of the word
    for row_delta, col_delta in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
        result = backtrack(row + row_delta, col + col_delta, word[1:], board)
        if result: break
    # Reset changes to this cell so other explorations of the board can use it
    board[row][col] = word[0]
    return result
```

</details>

#### Tests for Solutions

##### Java
```java
public static void main(String[] args) {
    char[][] testBoard = {{ 'A','B','C','E' }, { 'S','F','C','S' }, { 'A','D','E','E' }};
    System.out.println(exist(testBoard, "ABCCED")); // Should print true
    System.out.println(exist(testBoard,"SEE"));     // Should print true
    System.out.println(exist(testBoard, "ABCB"));   // Should print false
}
```

##### Python
```python

def main():
    test_board = [['A','B','C','E'],
                  ['S','F','C','S'],
                  ['A','D','E','E' ]]
    print(exist(test_board, "ABCCED")) # Should print true
    print(exist(test_board, "SEE"))    # Should print true
    print(exist(test_board, "ABCB"))   # Should print false

if __name__ == "__main__":
    main()
```

<!-- Don't remove -->
Go to [Top](#top)
