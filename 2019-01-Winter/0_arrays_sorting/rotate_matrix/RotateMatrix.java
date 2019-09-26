public class RotateMatrix {


    // problem implementation
    public void rotate(int[][] matrix) {
        if (matrix == null || matrix.length <= 1) {
            return;
        }
        int n = matrix.length;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int i = 0; i < n; i++) {
            int head = 0;
            int tail = n - 1;
            while (head < tail) {
                int temp = matrix[i][head];
                matrix[i][head] = matrix[i][tail];
                matrix[i][tail] = temp;
                head++;
                tail--;
            }
        }
    }

    // utility method to print the matrix
    public void printArray(int[][] arr) {
        System.out.print("[ ");
        if (arr.length == 0) {
            System.out.println("]");
            return;
        }
        for (int i = 0; i < arr.length; i++) {
            if (i != 0) System.out.print("  ");
            System.out.print("[ ");
            for (int j = 0; j < arr[0].length; j++) {
                System.out.print(arr[i][j]);
                if (j < arr[0].length - 1) {
                    System.out.print(", ");
                }
            }
            System.out.println(" ]");
            if (i == arr.length - 1) System.out.println(" ]");
        }
    }

    // driver
    public static void main(String[] args) {
        RotateMatrix rm = new RotateMatrix();
        int[][] m1 = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
        System.out.println("Before rotation:");
        rm.printArray(m1);
        rm.rotate(m1);
        System.out.println("After rotation:");
        rm.printArray(m1);
    }

}
