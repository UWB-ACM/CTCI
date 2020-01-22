import java.util.*;

public class driver{
    public static class Node { 
        int data; 
        Node next; 
        Node(int d) 
        { 
            next = null; 
            data = d; 
        } 
    } //end of inner class Node
    
    public static void main(String args[]){
        Node one = new Node(1); 
        Node two = new Node(2); 
        Node three = new Node(3); 
        Node four = new Node(4); 
        Node five = new Node(3); 
        Node six = new Node(2); 
        Node seven = new Node(1); 
        one.next = two; 
        two.next = three; 
        three.next = four; 
        four.next = five; 
        five.next = six; 
        six.next = seven; 
        boolean condition = isPalindrome(one); 
        System.out.println("isPalidrome :" + condition); 
    } 

    // Function to check if linked list is palindrome
    public static boolean isPalindrome(Node head) 
    {
        //Your code here
    }    
}
