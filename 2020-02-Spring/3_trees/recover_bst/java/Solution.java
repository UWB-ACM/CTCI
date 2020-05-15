import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

// NOTE: Tree problems are slightly different in Java
//       because pointers are passed by value.

public class Solution {
    public static class TreeNode {
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

    ///////////////////////////////////////////////////////
    ////////////////// BASIC SOLUTION  ////////////////////
    ///////////////////////////////////////////////////////

    // Recursive inorder traversal with O(n) space
    public static void inorderTraversal(TreeNode root, List<Integer> nodes) {
        if (root != null) {
            inorderTraversal(root.left, nodes);
            nodes.add(root.val);
            inorderTraversal(root.right, nodes);
        }
    }

    // Helper method that finds the first two values
    // that are not in ascending order
    public static int[] findSwappedValues(List<Integer> values) {
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
    
    // Helper method that finds the nodes that have the given values
    // and swaps their values
    public static void fixSwaps(TreeNode root, int fixes, int first, int second) {
        if (root != null) {
            if (root.val == first || root.val == second) {
                if (root.val == first) {
                    root.val = second;
                } else {
                    root.val = first;
                }
                if (--fixes == 0) return;
            }
            fixSwaps(root.left, fixes, first, second);
            fixSwaps(root.right, fixes, first, second);
        }
    }

    public static void recoverTree(TreeNode root) {
        List<Integer> nodes = new ArrayList<>();
        inorderTraversal(root, nodes);
        int[] swapped = findSwappedValues(nodes);
        fixSwaps(root, 2, swapped[0], swapped[1]);
    }

    /////////////////////////////////////////////////////////
    ////////////////// OPTIMAL SOLUTION  ////////////////////
    /////////////////////////////////////////////////////////

    // Helper method for swapping the values of two nodes
    public static void swap(TreeNode a, TreeNode b) {
        int temp = a.val;
        a.val = b.val;
        b.val = temp;
    }

    public static void recoverTree2(TreeNode root) {
        TreeNode first = null;       // First swapped node
        TreeNode second = null;      // Second swapped node
        TreeNode predecessor = null; // For Morris traversal
        TreeNode previous = null;    // For finding the swapped nodes
        while (root != null) {
            if (root.left != null) {
                // Find inorder predecessor of root
                predecessor = root.left;
                while (predecessor.right != null && predecessor.right != root) {
                    predecessor = predecessor.right;
                }
                // If there is no link to the parent node
                // Create one, then visit the left subtree
                if (predecessor.right == null) {
                    predecessor.right = root;
                    root = root.left;
                } else {
                    // Link already exists. We're done with the left subtree
                    // Check to see if this node is swapped
                    if (previous != null && root.val < previous.val) {
                        second = root;
                        if (first == null) first = previous;
                    }
                    previous = root;          // Save this node for swap comparison

                    predecessor.right = null; // Break the existing link
                    root = root.right;        // Go to the right subtree
                }
            } else {
                // No left subtree. No need to check for predecessors. Just go right.

                // Check to see if this node is swapped
                if (previous != null && root.val < previous.val) {
                    second = root;
                    if (first == null) first = previous;
                }
                previous = root;          // Save this node for swap comparison

                root = root.right; // Go to the right subtree
            }
        }
        // We are done traversing through the tree.
        // We can swap the nodes now.
        swap(first, second);
    }

    //////////////////////////////////////////////////////////
    ////////////  METHODS FOR RUNNING TESTS  /////////////////
    //////////////////////////////////////////////////////////

    // Helper method that builds a binary tree in level order
    // from the given list of nodes
    public static TreeNode buildTree(List<Integer> nodes) {
        TreeNode root = insertNodes(nodes, null, 0);
        return root;
    }

    public static TreeNode insertNodes(List<Integer> nodes, TreeNode root, int index) {
        if (index < nodes.size() && nodes.get(index) != null) {
            TreeNode current = new TreeNode(nodes.get(index));
            root = current;
            root.left = insertNodes(nodes, root.left, 2 * index + 1);
            root.right = insertNodes(nodes, root.right, 2 * index + 2);
        }
        return root;
    }

    // Helper method that prints tree in inorder traversal
    public static void printTree(TreeNode root) {
        System.out.print("[");
        printTreeHelper(root);
        System.out.println("]");
    }

    public static void printTreeHelper(TreeNode root) {
        if (root != null) {
            printTreeHelper(root.left);
            System.out.print(" " + root.val + " ");
            printTreeHelper(root.right);
        }
    }

    public static void main(String[] args) {
        List<Integer> treeList1 = new ArrayList<>(Arrays.asList(1, 3, null, null, 2));
        List<Integer> treeList2 = new ArrayList<>(Arrays.asList(3, 1, 4, null, null, 2));

        TreeNode tree1Basic = buildTree(treeList1);
        TreeNode tree1Optimal = buildTree(treeList1);
        TreeNode tree2Basic = buildTree(treeList2);
        TreeNode tree2Optimal = buildTree(treeList2);

        System.out.println("Before: ");
        printTree(tree1Basic); // Before: [ 3 2 1 ]
        printTree(tree2Basic); // Before: [ 1 3 2 4 ]

        recoverTree(tree1Basic);
        recoverTree(tree2Basic);
        recoverTree2(tree1Optimal);
        recoverTree2(tree2Optimal);

        System.out.println("Basic: ");
        printTree(tree1Basic);      // After: [ 1 2 3 ]
        printTree(tree2Basic);      // After: [ 1 2 3 4 ]

        System.out.println("Optimal: ");
        printTree(tree1Optimal);    // After: [ 1 2 3 ]
        printTree(tree2Optimal);    // After: [ 1 2 3 4 ]
    }
}

