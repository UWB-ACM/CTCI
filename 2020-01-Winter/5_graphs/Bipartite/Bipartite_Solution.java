/*
 * ACM CTCI
 * Graph Practices, https://leetcode.com/problems/is-graph-bipartite/
 * @author Bill Zhao
 * @date 02/14/2020
 */

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