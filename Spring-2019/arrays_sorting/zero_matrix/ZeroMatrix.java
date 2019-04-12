public class ZeroMatrix {

    // Method definition for solution
    public int[][] zeroes(int[][] arr) {
        // Edge case: empty array
        if (arr.length == 0 || arr[0].length == 0) {
            return arr;
        }
        boolean nulCol0 = false;
        boolean nulRow0 = false;
        // First, locate zeroes in the matrix, and replace row/col header 
        // with zeroes when they occur for indeces 1-m and 1-n.
        // Replacement in this fasion will let us go back to the first 
        // row and first column of the matrix to replace full row/col.
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                if ((i == 0 || j == 0) && arr[i][j] == 0) {
                    // we need to know whether to nullfiy the first 
                    // row or first column
                    if (i == 0) nulRow0 = true;
                    if (j == 0) nulCol0 = true;
                } else if (arr[i][j] == 0) {
                    arr[0][j] = 0;
                    arr[i][0] = 0;
                }
            }
        }
        // Now that our first row and column has zeroes marking the 
        // rows and columns that require replacement, iterate over the 
        // first row and first column to replace the respective column 
        // or row with zeroes.
        // NOTE: arr.length    ---> row index
        // NOTE: arr[0].length ---> column index
        // Nullify rows below row 0
        for (int i = 1; i < arr.length; i++) {
            if (arr[i][0] == 0) {
                for (int j = 0; j < arr[0].length; j++) {
                    arr[i][j] = 0;
                }
            }
        }
        // Nullify all columns
        for (int i = 1; i < arr[0].length; i++) {
            if (arr[0][i] == 0) {
                for (int j = 0; j < arr.length; j++) {
                    arr[j][i] = 0;
                }
            }
        }
        // if boolean conditional for first row/col was true, 
        // nullify first row or col respectively
        if (nulRow0) {
            for (int i = 0; i < arr[0].length; i++) {
                arr[0][i] = 0;
            }
        }
        if (nulCol0) {
            for (int i = 0; i < arr.length; i++) {
                arr[i][0] = 0;
            }
        }
        return arr;
    }

    public static void main(String[] args) {
        ZeroMatrix zm = new ZeroMatrix();
        PrintUtil util = new PrintUtil();
        // test a simple example
        System.out.println("First Example: basic example");
        int[][] arr = { {1, 4, -3, 2, 5},
                        {2, 0, 4, 6, 3},
                        {10, 12, 6, 4, 9} };
        util.printGrid(arr);
        arr = zm.zeroes(arr);
        util.printGrid(arr);
        // test an edge case: 0 in first row or col
        System.out.println("\nSecond Example: 0 in arr[0][0]");
        int[][] arr1 = { {0, 3, 6, 18, 44, 2, 9},
                         {19, 12, 3, 2, 4, 9, 9},
                         {66, -3, 2, 4, 19, 0, 1},
                         {1, 6, 13, 4, 10, -3, 2},
                         {14, 8, 19, 2, 66, 2, 9},
                         {5, 2, 1, 3, 666, 22, 1} };
        util.printGrid(arr1);
        arr1 = zm.zeroes(arr1);
        util.printGrid(arr1);
        System.out.println("Second Example: 0 in first row and first column (not [0][0]");
        int[][] arr4 = { {3, 6, 9, 12, 0, 4, 2},
                         {14, 6, 3, 22, 5, 2, 4},
                         {0, 2, 9, 6, 14, 3, 11},
                         {-1, 2, 7, 6, 4, 9, 3} }; 
        util.printGrid(arr4);
        arr4 = zm.zeroes(arr4);
        util.printGrid(arr4);
        // test an edge case: empty array
        System.out.println("\nThird Example: null arrays");
        int[][] arr2 = {{}};
        util.printGrid(arr2);
        arr2 = zm.zeroes(arr2);
        util.printGrid(arr2);
        int[][] arr3 = {};
        util.printGrid(arr3);
        arr3 = zm.zeroes(arr3);
        util.printGrid(arr3);
    }

}
