import java.util.Stack;

public class Main {

    public static String removeKdigits(String num, int k) {
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
        String str = "765028321";
        String str1 = "478502841";
        int n = 5;
        System.out.println("Input1: " + str);
        String result = removeKdigits(str, n);
        System.out.println("Output1: " + result);
        System.out.println("Input2: " + str1);
        String result2 = removeKdigits(str1, n);
        System.out.println("Output2: " + result2);
    }
}
