
import java.util.*;

/**
 *
 * @author Angel
 */
public class Anagram {
	 
    public static List<List<String>> groupAnagrams(String[] strs) {
        if (strs.length == 0){
            return new ArrayList<>();
        }
        
        Map<String, List> map = new HashMap<>();
        
        for (String st:strs){
            
            char[] chars = st.toCharArray();
            
            Arrays.sort(chars);
            
            String key = String.valueOf(chars); // Converting the sorted char sequence into string
            
            if (!map.containsKey(key)) {
                map.put(key, new ArrayList());
            }
            
            map.get(key).add(st);
        }
        return new ArrayList(map.values());
    }


    public static List<List<String>> groupAnagramsOpt(String[] strs) {
        if (strs.length == 0) {
            return new ArrayList<>();
        }

        Map<String, List> map = new HashMap<>();

        for (String st : strs) {

            char[] chars = st.toCharArray();

            Arrays.sort(chars);

            String key = String.valueOf(chars); // Converting the sorted char sequence into string

            if (!map.containsKey(key)) {
                map.put(key, new ArrayList());
            }

            map.get(key).add(st);
        }
        return new ArrayList(map.values());
    }

    public static List<List<String>> groupAnagrams(String[] strs) {

        if (strs.length == 0) {
            return new ArrayList();
        }

        Map<String, List> map = new HashMap<>();

        int[] count = new int[26]; //Each letter in the alphabet is
        //represented by the array index

        for (String s : strs) {

            Arrays.fill(count, 0);

            for (char c : s.toCharArray()) {
                //counts how many times the char c appears in the string 
                ++count[c - 'a'];
            }

            StringBuilder sb = new StringBuilder("");

            for (int i = 0; i < 26; i++) {
                sb.append("#");
                sb.append(count[i]);//appending the times the index-represented character 
                //exist in the string
            }

            String word = sb.toString();

            if (!map.containsKey(word)) {
                map.put(word, new ArrayList());// add a new key value pair

            }
            map.get(word).add(s); //updates existing list of anagram strings

        }
        return new ArrayList(map.values());
    }

    public static void main(String[] args) {

        String[] words = {"eat", "tea", "tan", "ate", "nat", "bat"};

        List<List<String>> res = groupAnagramsOpt(words);

        for (List<String> anagrams : res) {
            System.out.print(anagrams + " ");
        }
        System.out.println("");

        String[] words2 = {"ab", "abb", "baa", "aba", "bab", "b"};

        List<List<String>> res2 = groupAnagramsOpt(words2);

        for (List<String> anagrams : res2) {
            System.out.print(anagrams + " ");
        }
        System.out.println("");

        String[] empty = {""};
        List<List<String>> emptyRes = groupAnagramsOpt(empty);

        for (List<String> anagrams : emptyRes) {
            System.out.print(anagrams + " ");
        }
        System.out.println("");

        String[] longList = {"abed", "bade", "bead", "abet", "beat", "beta",
            "acme", "acres", "actress", "airmen", "costar", "marine", "scare",
            "cares", "races", "casters", "actors", "remain", "castor", "recasts"};

        List<List<String>> longRes = groupAnagrams(longList);

        for (List<String> anagrams : longRes) {
            System.out.print(anagrams + " ");
        }
        System.out.println("");
    }

}
