
public class RobotMaze {
    
    public int uniquePaths(int[][] obstacleGrid) {
    
        int R = obstacleGrid.length;
        int C = obstacleGrid[0].length;
    
        // If the starting cell has an obstacle, 
        // then simply return as there would be
        // no paths to the destination.
        if (obstacleGrid[0][0] == 1) return 0;
    
        // Number of ways of reaching the starting cell = 1.
        obstacleGrid[0][0] = 1;
    
        // Filling the values for the first column
        for (int i = 1; i < R; i++)
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 
            && obstacleGrid[i - 1][0] == 1) ? 1 : 0;
    
        // Filling the values for the first row
        for (int i = 1; i < C; i++)
            obstacleGrid[0][i] = (obstacleGrid[0][i] == 0 
            && obstacleGrid[0][i - 1] == 1) ? 1 : 0;
    
        // Starting from cell(1,1) fill up the values
        // No. of ways of reaching 
        // cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
        // i.e. From above and left.
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (obstacleGrid[i][j] == 0)
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] 
                    + obstacleGrid[i][j - 1];
                else
                    obstacleGrid[i][j] = 0;
            }
        }
    
        // Return value stored in rightmost bottommost cell. 
        // That is the destination.
        return obstacleGrid[R - 1][C - 1];
    }

    public void printGrid(int[][] grid) {
        System.out.println("Printing Grid:");
        for (int r = 0; r < grid.length; r++) {
            System.out.print((r == 0 ? "[ " : "  "));
            for (int c = 0; c < grid[0].length; c++) {
                System.out.print((c == 0 ? "[" : ""));
                String item = Integer.toString(grid[r][c]);
                System.out.print((item.length() == 2 ? " " : "  ") + item);
                System.out.print((c == grid[0].length - 1 ? " ]" : ""));
            }
            System.out.print(r == grid.length - 1 ? " ]" : "");
            System.out.print("\n");
        }
    }
                

    public static void main(String[] args) {
        // create an object for testing
        RobotMaze testObj = new RobotMaze();
        
        // test the simple case
        int[][] grid2 = new int[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid2[i][j] = 0;
            }
        }
        // notate the unpermitted square
        grid2[1][1] = -1;
        testObj.printGrid(grid2);
        int answer = testObj.uniquePaths(grid2);
        System.out.println("Result was " + answer);
        
        // complex grid
        // initialize a grid and fill with zeros
        int[][] grid = new int[6][6];
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                grid[i][j] = 0;
            }
        }
        // fill some squares with -1 to indicate an unpermitted square
        grid[0][2] = -1;
        grid[3][3] = -1;
        grid[4][5] = -1;
        grid[1][4] = -1;
        grid[4][0] = -1;
        testObj.printGrid(grid);
        answer = testObj.uniquePaths(grid);
        System.out.println("Result was " + answer);
        
    }
    
}
