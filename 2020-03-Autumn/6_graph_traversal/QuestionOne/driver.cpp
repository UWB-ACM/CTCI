#include <iostream>
#include <vector>
using namespace std;

void markIslandVisited (vector<vector<char>>& grid, int rowInd, int colInd, int maxRows, int maxCols) {

    if(rowInd < 0 || colInd < 0 || colInd >= maxCols || rowInd >= maxRows || grid[rowInd][colInd] != '1'){
        return;
    }
    //mark it as visited
    grid[rowInd][colInd] = '3';

    //Visit the adjacent rows and cols
    //Going north
    markIslandVisited(grid, rowInd - 1, colInd, maxRows, maxCols);
    //Going west
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
                //let's mark it
                markIslandVisited(grid, i, j, rows, cols);

            }
        }
    }
    return islands;
}

int main() {
   // std::cout << "Hello, World!" << std::endl;


    vector<vector<char>> firstGrid{
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
    };

    vector<vector<char>> secondGrid{
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
    };


    int res = numIslands(firstGrid);
    int res2 = numIslands(secondGrid);

    cout << "Total of islands: " << res <<endl;
    cout << "Total of islands in second grid " << res2 <<endl;

    return 0;
}
