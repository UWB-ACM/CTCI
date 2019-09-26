public class GetValue {

    public static int getValueIterative(Node head, int target) {
        Node result = head;
        for (int i = 0; head != null; i++) {
            head = head.next;
            // preserve the interval between head and result
            if (i >= target) result = result.next;
        }
        return result.data;
    }

    public static void print(Node head) {
        if (head == null) return;
        System.out.print(head.data + " ");
        print(head.next);
    }

    public static void main(String[] args) {
        int[] arr = { 3, 18, 4, 9, 12, -6, 2 };
        Node head = new Node(arr);
        System.out.print("Original array: ");
        print(head);
        System.out.println("\nk = 3:  " + getValueIterative(head, 3));
        System.out.println("k = 20: " + getValueIterative(head, 20));
    }

}
