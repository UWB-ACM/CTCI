import java.util.Stack;

public class Main {

    public String removeKdigits(String num, int k) {
        if (num.length() == 0) {
            return "0";
        }
        Stack<Character> stack = new Stack<>();
        for (char c : num.toCharArray()) {
            while (!stack.isEmpty() && k > 0 && stack.peek() > c) {
                stack.pop();
                k--;
            }
            stack.push(c);
        }
        while (stack.size() > num.length() - k) {
            stack.pop();
        }
        StringBuilder rst = new StringBuilder();
        while (!stack.isEmpty()) {
            rst.append(stack.pop());
        }
        int index = rst.length();
        while (index > 0 && rst.charAt(index - 1) == '0') {
            index--;
        }
        rst.delete(index, rst.length());
        return rst.length() == 0 ? "0" : rst.reverse().toString();
    }

    public static void main(String[] args) {
        Main test = new Main();
        String str = "765028321";
        String str1 = "478502841";
        int n = 5;
        System.out.println("Input1: " + str);
        String result = test.removeKdigits(str, n);
        System.out.println("Output1: " + result);
        System.out.println("Input2: " + str1);
        String result2 = removeKdigits(str1, n);
        System.out.println("Output2: " + result2);
        n = 3;
        String str2 = "1432219";
        System.out.println("Input3: " + str2);
        String result3 = test.removeKdigits(str2, n);
        System.out.println("Output3: " + result3);
        n = 1;
        String str3 = "10200";
        System.out.println("Input4: " + str3);
        String result4 = removeKdigits(str3, n);
        System.out.println("Output4: " + result4);
    }
}
