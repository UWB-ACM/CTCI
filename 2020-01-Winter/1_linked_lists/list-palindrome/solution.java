import java.util.*;

/*
A simple solution is to use a stack of list nodes. This mainly involves three steps.
Traverse the given list from head to tail and push every visited node to stack.
Traverse the list again. For every visited node, pop a node from stack and 
compare data of popped node with currently visited node.
If all nodes matched, then return true, else false.
 */

public class solution {
    static boolean isPalindrome(Node head) 
    { 
        Node current = head; 
        boolean ispalin = true; 
        Stack<Integer> stack = new Stack<Integer>(); 

        if(head.next == null){
            return true;
        }
  
        while (current != null) { 
            stack.push(current.data); 
            current = current.next; 
        } 
  
        while (head != null) { 
  
            int i = stack.pop(); 
            if (head.data == i) { 
                ispalin = true; 
            } 
            else { 
                ispalin = false; 
                break; 
            } 
            head = head.next; 
        } 
        return ispalin;
    } 
}