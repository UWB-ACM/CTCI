/*
 * ACM CTCI
 * Graph Practices, https://leetcode.com/problems/is-graph-bipartite/
 * @author Bill Zhao
 * @date 02/14/2020
 */

import java.io.*;
import java.lang.*;
import java.util.*;

class Bipartite {
   // Solution to Problem 3
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
   
   // Driver for Problem 3
   public static void main(String[] args) {
     // 0----1
     // |    |
     // |    |
     // 3----2
     int TestCase[][] = new int[][]
                        {{1,3}, {0,2},
                          {1,3}, {0,2}};
     // 0----1
     // | \  |
     // |  \ |
     // 3----2
     int TestCase2[][] = new int[][]
                        {{1,2,3}, {0,2},
                         {0,1,3}, {0,2}};
              
     Bipartite Test = new Bipartite();
     
     if (Test.isBipartite(TestCase) && !Test.isBipartite(TestCase2))
         System.out.println("All Tests Passed");
     else
         System.out.println("Some/All Tests Failed");
   }
}