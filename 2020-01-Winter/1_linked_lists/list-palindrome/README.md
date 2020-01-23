**Question:**

Given a singly unsorted linked list of size N of integers. 

Your task is to check if the given linked list is palindrome or not.

Input:

A singly usorted linked list of N integers 

1 <= N <= 10

Output:

1 if the linked list is a palindrome, 0 otherwise

```
public class question
{
    // Function to check if linked list is palindrome
    boolean isPalindrome(Node head) 
    {
        //Your code here
    }    
}
```

**Solution:**

A simple solution is to use a stack of list nodes.

This mainly involves three steps:

1.Traverse the given list from head to tail and push every visited node to stack.

2.Traverse the list again. For every visited node, pop a node from stack and 
compare data of popped node with currently visited node.

3.If all nodes matched, then return true, else false.

```
public static boolean isPalindrome(Node head) 
    {
        //Your code here
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
```
 
