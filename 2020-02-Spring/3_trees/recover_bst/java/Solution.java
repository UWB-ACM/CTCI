import java.util.ArrayList;
import java.util.List;

public class Solution {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    // Recursive inorder traversal with O(n) space
    public void inorderTraversal(TreeNode root, List<Integer> nodes) {
        if (root != null) {
            inorderTraversal(root.left, nodes);
            nodes.add(root.val);
            inorderTraversal(root.right, nodes);
        }
    }

    // Helper method that finds the first two values
    // that are not in ascending order
    public int[] findSwappedValues(List<Integer> values) {
        int length = values.size();
        int first = -1;
        int second = -1;
        for (int i = 0; i < length - 1; i++) {
            if (values.get(i + 1) < values.get(i)) {
                if (first == -1) {
                    first = values.get(i);
                    second = values.get(i + 1); 
                } else {
                    second = values.get(i + 1); 
                    break; 
                }
            }
        }
        return new int[]{first, second};
    }

    public void recover(TreeNode root, int first, int second) {
        
    }
 
    public void recoverTree(TreeNode root) {
        List<Integer> nodes = new ArrayList<>();
        inorderTraversal(root, nodes);
        int[] swapped = findSwappedValues(nodes);
        recover(root, swapped[0], swapped[1]);
        
    }
}

