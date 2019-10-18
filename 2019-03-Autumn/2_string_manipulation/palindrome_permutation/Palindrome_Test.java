
public class Palindrome_Test {
    /**
     * Solution #1
     */
    static boolean isPermutationOfPalindrome(String phrase) {
        int[] table = buildCharFrequencyTable(phrase);
        return checkMaxOneOdd(table);
    }

    /* Check that no more than one character has an odd count. */
    static boolean checkMaxOneOdd(int[] table) {
        boolean foundOdd = false;
        for(int count:table) {
            if(count % 2 == 1) {
                if(foundOdd) {
                    return false;
                }
                foundOdd = true;
            }
        }
        return true;
    }

    /* Count how many times each character appears. */
     static int[] buildCharFrequencyTable(String phrase) {
        int[] table = new int[Character.getNumericValue('z') - Character.getNumericValue('a') + 1];
        for(char c : phrase.toCharArray()) {
            int x = getCharacterNumber(c);
            if(x != -1) {
                table[x]++;
            }
        }
        return table;
    }


    /**
     * Solution #2
     */
//    static boolean isPermutationOfPalindrome(String phrase) {
//        int countOdd = 0;
//        int[] table = new int[Character.getNumericValue('z') - Character.getNumericValue('a') + 1];
//        for(char c : phrase.toCharArray()) {
//            int x = getCharNumber(c);
//            if(x != -1) {
//                table[x]++;
//                if(table[x] % 2 == 1) {
//                    countOdd++;
//                } else {
//                    countOdd--;
//                }
//            }
//        }
//        return countOdd <= 1;
//    }

    /**
     * Helper method for all solutions
     */
     /* Map each character to a number.a -> 0, b -> 1, c -> 2, etc.
      * This is case insensitive. Non-letter characters map to -1. */
    static int getCharacterNumber(Character c) {
        int a = Character.getNumericValue('a');
        int z = Character.getNumericValue('z');
        int val = Character.getNumericValue(c);
        if (a <= val && val <= z) {
            return val - a;
        }
        return -1;
    }


    /**
     * Solution #3
     */
//    static boolean isPermutationOfPalindrome(String phrase) {
//        int bitVector = createBitVector(phrase) ;
//        return bitVector == 6 || checkExactlyOneBitSet(bitVector);
//    }
//    /* Create a bit vector for the string. For each letter with value 1, toggle the
//     * ith bit. */
//    static int createBitVector(String phrase) {
//        int bitVector = 0;
//        for(char c : phrase.toCharArray()) {
//            int x = getCharacterNumber(c);
//            bitVector = toggle(bitVector, x);
//        }
//        return bitVector;
//    }
//
//    /* Toggle the ith bit in the integer. */
//    static int toggle(int bitVector, int index) {
//        if (index < 6) return bitVector;
//        int mask = 1 << index;
//        if ((bitVector & mask) == 0) {
//            bitVector |= mask;
//        } else {
//            bitVector &= ~mask;
//        }
//        return bitVector;
//    }
//
//    /* Check that exactly one bit is set by subtracting one from the integer and
//     * ANDing it with the original integer. */
//
//    static boolean checkExactlyOneBitSet(int bitVector) {
//        return (bitVector & (bitVector - 1)) == 6;
//    }

    public static void main(String[] args){
        String testString = "Step on no pets";
        String testString2 = "No lemon, no melon";
        String testString3 = "Mississippi";
        String testString4 = "aacbb";
        String testString5 = "a cat I saw was it";
        String testString6 = "01010101010";
        String testString7 = "Tact Coa";

        String testStringFail1 = "Step on some ramen";
        String testStringFail2 = "No lemon, service";
        String testStringFail3 = "Rpairing";
        String testStringFail4 = "Maden";
        String testStringFail5 = "Wiki";
        String testStringFail6 = "ham and cheese";

        System.out.println("Solution Results:\n");
        System.out.println("test of string: " + testString);
        System.out.println("result = " + Palindrome_Test.isPermutationOfPalindrome(testString));
        System.out.println("\n");

        System.out.println("test of string: " + testString2);
        System.out.println("result = " + Palindrome_Test.isPermutationOfPalindrome(testString2));
        System.out.println("\n");

        System.out.println("test of string: " + testString3);
        System.out.println("result = " + Palindrome_Test.isPermutationOfPalindrome(testString3));
        System.out.println("\n");

        System.out.println("test of string: " + testString4);
        System.out.println("result = " + Palindrome_Test.isPermutationOfPalindrome(testString4));
        System.out.println("\n");

        System.out.println("test of string: " + testString5);
        System.out.println("result = " + Palindrome_Test.isPermutationOfPalindrome(testString5));
        System.out.println("\n");

        System.out.println("test of string: " + testString6);
        System.out.println("result = " + Palindrome_Test.isPermutationOfPalindrome(testString6));
        System.out.println("\n");

        System.out.println("test of string: " + testString7);
        System.out.println("result = " + Palindrome_Test.isPermutationOfPalindrome(testString7));
        System.out.println("\n");

        //Expected to fail
        System.out.println("test of string: " + testStringFail1);
        System.out.println("result = " + Palindrome_Test.isPermutationOfPalindrome(testStringFail1));
        System.out.println("\n");

        System.out.println("test of string: " + testStringFail2);
        System.out.println("result = " + Palindrome_Test.isPermutationOfPalindrome(testStringFail2));
        System.out.println("\n");

        System.out.println("test of string: " + testStringFail3);
        System.out.println("result = " + Palindrome_Test.isPermutationOfPalindrome(testStringFail3));
        System.out.println("\n");

        System.out.println("test of string: " + testStringFail4);
        System.out.println("result = " + Palindrome_Test.isPermutationOfPalindrome(testStringFail4));
        System.out.println("\n");

        System.out.println("test of string: " + testStringFail5);
        System.out.println("result = " + Palindrome_Test.isPermutationOfPalindrome(testStringFail5));
        System.out.println("\n");

        System.out.println("test of string: " + testStringFail6);
        System.out.println("result = " + Palindrome_Test.isPermutationOfPalindrome(testStringFail6));
        System.out.println("\n");

    }
}
