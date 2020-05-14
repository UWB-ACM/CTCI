
class PowerStations {
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
    public static void main(String[] args) {
        // select the test you want to run
        Graph G;
        
        //G = Graph00();
        G = Graph01();
        //G = Graph02();
        //G = Graph03();
        
        // replace this solution with your solution
        Solve(G);
    
    }
    static Graph Graph00() {
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
        Graph G = new Graph();
        G.N =4; G.M=3; G.K=1;
        G.PowPlants = new int[]{0,1,2};
        G.Maint = new int[]{0};
        G.Matrix = new int[][] { // output : 0 1 3
            {0,1,0,1},
            {0,0,1,1},
            {1,0,0,0},
            {0,0,0,0}
        };
        return G;

    }
    static Graph Graph01(){
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
        Graph G = new Graph();
        G.N =6; G.M=2; G.K=1;
        G.PowPlants = new int[]{0,5};
        G.Maint = new int[]{0};
        G.Matrix = new int[][] { // output : 0 1 3
            {0,1,0,1,0,0},
            {0,0,1,0,1,0},
            {0,0,0,0,0,0},
            {0,0,0,0,1,0},
            {0,0,1,0,0,0},
            {0,0,0,0,1,0}
        };
        return G;
    }
    static Graph Graph02() {
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
        Graph G = new Graph();
        G.N = 4; G.M = 2; G.K=1;
        G.Maint = new int[]{0};
        G.PowPlants = new int[]{0,2};
        G.Matrix = new int[][] { // 0 1 3
            {0,1,0,1},
            {0,0,1,1},
            {1,0,0,1},
            {0,0,0,0}
        };
        return G;
    }
    static Graph Graph03() {
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
        Graph G = new Graph();
        G.N = 3; G.M = 3; G.K = 1;
        G.Maint = new int[]{2};
        G.PowPlants = new int[]{0,1,2};
        G.Matrix = new int[][]{
            {0,1,1},
            {1,0,1},
            {1,1,0}
        };
        return G;
    }
}


