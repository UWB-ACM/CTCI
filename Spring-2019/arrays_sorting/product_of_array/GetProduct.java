// Class Definition
public class GetProduct {

    // Solution Method Definition
    // Note: this is the optimized solution
    public int[] arrayProduct(int[] start) {
        int total = 1;
        int nonZeroTotal = 1;
        int zeroCount = 0;
        // get total product of array
        for (int i = 0; i < start.length; i++) {
            if (start[i] == 0) {
                zeroCount++;
                total = 0;
            } else {
                total *= start[i];
                nonZeroTotal *= start[i];
            }
        }
        // create new array to store result
        int[] result = new int[start.length];
        for (int i = 0; i < start.length; i++) {
            if (start[i] == 0) {
                result[i] = (zeroCount == 1 ? nonZeroTotal : 0);
            } else {
                result[i] = total / start[i];
            }
        }
        return result;
    }

    public String printArray(int[] array) {
        String result = "";
        for (int i = 0; i < array.length; i++) {
            result += array[i] + " ";
        }
        return result;
    }

    public static void main(String[] args) {
        GetProduct tester = new GetProduct();
        int[] test = {1, 2, 3, 4, 5, 6};
        int[] result = tester.arrayProduct(test);
        System.out.println("Original is:\t" + tester.printArray(test));
        System.out.println("Result is:\t" + tester.printArray(result));
        int[] test1 = {2, 5, 9, 1, 0, 6, -3, 12, -1};
        int[] result1 = tester.arrayProduct(test1);
        System.out.println("Original is:\t" + tester.printArray(test1));
        System.out.println("Result is:\t" + tester.printArray(result1));
    }
}
