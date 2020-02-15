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

````
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

### 3. Is Graph Bipartite

Source: [Leetcode](https://leetcode.com/problems/is-graph-bipartite/)

#### Solution

````
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
