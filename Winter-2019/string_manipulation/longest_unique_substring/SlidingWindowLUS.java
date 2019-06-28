import java.util.Set;
import java.util.HashSet;

// Sliding window approach
public class SlidingWindowLUS {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        Set<Character> set = new HashSet<>();
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            // try to extend the range [i, j]
            if (!set.contains(s.charAt(j))){
                set.add(s.charAt(j++));
                ans = Math.max(ans, j - i);
            }
            else {
                set.remove(s.charAt(i++));
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        SlidingWindowLUS test = new SlidingWindowLUS();
        int ans = test.lengthOfLongestSubstring("abcabcbb");
        System.out.println("abcabcbb: " + Integer.toString(ans));
        ans = test.lengthOfLongestSubstring("bbbbb");
        System.out.println("bbbbb: " + Integer.toString(ans));
    }
        
}

