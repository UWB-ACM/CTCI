
class TestDeleteMiddleNode {

    /* Link list Node */
    static class LinkedListNode {
        char data;
        LinkedListNode next;
    }

    // Utility function to create a new node
    static LinkedListNode newNode(char data) {
        LinkedListNode temp = new LinkedListNode();
        temp.data = data;
        temp.next = null;
        return temp;
    }

    // Delete given middle node
    static boolean deleteMiddleNode(LinkedListNode n) {
        if (n == null || n.next == null) {
            return false; // Failure
        }
        LinkedListNode next = n.next;
        n.data = next.data;
        n.next = next.next;
        return true;
    }

    // Utility function to print a linked list
    static void printList(LinkedListNode n) {
        while (n != null) {
            System.out.print(n.data + "->");
            n = n.next;
        }
        System.out.print("Null");
    }

    /* Driver code */
    public static void main(String[] args) {
        /* Start with the empty list */
        LinkedListNode head = newNode('a');
        head.next = newNode('b');
        head.next.next = newNode('c');
        head.next.next.next = newNode('d');
        head.next.next.next.next = newNode('e');
        head.next.next.next.next.next = newNode('f');

        System.out.println("Given Linked List:");
        printList(head);

        LinkedListNode c = head.next.next;
        deleteMiddleNode(c);

        System.out.println("\n\nLinked List after deletion of middle");
        printList(head);

        // Test Null node argument
        LinkedListNode nullNode = null;
        boolean result = deleteMiddleNode(nullNode);
        System.out.println("\n\nResult of Null node passed to delete middle function");
        System.out.println(result);

        // Test last node argument
        LinkedListNode head2 = newNode('a');
        head2.next = newNode('b');
        head2.next.next = newNode('c');
        head2.next.next.next = null;

        LinkedListNode c2 = head2.next.next;
        boolean result2 = deleteMiddleNode(c2);
        System.out.println("\n\nResult of last node passed to delete middle function");
        System.out.println(result);
    }
}