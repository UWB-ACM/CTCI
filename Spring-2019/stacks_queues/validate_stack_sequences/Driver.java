import java.util.Stack;
import java.util.Arrays;

public class Driver {
    public static boolean validateStackSequences(int[] pushed, int[] popped) {
        int N = pushed.length;
        Stack<Integer> stack = new Stack<Integer>();

        int j = 0;
        for (int x : pushed) {
            stack.push(x);
            while (!stack.isEmpty() && j < N && stack.peek() == popped[j]) {
                stack.pop();
                j++;
            }
        }

        return j == N;
    }

    public static void main(String[] args) {
        int[] pushed = {1,2,3,4,5};
        int[] poppedCorrect = {4,5,3,2,1};
        int[] poppedIncorrect = {4,3,5,1,2};

        System.out.println("Pushed: " + Arrays.toString(pushed) + ", Popped: " + Arrays.toString(poppedCorrect) + ", Output: " + validateStackSequences(pushed, poppedCorrect));
        System.out.println("Pushed: " + Arrays.toString(pushed) + ", Popped: " + Arrays.toString(poppedIncorrect) + ", Output: " + validateStackSequences(pushed, poppedIncorrect));
        
        int[] pushed1 = {10, 11, 12, 13, 14, 15, 16};
        int[] poppedCor1 = {10, 11, 12, 13, 14, 15, 16};
        int[] poppedCor2 = {13, 16, 15, 14, 12, 11, 10};
        int[] poppedIncor1 = {10, 11, 12, 13, 14, 15, 17};
        int[] poppedIncor2 = {16, 16, 16, 16, 16, 16, 16};
        System.out.println("Pushed: " + Arrays.toString(pushed1) + ", Popped: " + Arrays.toString(poppedCor1) + ", Output: " + validateStackSequences(pushed1, poppedCor1));
        System.out.println("Pushed: " + Arrays.toString(pushed1) + ", Popped: " + Arrays.toString(poppedCor2) + ", Output: " + validateStackSequences(pushed1, poppedCor2));
        System.out.println("Pushed: " + Arrays.toString(pushed1) + ", Popped: " + Arrays.toString(poppedIncor1) + ", Output: " + validateStackSequences(pushed1, poppedIncor1));
        System.out.println("Pushed: " + Arrays.toString(pushed1) + ", Popped: " + Arrays.toString(poppedIncor2) + ", Output: " + validateStackSequences(pushed1, poppedIncor2));
    }
}
