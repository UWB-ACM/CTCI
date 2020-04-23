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
        print(c1);//expected ['h']
        reverseString(c2);
        print(c2);//expected ['e','h']
        reverseString(c3);
        print(c3);//expected ['o','l','l','e','h']
        reverseString(c4);
        print(c4);//expected ['w','a','c']
        reverseString(c5);
        print(c5);//expected ['r','a','c','e','c','a','r']
        reverseString(c6);
        print(c6);//expected ['4','3','2','1']
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
