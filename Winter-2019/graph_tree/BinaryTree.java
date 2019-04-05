import java.lang.Math;

public class BinaryTree {
    
    private BinTreeNode root;

    public BinaryTree (String[] arr) {
        BinTreeNode currNode = root;
        int count = 0;
        int height = 0;
        while (count < arr.length) {
            currNode = root;
            if (count == 0) {
                root = new BinTreeNode();
                root.data = arr[count];
            } else {
                int resid = count - (int) Math.floor(Math.pow(2, height) - 1);
                for (int i = height - 1; i > 0; i--) {
                    if (resid / (int) Math.pow(2, i) == 0) {
                        currNode = currNode.left;
                    } else {
                        currNode = currNode.right;
                    }
                }
                if ((count - (int) Math.floor(Math.pow(2, height) - 1)) % 2 == 0) {
                    currNode.left = new BinTreeNode();
                    currNode.left.data = arr[count];
                } else {
                    currNode.right = new BinTreeNode();
                    currNode.right.data = arr[count];
                }
            }
            count++;
            if (Math.pow(2, height + 1) - 1 <= count) {
                height++;
            }
        }
    }

    public boolean validate() {
        return validateHelper(this.root, null, null);
    }

    private boolean validateHelper(BinTreeNode currNode, String min, String max) {
        if (currNode == null) {
            return true;
        }
        if (min != null && currNode.data.compareTo(min) <= 0) {
            return false;
        }
        if (max != null && currNode.data.compareTo(max) > 0) {
            return false;
        }
        boolean lhsIsValid = false;
        lhsIsValid = validateHelper(currNode.left, min, currNode.data);
        boolean rhsIsValid = false;
        rhsIsValid = validateHelper(currNode.right, currNode.data, max);
        if (!lhsIsValid || !rhsIsValid) {
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        String[] arr = {"d", "b", "f", "a", "c", "e", "g"};
        BinaryTree b = new BinaryTree(arr);
        System.out.println("first tree is valid? " + (b.validate() ? "true" : "false"));
        // expecting failures for the following trees
        String[] fail1 = {"e", "b", "g", "a", "k", "f", "h"};
        BinaryTree f1 = new BinaryTree(fail1);
        String[] fail2 = {"a", "b", "c", "d", "e", "f", "g"};
        BinaryTree f2 = new BinaryTree(fail2);
        String[] fail3 = {"m", "b", "a", "a", "l", "x", "z"};
        BinaryTree f3 = new BinaryTree(fail3);
        System.out.println("second tree is valid? " + (f1.validate() ? "true" : "false"));
        System.out.println("third tree is valid? " + (f2.validate() ? "true" : "false"));
        System.out.println("fourth tree is valid? " + (f3.validate() ? "true" : "false"));
    }
}
