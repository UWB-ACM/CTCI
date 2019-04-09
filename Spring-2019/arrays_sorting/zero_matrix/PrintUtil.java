public class PrintUtil {

    public void printGrid(int[][] grid) {
        System.out.println("Printing Grid:");
        for (int r = 0; r < grid.length; r++) {
            System.out.print((r == 0 ? "[ " : "  "));
            for (int c = 0; c < grid[0].length; c++) {
                System.out.print((c == 0 ? "[" : ""));
                String item = Integer.toString(grid[r][c]);
                System.out.print((item.length() == 2 ? "  " : (item.length() == 3 ? " " : "   ")) + item);
                System.out.print((c == grid[0].length - 1 ? " ]" : ""));
            }
            System.out.print(r == grid.length - 1 ? " ]" : "");
            System.out.print("\n");
        }
    }

}
