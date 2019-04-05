import java.util.Arrays;

public class Anagram {
   
    /*
     * One way to find if two Strings are anagram in Java. This method
     * assumes both arguments are not null and in lowercase.
     *
     * @return true, if both String are anagram
     */
    public static boolean isAnagram(String word, String anagram){       
        if(word.length() != anagram.length()){
            return false;
        }
       
        char[] chars = word.toCharArray();
       
        for(char c : chars){
            int index = anagram.indexOf(c);
            if(index != -1){
                anagram = anagram.substring(0,index) + anagram.substring(index +1, anagram.length());
            }else{
                return false;
            }           
        }
       
        return anagram.isEmpty();
    }
   
    /*
     * Another way to check if two Strings are anagram or not in Java
     * This method assumes that both word and anagram are not null and lowercase
     * @return true, if both Strings are anagram.
     */
    public static boolean isAnagramNlogN(String word, String anagram){
        char[] charFromWord = word.toCharArray();
        char[] charFromAnagram = anagram.toCharArray();       
        Arrays.sort(charFromWord);
        Arrays.sort(charFromAnagram);
       
        return Arrays.equals(charFromWord, charFromAnagram);
    }
    
    public static void main(String[] args) {
        System.out.println("Testing isAnagram(): ");
        System.out.println("banana and aaannb: " + (isAnagram("banana", "aaannb") ? "true" : "false"));   
        System.out.println("debit card and bad credit: " + (isAnagram("debit card", "bad credit") ? "true" : "false"));   
        System.out.println("fancy and crafty: " + (isAnagram("fancy", "crafty") ? "true" : "false"));   
        System.out.println("schoolmaster and the classroom: " + (isAnagram("schoolmaster", "the classroom") ? "true" : "false"));   
        System.out.println("Testing isAnagramNlogN(): ");
        System.out.println("banana and aaannb: " + (isAnagramNlogN("banana", "aaannb") ? "true" : "false"));   
        System.out.println("debit card and bad credit: " + (isAnagramNlogN("debit card", "bad credit") ? "true" : "false"));   
        System.out.println("fancy and crafty: " + (isAnagramNlogN("fancy", "crafty") ? "true" : "false"));   
        System.out.println("schoolmaster and the classroom: " + (isAnagramNlogN("schoolmaster", "the classroom") ? "true" : "false"));   
    }
}
