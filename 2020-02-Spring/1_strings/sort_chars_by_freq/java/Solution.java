import java.util.Collections; 
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Solution {
    public static void main(String[] args) {
        System.out.println(frequencySort1("hello"));    // Expected "eert" or "eetr"
        System.out.println(frequencySort1("tree"));     // Expected "lleho", "llheo", "llohe", "lloeh", "lleoh", etc
        System.out.println(frequencySort1("cccaaa"));   // Expected "aaaccc" or "cccaaa"
        System.out.println(frequencySort1("Aabb"));     // Expected "bbAa"
        System.out.println(frequencySort1(""));         // Expected ""

        System.out.println(frequencySort2("hello"));    // Expected "eert" or "eetr"
        System.out.println(frequencySort2("tree"));     // Expected "lleho", "llheo", "llohe", "lloeh", "lleoh", etc
        System.out.println(frequencySort2("cccaaa"));   // Expected "aaaccc" or "cccaaa"
        System.out.println(frequencySort2("Aabb"));     // Expected "bbAa"
        System.out.println(frequencySort2(""));         // Expected ""
    }

    public static String frequencySort1(String word) {
        // Edge case handling
        if (word == null || word.isEmpty()) {
            return word;
        }

        // Create an array of sorted characters 
        // [ 'h', 'e', 'l', 'l', 'o'] --> ['e', 'h', 'l', 'l' 'o']
        char[] chars = word.toCharArray();
        Arrays.sort(chars); // Sorts lexigraphically by default

        // Combine identical groups of characters into Strings
        // ['e', 'h', 'l', 'l', 'o'] --> ["e", "h", "ll", "o"]
        List<String> identicalGroups = new ArrayList<String>();
        StringBuilder group = new StringBuilder();
        group.append(chars[0]);
        for (int i = 1; i < chars.length; i++) {
            if (chars[i] != chars[i - 1]) {
                identicalGroups.add(group.toString());   // Add the group we just finished
                group = new StringBuilder();     // Start a new group of characters
            }
            group.append(chars[i]);
        }
        identicalGroups.add(group.toString());

        // Sort the groups of characters by length, from longest to shortest
        // ["e", "h", "ll", "o"] --> ["ll", "e", "h", "o"]
        Collections.sort(identicalGroups, (a, b) -> b.length() - a.length());
        
        // Combine the groups of characters into our final result
        // ["ll", "e", "h", "o"] --> "lleho"
        StringBuilder result = new StringBuilder();
        for (String s : identicalGroups) {
            result.append(s);
        }
        return result.toString();
    }


    public static String frequencySort2(String word) {
        // Edge case handling
        if (word == null || word.isEmpty()) {
            return word;
        }

        // Create a frequency map that contains the number of times
        // each character occurs in the word
        // [ 't', 'r', 'e', 'e' ] --> { 't' : 1, 'r' : 1, 'e' : 2}
        Map<Character, Integer> counts = new HashMap<>();
        for (char ch : word.toCharArray()) {
            if (!counts.containsKey(ch)) {
                counts.put(ch, 1);
            } else {
                counts.put(ch, counts.get(ch) + 1);
            }
        }

        // Sort the characters by the number of times they occur
        // in ascending order
        // { 't' : 1, 'r' : 1, 'e' : 2} --> { 'e' : 2, 't' : 1, 'r' : 1 }
        List<Character> chars = new ArrayList<>(counts.keySet());
        Collections.sort(chars, (a, b) -> counts.get(b) - counts.get(a));

        // Combine the sorted key-value pairs into our final result
        // { 'e' : 2, 't' : 1, 'r' : 1 }  --> "eetr"
        StringBuilder result = new StringBuilder();
        for (Character ch : chars) {
            int repetitions = counts.get(ch);
            for (int i = 0; i < repetitions; i++) {
                result.append(ch);
            }
        }
        return result.toString();
    }


    
}