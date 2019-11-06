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

### 3. Boggle

Source: Lizzy

#### Scenario

In the [game of Boggle](https://en.m.wikipedia.org/wiki/Boggle), 16 
dice with English letters are arranged in a 4x4 grid, and players 
identify as many real words as they can in 3 minutes.

A "real word" is constructed by stringing adjacent characters together 
to form a common English word. Unique die faces which have been 
used to construct a word may not be reused in that same word. 
Adjacent characters include letters which are diagonally adjacent as 
well as letters which are orthogonally adjacent.

Given a 2D array which represents a legal Boggle board and a string, 
determine whether the string could be legally produced from the 
board.

_Bonus: what if you wanted to find all valid words in a given board? 
What kind of structures would you need? How would your implementation 
change?_

#### Example Input

Input:

```
board:  v e i e
        l v t w
        r e n x
        w m p i

string: interview
```

Output: `true`

Explanation: The word "interview" is formed by tracing the word 
from the bottom right-hand cell.

Input:

```
board:  v e i e
        l v t w
        r e n x
        w m p i

string: tent
```

Output: `false`

Explanation: We can form 't', 'te', and 'ten', but we cannot legally 
form 'tent' in this board.

#### Function Signature

**D**esign **I**t **Y**ourself

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

### 3. Boggle

Source: Lizzy

#### Solution 

We can envision this board as an undirected unweighted graph. 
Each die is a node, and all neighboring dice have edges connecting 
them. When we find a word in the board, the word is represented by 
a specific traversal route across the graph.

We can choose to traverse the graph depth- or breadth-first; our 
solution traverses depth-first using a recursive function.

Because we don't want to repeat our usage of dice when we are forming 
a word, we must track which nodes we have "visited", or included in 
our word formation, up until this point. The provided solution uses 
a set, but can be another structure of your choosing.

To begin the solution we call a method that is called `solve` in 
this example. `solve` calls our recursive depth-first search 
function for each cell in the grid.

```python
def solve(grid, word):
    if not grid or not word:
        return False
    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if dfs(grid, word, 0, row, col, set()):
                return True
    return False
```

Our recursive function does the following:

1. Check for base cases which might cause the current search path to 
   terminate as either true or false (see code for details).
2. Otherwise, we can proceed by searching surrounding cells. We mark 
   the current cell as visited and call our recursive function on 
   the surrounding cells, returning the inclusive OR of the result.

```python
def dfs(grid, word, word_idx, row, col, visited):
    # handle edge cases:
    # 1. check to ensure our indices are still in bounds
    # 2. check to ensure we have not processed entire word
    # 3. check to make sure we haven't visited this node
    if row < 0 or row >= len(grid): return False
    if col < 0 or col >= len(grid[0]): return False
    if word_idx >= len(word): return True
    if (row, col) in visited: return False
    # we are still traversing graph; now, check for letter alignment
    if grid[row][col] != word[word_idx]:
        # letters are mismatched; terminate this search
        return False
    # keep searching; search in all 8 directions from current node
    visited.add((row, col))
    return dfs(grid, word, word_idx + 1, row + 1, col, visited) or  \
            dfs(grid, word, word_idx + 1, row + 1, col + 1, visited) or \
            dfs(grid, word, word_idx + 1, row + 1, col - 1, visited) or \
            dfs(grid, word, word_idx + 1, row, col + 1, visited) or \
            dfs(grid, word, word_idx + 1, row, col - 1, visited) or \
            dfs(grid, word, word_idx + 1, row - 1, col + 1, visited) or \
            dfs(grid, word, word_idx + 1, row - 1, col - 1, visited) or \
            dfs(grid, word, word_idx + 1, row - 1, col, visited)
```

#### Bonus Question Solution

_Bonus: what if you wanted to find all valid words in a given board? 
What kind of structures would you need? How would your implementation 
change?_

Since our problem here has become more generic, we would do away with 
matching individual characters based on an input string. However, we 
require a set of words to compare our traversal path against. To 
validate a specific path in the board, we can use one of two structures: 

1. A "dictionary" of words, usually given as a `set`.
2. A prefix tree, or [trie](https://en.wikipedia.org/wiki/Trie).

For efficiency and elegant alignment with node traversal, a trie is 
preferred. The reasons for this make for a good brain exercise; 
feel free to ask why. 

Now, when we are performing depth-first search of our board, we want 
to have a way to reconstruct the word we are currently building. A 
simple implementation would be to have the existing word passed in as 
an argument to `dfs` so we can just append the current letter.

Each time we append a letter, we can check it against our valid word 
list to see if we found a valid word. If that's the case, we want to 
store the word somewhere. Because `dfs` is recursive, we have to be 
careful about how we handle this requirement; a wrapper class around 
a list/array is the most straightforward approach. Possible duplicate 
words should be addressed in the solution.

#### Driver For Solution

For the basic problem, the [solution](./boggle/solution.py) and 
[driver](./boggle/driver.py) are available. The solution's output is:

```console
$ python driver.py

Board:
v e i e 
l v t w 
r e n x
w m p i 

For word 'interview', the result is True
For word 'tent', the result is False

Board:


For word 'a', the result is False
```

A coded solution for the bonus problem has not been provided and 
has been left as an exercise for the reader.

<!-- Don't remove -->
Go to [Top](#top)
