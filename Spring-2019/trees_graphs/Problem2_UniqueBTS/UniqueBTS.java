import java.util.*;
import java.util.ArrayList;
import java.util.List;
public class UniqueBTS {

    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { this.val = x; left=right=null;}
     }


    public static List<TreeNode> generateTrees(int n) {
        if(n==0){
            return new ArrayList<TreeNode>();
        }
        return helper(1, n);
    }

    public static List<TreeNode> helper(int m, int n){
        List<TreeNode> result = new ArrayList<TreeNode>();
        if(m>n){
            result.add(null);
            return result;
        }
        for(int i=m; i<=n; i++){
            List<TreeNode> ls = helper(m, i-1);
            List<TreeNode> rs = helper(i+1, n);
            for(TreeNode l: ls){
                for(TreeNode r: rs){
                    TreeNode curr = new TreeNode(i);
                    curr.left=l;
                    curr.right=r;
                    result.add(curr);
                }
            }
        }
        return result;
    }

    static void preorder(TreeNode root)
    {
        if (root != null) {
            System.out.print(root.val + ", ");
            preorder(root.left);
            preorder(root.right);
        }

    }

    public static void main(String args[])
    {
        ArrayList<TreeNode> totalTreesFrom1toN = (ArrayList<TreeNode>) generateTrees(4);
        System.out.println("The total of unique binary search trees: " +totalTreesFrom1toN.size());
        System.out.println("Generate the tree in preorder traversal");
        for (int i = 0; i < totalTreesFrom1toN.size(); i++)
        {
            System.out.print("[");
            preorder(totalTreesFrom1toN.get(i));
            System.out.print("]");
            System.out.println();

        }
    }
}
