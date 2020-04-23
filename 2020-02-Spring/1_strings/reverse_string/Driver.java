public class Driver{
    public static void main (String []args){
        char [] c1 = {'h'};
        char [] c2 = {'h', 'e'};
        char [] c3 = {'h', 'e', 'l','l','o'};
        char [] c4 = {'c','a','w'};
        char [] c5 = {'r','a','c','e','c','a','r'};
        char [] c6 = {'1','2','3','4'};

        System.out.println("Output: ");
        reverseString(c1);
        print(c1);
        reverseString(c2);
        print(c2);
        reverseString(c3);
        print(c3);
        reverseString(c4);
        print(c4);
        reverseString(c5);
        print(c5);
        reverseString(c6);
        print(c6);
    }

    public static void print(char[] c){
        for(char i : c){
            System.out.print(i);
        }
        System.out.println();
    }

    //TO-DO: REPLACE YOUR SOLUTION HERE
    public static void reverseString(char[] s) {
        //TO-DO: REPLACE YOUR SOLUTION HERE
        
        // int left = 0, right = s.length - 1;
        // while (left < right) {
        //     char tmp = s[left];
        //     s[left++] = s[right];
        //     s[right--] = tmp;
        // }
    }

}