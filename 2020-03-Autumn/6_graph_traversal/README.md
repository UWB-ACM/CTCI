<!-- Don't remove -->
<a name="top"/>

# Graph Traversal

***Problems and solutions for Graph Traversal session on November 20, 2020.***

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

### 1. Number of Islands

Source: [LeetCode](https://leetcode.com/problems/number-of-islands/)

#### Scenario

Given an `m x n` 2d grid map of `'1's` (land) and `'0's` (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

#### Example 1

**Input:** ```grid = [
		["1","1","1","1","0"],
		["1","1","0","1","0"],
		["1","1","0","0","0"],
		["0","0","0","0","0"]
]```

**Output:** 1

**Explanation:** 
There is only one big island in the grid.

#### Example 2

**Input:** ```grid = [
		["1","1","0","0","0"],
		["1","1","0","0","0"],
		["0","0","1","0","0"],
		["0","0","0","1","1"]
]```

**Output:** 3

**Explanation:** 
In the grid, we only count `1`s to be part of the same island if the are connected vertically or horizontally.
If two `1`s are adjacent diagonally, they are considered different islands.

#### Function Signature

**C++:** `int numIslands(vector<vector<char>>& grid)`

**Java:** `int numIslands(char[][] grid)`

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

### 1. Number of Islands

Source: [LeetCode](https://leetcode.com/problems/number-of-islands/)

#### DFS Solution

We can treat the 2d grid as an undirected graph, where there is an edge between adjacent nodes of value `1`.

Traversing the 2d grid, we can check which node contains a `1`. When we find a node containing `1`, we know we need to explore the adjacent nodes to see if they 
are part of the recently. Here is where we will use the DFS. During DFS, we want to mark the visited nodes with value of `1`. Any number other than `0` and `1` would work. In this implementation, we are going to use the number
`3` to mark the nodes with value of `1` that have been visited. 
Count the number of root nodes that trigger DFS, this number would be the number of islands since each DFS starting at some root identifies an island.

Here is one way to implement the solution:

```
	//DFS graph traversal
    void markIslandVisited (vector<vector<char>>& grid, int rowInd, int colInd, int maxRows, int maxCols) {
        
        if(rowInd < 0 || colInd < 0 || colInd >= maxCols || rowInd          >= maxRows || grid[rowInd][colInd] != '1'){
            return;
        }
        //mark it as visited
        grid[rowInd][colInd] = '3';
        
        //Visit the adjacent rows and cols
        //Going North
        markIslandVisited(grid, rowInd - 1, colInd, maxRows, maxCols);
        //Going West
        markIslandVisited(grid, rowInd, colInd - 1, maxRows, maxCols);
        //Going South
        markIslandVisited(grid, rowInd + 1, colInd, maxRows, maxCols);
        //Going East
        markIslandVisited(grid, rowInd, colInd + 1, maxRows, maxCols);
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        if (rows == 0) {
            return 0;
        }
        int cols = grid[0].size();
        
        if (cols == 0) {
            return 0;
        }
        
        int islands = 0;
        
        for (int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++){
                //We have find an unvisited block of land
                if (grid[i][j] == '1') {
                    //count the island
                    islands++;
                    //let's mark it as visited, and visit adjacent nodes
                    markIslandVisited(grid, i, j, rows, cols);
                    
                }
            }
        }
        return islands;
    }
```
#### Testing The Solutions OR Driver For Solution

[Click here for the C++ driver](./QuestionOne/driver.cpp)

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
