<!-- Don't remove -->
<a name="top"/>

# Graphs

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

### 3. Power Stations

#### Scenario

The electrical system of HappyLand consists of ``N`` stations from ``0`` to ``N-1`` including ``M`` power plants where electricity is produced and the rest ``N-M`` stations are used for transmitting electricity, ``M <= N``. After a hurricane, HappyLand’s authorities need to shut down ``K`` station(s) for maintenance. For safety reasons, a shutdown station has no electricity coming in/out of it. To be considered active, a station, unless it is a power plant which can power itself and stations receiving electricity from it, must receive electricity from at least one active station. Otherwise, it is also shut down indirectly. **Find out all stations that are shutdown by disconnecting K stations.**

Each station is represented by a vertex. Directed arrows indicate the electrical dependency between stations (receive from or transfer to its neighboring stations). Each station is guaranteed to be powered by at least one power plant.

![Electrical system](./PowerStations/Figure12.png)

#### Example Input
```
N =6; M=2; K=1;
PowPlants[M] = {0,5};
Maint[N] = {0};
Matrix[N][N] = {{0,1,0,1,0,0},
              {0,0,1,0,1,0},
              {0,0,0,0,0,0},
              {0,0,0,0,1,0},
              {0,0,1,0,0,0},
              {0,0,0,0,1,0}};
```
#### Example Output
Offline stations:
```
0 1 3
```
<details>
<summary>Click to see explanation</summary>

##### Explanation:
There are 6 stations. 2 power plants are 0 and 5. Station 0 is shut down for maintenance.

Shutting down station 0 shuts down station 1 and 3 as they only receive electricity from power plant 1. Stations 2 is powered by active station 4, which is powered by active power plant 5, also active.
</details>

#### Function Signature
C++:

```c++
// Definition of Graph
struct Graph {
    explicit Graph() = default;
    int N,M,K;
    vector<vector<bool> > Matrix;
    vector<int> PowPlants;
    vector<int> Maint;
};

void Solve(Graph &G) {
    // your code goes here

}
```
Java:

```Java
// Definition of Graph
static class Graph {
    public Graph() { }
    public int N,M,K;
    public int Matrix[][];
    public int PowPlants[];
    public int Maint[];
}
public static void Solve(Graph G) {
    // your code goes here

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

### 3. Power Stations

Instead of validating the status of current vertex by checking vertices(stations) it relies on, we could approach the problem top-down: we assume that all stations are shut down. Starting with known power plant that remains active, we activate adjacent stations and substations of the current active station using DFS.Stations that are not activated by the end of the algorithm are the ones affected by shutting down K stations.

<details>
<summary>Click to see the algorithm illustration</summary>

![Algorithm in steps](./PowerStations/Alg_illustration.png)
</details>

###### Pseudocode
```
void Solve() {
  -> mark all stations as Offline
  -> mark power plants that are in maintenance as Offline
  // start marking from active power plants i-th
  for (i : M) {
    if (PowPlants[i] is active)
      DFS(PowPlants[i]);
  }
}
void DFS(int Cur) {
  if (Cur is in maintenance) return; // stop checking

  // Otherwise mark Cur as active and visited
  Visited[Cur] = true;
  Active[Cur] = true;

  // check its adjacent
  for (i : N) {
    // if i is not visited and has path from Cur->i
    if (!Visited[i] && Matrix[Cur][i])
      DFS(i);
  }
}
```
###### Source code
<details>
<summary>Click to see C++ source code</summary>

```c++

class Solution{
public:
    vector<bool> Maint;
    vector<bool> PowPlants;
    void DFS(Graph &G, int Cur, vector<bool> &ActiveStas, vector<bool> &Visited) {
        if (Maint[Cur]) return;
        Visited[Cur] = true;
        ActiveStas[Cur] = true;
        for (int i=0; i<G.N; i++) {
            if (i!=Cur && !Visited[i] && G.Matrix[Cur][i]) {
                DFS(G, i, ActiveStas, Visited);
            }
        }
    }
    void Solve(Graph &G) {
        // init
        Maint = vector<bool>(G.N);
        PowPlants = vector<bool>(G.N);
        for (int i=0; i<G.K; i++)
            Maint[G.Maint[i]] = true;
        for (int i=0; i<G.M; i++)
            PowPlants[G.PowPlants[i]] = true;

        // assuming all stations are off except active power plants
        vector<bool> ActiveStas(G.N);
        vector<bool> Visited(G.N);
        for (int i=0; i<G.N; i++) {
            ActiveStas[i] = false;
            if (PowPlants[i] && !Maint[i]) ActiveStas[i] = true;
            Visited[i] = false;
        }

        // using DFS to mark stations that connected to
        // known active stations
        for (int i=0; i<G.M; i++) {
            if (ActiveStas[G.PowPlants[i]])
                DFS(G, G.PowPlants[i], ActiveStas, Visited);
        }

        // print out offline stations at the end
        for (int i=0; i<G.N; i++) {
            if (ActiveStas[i]) continue;
            cout << i << " ";
        }
        cout << endl;
    }
};

```
</details>

<details>
<summary>Click to see Java source code</summary>

```Java
static class Graph {
      public Graph() { }
      public int N,M,K;
      public int Matrix[][];
      public int PowPlants[];
      public int Maint[];
}

static boolean Maint[];
static boolean PowPlants[];
private static void DFS(Graph G, int Cur, boolean ActiveStas[], boolean Visited[]) {
    if (Maint[Cur]) return;
    Visited[Cur] = true;
    ActiveStas[Cur] = true;
    for (int i=0; i<G.N; i++) {
        if (i!=Cur && !Visited[i] && G.Matrix[Cur][i] == 1) {
            DFS(G, i, ActiveStas, Visited);
        }
    }
}
public static void Solve(Graph G) {
    // init
    Maint = new boolean[G.N];
    PowPlants = new boolean[G.N];
    for (int i=0; i<G.K; i++)
        Maint[G.Maint[i]] = true;
    for (int i=0; i<G.M; i++)
        PowPlants[G.PowPlants[i]] = true;

    // assuming all stations are off except active power plants
    boolean ActiveStas[] = new boolean[G.N];
    boolean Visited[] = new boolean[G.N];
    for (int i=0; i<G.N; i++) {
        ActiveStas[i] = false;
        if (PowPlants[i] && !Maint[i]) ActiveStas[i] = true;
        Visited[i] = false;
    }

    // using DFS to mark stations that connected to
    // known active stations
    for (int i=0; i<G.M; i++) {
        if (ActiveStas[G.PowPlants[i]])
            DFS(G, G.PowPlants[i], ActiveStas, Visited);
    }

    // print out offline stations at the end
    for (int i=0;i<G.N; i++) {
        if (ActiveStas[i]) continue;
        System.out.print(i +" ");
    }
    System.out.println();
}

```

</details>

###### Time complexity:

- Best and average case: when M is significantly small to N, it is ``O(M*N)``.
- Worst case: when M is close to N or M==N, the algorithm has the same complexity as that of DFS which is ``O(N^2)``.


#### Driver for solution

See C++ [Driver](./PowerStations/PowerStations.cpp)


See Java [Driver](./PowerStations/PowerStations.java)



<!-- Don't remove -->
Go to [Top](#top)
