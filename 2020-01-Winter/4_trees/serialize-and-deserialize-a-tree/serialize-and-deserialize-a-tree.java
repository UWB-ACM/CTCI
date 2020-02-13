import java.util.ArrayList;

class Codec {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {

        if (root == null) {
            return "null,";
        }

        // Pre-order traversal of the tree will serialize
        // the tree easily. Pre-order traversing visits
        // current node, then left, then right.
        //
        // Traversing in this way uses the fact that recursive
        // calls keep the state of each call and this allows us
        // to keep track of where we are in the tree.
        String s = root.val + ",";
        s += serialize(root.left);
        s += serialize(root.right);
        return s;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        // First thing we can do to make things easy is to
        // turn the string into a list of Integers. A list
        // is useful becuase we can remove elements from it
        // as we process them.
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (String s : data.split(",")) {
            list.add(s.equals("null") ? null : Integer.parseInt(s));
        }

        // Now call the real deserialize logic:
        return deserialize(list);
    }

    private TreeNode deserialize(ArrayList<Integer> list) {
        // Read and remove the first element of the list
        Integer value = list.get(0);
        list.remove(0);

        // If the element is null, lets return null
        if (value == null) {
            return null;
        }

        // If not, let's create the node and recursively
        // deserialize the REMAINING (remember we already
        // sliced the list) elements of the list.
        TreeNode node = new TreeNode(value);
        node.left = deserialize(list);
        node.right = deserialize(list);
        return node;
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Main {
    public static void main(String ... args) {
        // Create a simple tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.right.left = new TreeNode(4);
        root.right.right = new TreeNode(5);

        Codec codec = new Codec();

        // Serialize and print:
        System.out.println(codec.serialize(root));

        // It's hard to validate that it did the right thing visually,
        // so we are going to serialize -> deserialize -> serialize
        // and the start and end strings should be identical:
        System.out.println(codec.serialize(codec.deserialize(codec.serialize(root))));
    }
}

