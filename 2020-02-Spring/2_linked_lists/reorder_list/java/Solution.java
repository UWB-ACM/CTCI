// UWM ACM CTCI 
// 05/01/2020 
// Week 3: Linked Lists

// Solution for LeetCode #143 Reorder List
// Compile and run using: javac Solution.java ; java Solution.class

import java.util.ArrayList;

public class Solution {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    // Helper method that inserts a new node at the end of the linked list
    public ListNode insert(ListNode head, int element) {
        if (head == null) {
            return new ListNode(element);
        } else {
            ListNode current = head;
            while (current != null && current.next != null) {
                current = current.next;
            }
            current.next = new ListNode(element);
            return head;
        }
    }

    // Helper method for creating lists for test cases
    public ListNode makeBasicList(ArrayList<Integer> list) {
        ListNode front = null;
        for (Integer value : list) {
            front = insert(front, value);
        }
        return front;
    }

    // Helper method for printing the linked list
    public void printList(ListNode head) {
        ListNode current = head;
        System.out.print("[");
        if (current != null) {
            System.out.print(current.val);
            current = current.next;
        }
        while (current != null) {
            System.out.print(", " + current.val);
            current = current.next;
        }
        System.out.println("]");
    }

    public void reorderList(ListNode head) {
        
        // Find the middle node of the linked list
        ListNode slow = head, fast = head;
        while (fast && fast.next) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Reverse the second half of the linked list
        ListNode previous = null, current = slow, temp;
        while (current) {
            temp = current.next;
            current.next = previous;
            previous = current;
            current = temp;
        }

        // Merge the two linked lists
        ListNode first = head, second = previous;
        while (second.next) {
            temp = first.next;
            first.next = second;
            first = temp;

            temp = second.next;
            second.next = first;
            second = temp;
        }
    }

    public static void main(String[] args) {
        ArrayList<Integer> list1 = new ArrayList<>({1, 2, 3, 4});
        ListNode testCase1 = makeBasicList(list1);
        System.out.print("Before: ");
        printList(testCase1);
        reorderList(testCase1);
        
        System.out.print("After: ");
        printList(testCase1);

        ArrayList<Integer> list2 = new ArrayList<>({1, 2, 3, 4, 5});
        ListNode testCase2 = makeBasicList(list2);
        System.out.print("Before: ");
        printList(testCase2);
        reorderList(testCase2);
        
        System.out.print("After: ");
        printList(testCase2);
    }
}