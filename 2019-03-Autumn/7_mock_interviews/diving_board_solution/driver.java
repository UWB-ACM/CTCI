import java.util.HashSet;
public class Driver {

    /**
     * Naive Recursive Solution
     */
//    static HashSet<Integer> allLengths(int k, int shorter, int longer) {
//        HashSet<Integer> lengths = new HashSet<Integer>();
//        getAllLengths(k, 0, shorter, longer, lengths);
//        return lengths;
//    }
//    static void getAllLengths(int k, int total, int shorter, int longer, HashSet<Integer> lengths){
//    if (k == 0) {
//        lengths.add(total);
//        return;
//    }
//    getAllLengths(k - 1, total + shorter, shorter, longer, lengths);
//    getAllLengths(k - 1, total + longer, shorter, longer, lengths);
//}

    /**
    * Improved Recursive Solution
    */
//    static HashSet<Integer> allLengths(int k, int shorter, int longer) {
//        HashSet<Integer> lengths = new HashSet<Integer>();
//        HashSet<String> visited = new HashSet<String>();
//        getAllLengths(k, 0, shorter, longer, lengths, visited);
//        return lengths;
//    }

//    static void getAllLengths(int k, int total, int shorter, int longer, HashSet<Integer> lengths, HashSet<String> visited) {
//        if (k == 0) {
//            lengths.add(total);
//            return;
//        }
//        String key = k + " " + total;
//        if (visited.contains(key)) {
//            return;
//        }
//        getAllLengths(k - 1, total + shorter, shorter, longer, lengths, visited);
//        getAllLengths(k - 1, total + longer, shorter, longer, lengths, visited);
//        visited.add(key);
//    }

    /**
     * Optimal Iterative Solution
     */
    static HashSet<Integer> allLengths(int k, int shorter, int longer) {
        HashSet<Integer> lengths = new HashSet<Integer>();
        for (int nShorter = 0; nShorter <= k; nShorter++) {
            int nLonger = k - nShorter;
            int length = nShorter * shorter + nLonger * longer;
            lengths.add(length);
        }
        return lengths;
    }

    public static void main(String[] args) {

        System.out.println("k = 2, shorter = 1, longer = 3");
        System.out.println("Expected Output: [2, 4, 6]");
        HashSet<Integer> lengths = allLengths(2, 1, 3);
        System.out.println("Output: " + lengths.toString());
        System.out.println();
        System.out.println("k = 5, shorter = 2, longer = 4");
        System.out.println("Expected Output: [16, 18, 20, 10, 12, 14]");
        HashSet<Integer> lengths2 = allLengths(5, 2, 4);
        System.out.println("Output: " + lengths2.toString());
        System.out.println();
        System.out.println("k = 4, shorter = 5, longer = 9");
        System.out.println("Expected Output: [32, 20, 36, 24, 28]");
        HashSet<Integer> lengths3 = allLengths(4, 5, 9);
        System.out.println("Output: " + lengths3.toString());
        System.out.println();
        System.out.println("k = 12, shorter = 3, longer = 8");
        System.out.println("Expected Output: [64, 96, 68, 100, 72, 104, 76, 108, 80, 84, 88, 60, 92]");
        HashSet<Integer> lengths4 = allLengths(12, 5, 9);
        System.out.println("Output: " + lengths4.toString());
    }
}


