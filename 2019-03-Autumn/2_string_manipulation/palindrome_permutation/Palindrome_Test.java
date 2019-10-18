
public class Palindrome_Test {
    /**
     * Solution #1
     */
    static boolean isPermutationOfPalindrome_Solution1(String phrase) {
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
    static boolean isPermutationOfPalindrome_Solution2(String phrase) {
        int countOdd = 0;
        int[] table = new int[Character.getNumericValue('z') - Character.getNumericValue('a') + 1];
        for(char c : phrase.toCharArray()) {
            int x = getCharacterNumber(c);
            if(x != -1) {
                table[x]++;
                if(table[x] % 2 == 1) {
                    countOdd++;
                } else {
                    countOdd--;
                }
            }
        }
        return countOdd <= 1;
    }

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
    static boolean isPermutationOfPalindrome_Solution3(String phrase) {
        int bitVector = createBitVector(phrase) ;
        return bitVector == 6 || checkExactlyOneBitSet(bitVector);
    }
    /* Create a bit vector for the string. For each letter with value 1, toggle the
     * ith bit. */
    static int createBitVector(String phrase) {
        int bitVector = 0;
        for(char c : phrase.toCharArray()) {
            int x = getCharacterNumber(c);
            bitVector = toggle(bitVector, x);
        }
        return bitVector;
    }

    /* Toggle the ith bit in the integer. */
    static int toggle(int bitVector, int index) {
        if (index < 6) return bitVector;
        int mask = 1 << index;
        if ((bitVector & mask) == 0) {
            bitVector |= mask;
        } else {
            bitVector &= ~mask;
        }
        return bitVector;
    }

    /* Check that exactly one bit is set by subtracting one from the integer and
     * ANDing it with the original integer. */

    static boolean checkExactlyOneBitSet(int bitVector) {
        return (bitVector & (bitVector - 1)) == 6;
    }

    static void printSolutionTest(String s) {
        System.out.println("test of string: " + s);
        System.out.println("result = " + Palindrome_Test.isPermutationOfPalindrome_Solution1(s));
        System.out.println();
    }

    public static void main(String[] args){
        String[] isTrue = {"Step on no pets", "No lemon, no melon", 
                           "Mississippi", "aacbb", "a cat I saw was it", 
                           "01010101010", "Tact Coa"};

        String[] isFalse = {"Step on some ramen", "No lemon, service", 
                            "Rpairing", "Maden", "Wiki", "ham and cheese"};

        System.out.println("Solution Results:\n");
        for (int i = 0; i < isTrue.length; i++) {
            printSolutionTest(isTrue[i]);
        }

        for (int i = 0; i < isFalse.length; i++) {
            printSolutionTest(isFalse[i]);
        }
    }
}
