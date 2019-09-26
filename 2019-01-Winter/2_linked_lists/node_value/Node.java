public class Node {

    public int data;
    public Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }

    // no meaningful bounds checking for array size
    // constructor assumes that arr.length >= 1
    // this is a terrible constructor btw
    public Node(int[] arr) {
        this.data = arr[0];
        Node curr = null;
        Node prev = null;
        for (int i = 1; i < arr.length; i++) {
            curr = new Node(arr[i]);
            if (i == 1) this.next = curr;
            else prev.next = curr;
            prev = curr;
        }
    }

}
