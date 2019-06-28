public class ReversePrint {

    public static void reverse(Node head) {
        if (head == null) return;
        reverse(head.next);
        System.out.println(head.data);
    }

    public static void print(Node head) {
        if (head == null) return;
        System.out.println(head.data);
        print(head.next);
    }

    public static void main(String[] args) {
        int[] arr = { 4, 13, 12, -3, 4, 8, 9, 17, 0, 3 };
        Node head = new Node(arr);
        System.out.println("Original array:");
        print(head);
        System.out.println("Reversed array:");
        reverse(head);
    }

}
