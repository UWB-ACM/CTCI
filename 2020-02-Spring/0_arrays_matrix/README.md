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

### 1. PROBLEM 1 TODO :bug:

Source: TODO :bug:

#### Scenario

Problem Statement TODO :bug:

#### Example Input

If the problem is simple enough, remove this section. TODO :bug:

#### Function Signature

TODO :bug:

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

### 3. Word Search

Source: [LeetCode](https://leetcode.com/problems/word-search/)

#### Scenario

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

#### Example Input

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

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

### 1. SOLUTION 1 TODO :bug:

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

### 3. Word Search Solution 

#### Solution


Time Complexity: O(N * 4^{L}) where N is the number of cells in the board and L is the length of the word to be matched.


##### Java
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

##### Python
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

#### Testing The Solutions OR Driver For Solution

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
