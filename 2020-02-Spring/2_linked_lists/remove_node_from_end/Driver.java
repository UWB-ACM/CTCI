public class Driver {

    public static void main (String [] args){
        ListNode head = new ListNode(1); 
        ListNode two = new ListNode(2); 
        ListNode three = new ListNode(3); 
        ListNode four = new ListNode(4); 
        ListNode five = new ListNode(5); 
        ListNode six = new ListNode(6); 
        ListNode seven = new ListNode(7); 
        head.next = two; 
        two.next = three; 
        three.next = four; 
        four.next = five; 
        five.next = six; 
        six.next = seven; 
        removeNthFromEnd(head, 2);
        System.out.println("Result:"); //expected result: 1 -> 2 -> 3 -> 4 -> 5 -> 7
        print(head);
    }

    public static void print(ListNode head){
        ListNode curr = head;
        while(curr != null){
            System.out.print(curr.val + ", ");
            curr = curr.next;
        }
    }

    //Definition for singly-linked list.
    public static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public static ListNode removeNthFromEnd(ListNode head, int n) {
        //REPLACE THIS WITH YOUR OWN SOLUTION 
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode first = dummy;
        ListNode second = dummy;
        // Advances first pointer so that the gap between first and second is n nodes apart
        for (int i = 1; i <= n + 1; i++) {
            first = first.next;
        }
        // Move first to the end, maintaining the gap
        while (first != null) {
            first = first.next;
            second = second.next;
        }
        second.next = second.next.next;
        return dummy.next;
    }
}