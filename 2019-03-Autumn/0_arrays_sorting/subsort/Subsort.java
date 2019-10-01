public class Subsort {
    public static int[] subsort(int[] array) {
        // edge case
        // if array is empty or length 1, no sorting is required. 
        // return -1 as indeces (or null, if the client can guarantee null checking)
        if (array.length <= 1) return new int[]{-1, -1};

        // find bounds for sorted LHS 
        int lhs = getSortedLhs(array);
        // if LHS spans entire array, we can return a minimal window of 0 length
        if (lhs >= array.length - 1) return new int[]{-1, -1};

        // find bounds for sorted RHS
        int rhs = getSortedRhs(array);
        // find min and max in center section
        int min = array[lhs];
        int max = array[rhs];
        for (int i = lhs; i <= rhs; i++) {
            if (array[i] < min) min = array[i];
            if (array[i] > max) max = array[i];
        }

        // Shrink LHS and RHS segments so that 
        // all LHS items are less than min and 
        // all RHS items are greater than max.
        while (lhs > 0 && array[lhs - 1] > min) lhs--;
        while (rhs < array.length - 2 && array[rhs + 1] < max) rhs++;

        return new int[]{lhs, rhs};
    }

    private static int getSortedLhs(int[] arr) {
        for (int i = 1; i < arr.length; i++)
            if (arr[i] < arr[i-1]) return i;
        // because we move right, maximum bound is array's last idx
        return arr.length - 1;
    }

    private static int getSortedRhs(int[] arr) {
        for (int i = arr.length - 1; i > 0; i--)
            if (arr[i - 1] > arr[i]) return i;
        // because we move left, minimum bound is 0
        return 0;
    }

    private static void printArray(int[] arr) {
        System.out.print("Array: [ ");
        for (int i = 0; i < arr.length - 1; i++) System.out.print(arr[i] + ", ");
        if (arr.length > 0) System.out.print(arr[arr.length - 1] + " ");
        System.out.println("]");
    }

    public static void main(String[] args) {
        // make test cases
        int[] test1 = new int[]{1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
        printArray(test1);
        System.out.print("Result: ");
        printArray(subsort(test1));
        int[] test2 = new int[]{9, 8, 7, 6, 14, 15, 16, 17, 18};
        printArray(test2);
        System.out.print("Result: ");
        printArray(subsort(test2));
        int[] test3 = new int[]{};
        printArray(test3);
        System.out.print("Result: ");
        printArray(subsort(test3));
        int[] test4 = new int[]{1, 2, 3, 4, 5, 6, 7, 10, 15, 20};
        printArray(test4);
        System.out.print("Result: ");
        printArray(subsort(test4));
        int[] test5 = new int[]{10, 9, 8, 6, 5, 3, 2, 1, 0};
        printArray(test5);
        System.out.print("Result: ");
        printArray(subsort(test5));
    }
}
