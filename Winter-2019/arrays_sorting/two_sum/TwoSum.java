import java.util.HashMap;
import java.util.Map;

public class TwoSum {

    public int[] twoSum(int[] arr, int target) {
        // create an array for resulting indeces
        int[] result = null; // = new int[2];
        // check edge cases
        if (arr == null || arr.length < 2) {
            return result;
        }
        // create the map
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        // loop over array, build map
        for (int i = 0; i < arr.length; i++) {
            if (map.containsKey(target - arr[i])) {
                result = new int[2];
                result[0] = map.get(target - arr[i]);
                result[1] = i;
                return result;
            } else {
                map.put(arr[i], i);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        TwoSum ts = new TwoSum();
        int[] a1 = { 6, 13, 9, 4, -3, 8, 1, 3, 2, 7 };
        int[] ans = ts.twoSum(a1, 0);
        if (ans == null) return;
        System.out.println("result was " + ans[0] + " " + ans[1] + " (4, 7)");
        ans = ts.twoSum(a1, -4);
        if (ans != null) {
            System.out.println("Error");
        }
    }

}
