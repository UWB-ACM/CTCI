import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Driver {

    //Approach 1
    static int[] twoSum(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] == target - nums[i]) {
                    return new int[] { i, j };
                }
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }

//    //Approach 2
//    static int[] twoSum(int[] nums, int target) {
//        Map<Integer, Integer> map = new HashMap<>();
//        for (int i = 0; i < nums.length; i++) {
//            map.put(nums[i], i);
//        }
//        for (int i = 0; i < nums.length; i++) {
//            int complement = target - nums[i];
//            if (map.containsKey(complement) && map.get(complement) != i) {
//                return new int[] { i, map.get(complement) };
//            }
//        }
//        throw new IllegalArgumentException("No two sum solution");
//    }
//
//    //Approach 3
//    static int[] twoSum(int[] nums, int target) {
//        Map<Integer, Integer> map = new HashMap<>();
//        for (int i = 0; i < nums.length; i++) {
//            int complement = target - nums[i];
//            if (map.containsKey(complement)) {
//                return new int[]{map.get(complement), i };
//            }
//            map.put(nums[i], i);
//        }
//        throw new IllegalArgumentException("No two sum solution");
//    }

    public static void main(String[] args){
        int[] arrayOne = {1,2,3,4,5};
        int[] arrayTwo = {9,4,-5,2,1};
        int[] arrayThree = {4,3,5,1,2};

        int targetOne = 3;
        int targetTwo = 4;
        int targetThree = 20;

        System.out.println("Test Case #1");
        System.out.println("input: " + Arrays.toString(arrayOne));
        System.out.println("Target: " + targetOne);
        System.out.println("Expected Output: [0, 1]");

        System.out.println();
        System.out.println("After array and target passed to twoSum method...");
        System.out.println("Output: " + Arrays.toString(twoSum(arrayOne, targetOne)));

        System.out.println();
        System.out.println("Test Case #2");
        System.out.println("input: " + Arrays.toString(arrayTwo));
        System.out.println("Target: " + targetTwo);
        System.out.println("Expected Output: [0, 2]");

        System.out.println();
        System.out.println("After array and target passed to twoSum method...");
        System.out.println("Output: " + Arrays.toString(twoSum(arrayTwo, targetTwo)));

        System.out.println();
        System.out.println("Test Case #3");
        System.out.println("input: " + Arrays.toString(arrayThree));
        System.out.println("Target: " + targetThree);
        System.out.println("Expected Output: Illegal Argument Exception: No Solution");

        System.out.println();
        System.out.println("After array and target passed to twoSum method...");
        System.out.println("Output: " + Arrays.toString(twoSum(arrayThree, targetThree)));

    }

}
