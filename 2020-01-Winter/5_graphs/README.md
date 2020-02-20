<!-- Don't remove -->
<a name="top"/>

# Graphs

Problems and solutions for Graphs session on February 21, 2020.

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

### 2. PROBLEM 2 
Find the Town Judge
Source: [Leetcode](https://leetcode.com/problems/find-the-town-judge/)

#### Scenario

In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.

#### Example Input

Example 1:
```c++
Input: N = 2, trust = [[1,2]]
Output: 2
```
Example 2:
```c++
Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
```
Example 3:
```c++
Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
```
Example 4:
```c++
Input: N = 3, trust = [[1,2],[2,3]]
Output: -1
```
Example 5:
```c++
Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
```
#### Function Signature

```
int findJudge(int N, vector<vector<int>>& Trust) {}
```


<!-- Don't remove -->
Go to [Solution](#s2)   [Top](#top)

<!-- Don't remove -->
<a name="p3"/>

### 3. Is Graph Bipartite

Source: [Leetcode](https://leetcode.com/problems/is-graph-bipartite/)

#### Scenario

Given an undirected `graph`, return `true` if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into
two independent subsets A and B such that every edge in the graph has 
one node in A and another node in B.

The graph is given in the following form: `graph[i]` is a list of indexes `j`
for which the edge between nodes i and j exists.  Each node is an integer
between `0` and `graph.length - 1`.  There are no self edges or parallel edges:
`graph[i]` does not contain `i`, and it doesn't contain any element twice.

#### Example Input

````
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
0----1
|    |
|    |
3----2
````
````
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
0----1
| \  |
|  \ |
3----2
````
#### Function Signature

````java
// Java
public boolean isBipartite(int[][] graph)
````

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

### 2. Town Judge

Source: [Leetcode](https://leetcode.com/problems/find-the-town-judge/)

Using two vectors to count the number of incoming and outgoing trusted edges [TrustCounter]. For outgoing edges from A to B, we immediately invalidate A being the town judge according to the problem statement. (Judge CANNOT trust anyone)

For incoming edges A to B, we increment the counter Count[B]. When we know there are N-1 incoming connections, we make a note on the B. However, if there is a second candidate that has received N-1 connections, we know there are no answers which we can simply return -1.

One edge case is when there is only 1 person and the trust vector is empty, the person himself/herself is the judge.

```c++
class Solution {
public:
  int findJudge(int N, std::vector<std::vector<int>> &Trust) {

    std::vector<int> TrustCounter(N, 0);
    std::vector<bool> ValidJudge(N, true);

    int Count = 0;
    int X = -1;

    for (const auto &Person : Trust) {
      TrustCounter[Person[1] - 1] ++;
      if (TrustCounter[Person[1] - 1] == N - 1) {
        Count++;
        X = Person[1];
        // no judge
        if (Count >= 2) {
          return -1;
        }
      }
      // judge trusts nobody
      ValidJudge[Person[0] - 1] = false;
    }
    if (Count == 0) {
      return N == 1 ? 1 : -1;
    }
    if (ValidJudge[X - 1]) {
      return X;
    }
    return -1;
  }
};
```

#### Testing The Solutions OR Driver For Solution

[Link to .cpp file](./TownJudge/TownJudge.cpp)

<!-- Don't remove -->
Go to [Top](#top)

<!-- Don't remove -->
<a name="s3"/>

### 3. Is Graph Bipartite

Source: [Leetcode](https://leetcode.com/problems/is-graph-bipartite/)

#### Solution

The idea of this solution is to assign the nodes with two different colors,
in this case, a graph is only bipartite if any of the two adjacent nodes does
not have the same color.

Using Breadth First Search to traverse all nodes, color the first node as 1, 
then color all its neighbors as 0, continue until all nodes are traversed.

As we said before, if two adjacent nodes have the same color, it is not
bipartite. If all nodes follows the rule, it is bipartite, therefore,
return true.

Time Complexity: O(n), n is the sum of #nodes and #edges
 
````java
// Solution in Java
public boolean isBipartite(int[][] Graph) {
  int NumOfNodes = Graph.length;
  int[] Group = new int[NumOfNodes];

  for (int I = 0; I < NumOfNodes; ++I) {
    if (Group[I] != 0) continue;
    Queue<Integer> Groups = new LinkedList<>();
    Groups.add(I);
    Group[I] = 1;

    while (!Groups.isEmpty()) {
      int Tmp = Groups.remove();
      for (int Neighbor : Graph[Tmp]) {
        if (Group[Neighbor] == Group[Tmp])
          return false;
        if (Group[Neighbor] == 0) {
          Group[Neighbor] = -Group[Tmp];
          Groups.add(Neighbor);
        }
      }
    }
  }
  return true;
}
````

#### Testing The Solutions OR Driver For Solution

The solution for this problem is
[available in this repository](./Bipartite/Bipartite_Solution.java).
<br> Additional solutions could be found on
[LeetCode](https://leetcode.com/problems/is-graph-bipartite/).

<!-- Don't remove -->
Go to [Top](#top)
