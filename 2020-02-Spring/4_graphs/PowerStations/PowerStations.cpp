
#include <iostream>
#include <vector>

using namespace std;
struct Graph {
    explicit Graph() = default;
    int N,M,K;
    vector<vector<bool> > Matrix;
    vector<int> PowPlants;
    vector<int> Maint;
};

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
        for (int i=0;i<G.N; i++) {
            if (ActiveStas[i]) continue;
            cout << i << " ";
        }
        cout << endl;
    }
};

// tests
Graph Graph00();
Graph Graph01();
Graph Graph02();
Graph Graph03();

int main() {
    // select the test you want to run
    Graph G;
    //G = Graph00();
    G = Graph01();
    //G = Graph02();
    //G = Graph03();
    
    // replace this solution with your solution
    Solution().Solve(G);
    return 0;
}
Graph Graph00() {
  /*
       ________
      /        \
     /          \
    v            \
    3<---0------->1
         |\      /
           \    /
            \  v
              2
     */
    Graph G;
    G.N =4; G.M=3; G.K=1;
    G.PowPlants = {0,1,2};
    G.Maint = {0};
    G.Matrix = { // output : 0 1 3
        vector<bool>{0,1,0,1},
        vector<bool>{0,0,1,1},
        vector<bool>{1,0,0,0},
        vector<bool>{0,0,0,0}
    };
    return G;
}
Graph Graph01(){
    /*
     0--->1------>2
     |    \      /|
     |     \    /
    \|      \| /
     3------->4
              |\
              |
              5
     */
    Graph G;
    G.N =6; G.M=2; G.K=1;
    G.PowPlants = {0,5};
    G.Maint = {0};
    G.Matrix = { // output : 0 1 3
        vector<bool>{0,1,0,1,0,0},
        vector<bool>{0,0,1,0,1,0},
        vector<bool>{0,0,0,0,0,0},
        vector<bool>{0,0,0,0,1,0},
        vector<bool>{0,0,1,0,0,0},
        vector<bool>{0,0,0,0,1,0},
    };
    return G;
}
Graph Graph02() {
    /*
       __________
      /          \
     v            \
    0------>1----->2
     \     /      /
      \   /      /
       v v      /
        3 <----/
     */
    Graph G;
    G.N = 4; G.M = 2; G.K=1;
    G.Maint = {0};
    G.PowPlants = {0,2};
    G.Matrix = { // 0 1 3
        vector<bool>{0,1,0,1},
        vector<bool>{0,0,1,1},
        vector<bool>{1,0,0,1},
        vector<bool>{0,0,0,0},
    };
    return G;
}
Graph Graph03() {
    //bilateral connection
    /*
          ___     __
         /   \   /  \
        v     \ v    \
    ---0------->1----->2
    |  |\             / |\
    |    \___________/    \
    |______________________|
      */
    Graph G;
    G.N = 3; G.M = 3; G.K = 1;
    G.Maint = {2};
    G.PowPlants = {0,1,2};
    G.Matrix = {
        vector<bool>{0,1,1},
        vector<bool>{1,0,1},
        vector<bool>{1,1,0},
    };
    return G;
}

