/**
 * Linked List 
 * 
 * A class to represent a multilevel doubly linked list.
 * this class has functions toString and helper methods
 * createListOne, and createListTwo to create specific examples
 * for the flatten function.
 * @author jquigtar
 *
 */
public class LinkedList {
	private int levels;
	private Node head;

	private class Node {
		public int data;
		public Node prev;
		public Node next;
		public Node child;
		Node(int data) { 
            this.data = data;
            prev = null;
            next = null;
    		child = null; 
        } 
	};

	public String toString() {
		String s = "";
		Node current = this.head;
		while(current != null) {
			if(current.next != null) {
				s = s + current.data + ", ";
			}else {
				s = s + current.data + "";
			}
			current = current.next;
		}
		s= s + "\n";
		
		return s;
	}

	/**
	 * createList
	 * 
	 * this function creates a linked list of the int array passed into the
	 * parameter and returns the head of the linked list as a node
	 * @param arr
	 * @param n
	 * @return
	 */
	Node createList(int arr[], int n) { 
		Node node = null; 
		Node p = null; 

		int i; 
		for (i = 0; i < n; ++i) { 
			if (node == null) { 
				node = p = new Node(arr[i]); 
			} else { 
				p.next = new Node(arr[i]); 
				p = p.next; 
			} 
			p.next = p.child = null; 
		} 
		return node; 
	}

	/**
	 * createListOne
	 * 
	 * this function creates the multilevel doubly linked list
	 * 1,2,3,4,5,6
	 *     7,8,9,10
	 *       11,12
	 * to use as an example linked list to test the flatten method
	 * @return
	 */
	Node createListOne() { 
		int arr1[] = new int[]{1, 2, 3, 4, 5, 6}; 
		int arr2[] = new int[]{ 7, 8, 9, 10}; 
		int arr3[] = new int[]{ 11, 12}; 
		

		/* create 3 linked lists */
		Node head1 = createList(arr1, arr1.length); 
		Node head2 = createList(arr2, arr2.length); 
		Node head3 = createList(arr3, arr3.length); 


		/* modify child pointers to create the list shown above */
		head1.child = head2; 
		head1.next.next.next.child = head3; 

		/* Return head pointer of first linked list.  Note that all nodes are 
	         reachable from head1 */
		return head1; 
	} 

	/**
	 * createListTwo
	 * 
	 * this function creates the multilevel doubly linked list
	 * 1,2
	 * 3
	 * to use as an example linked list to test the flatten method
	 */
	Node createListTwo() { 
		int arr1[] = new int[]{1, 2}; 
		int arr2[] = new int[]{3};
		

		/* create 2 linked lists */
		Node head1 = createList(arr1, arr1.length); 
		Node head2 = createList(arr2, arr2.length); 

		/* modify child pointers to create the list shown above */
		head1.child = head2; 

		/* Return head pointer of first linked list.  Note that all nodes are 
	         reachable from head1 */
		return head1; 
	} 

	
	public Node flatten(Node head) {
		/*Base case*/
		if (head == null) { 
			return head; 
		} 

		/* Find tail node of first level linked list */
		Node tail = head; 
		while (tail.next != null) { 
			tail = tail.next; 
		} 

		// One by one traverse through all nodes of first level 
		// linked list till we reach the tail node 
		Node current = head; 
		while (current != tail) { 
			

			// If current node has a child 
			if (current.child != null) { 
				// then link child in between current and current.next
				//store last link on next level as temp to connect to
				//current.next
				Node temp = current.child; 
				while (temp.next != null) { 
					temp = temp.next; 
				} 
				//break and create new links
				temp.next = current.next;
				current.next.prev = temp;
				current.next = current.child; 
				current.child.prev = current;
				current.child = null;
			} 

			// Change current node 
			current = current.next; 
		} 
		return head;
	}
	
	public static void main(String[] args) {
		//create example lists
		LinkedList listOne = new LinkedList();
		LinkedList listTwo = new LinkedList();
		LinkedList emptyList = new LinkedList();
		listOne.head = listOne.createListOne();
		listTwo.head = listTwo.createListTwo();
		
		//print orginal lists
		System.out.println(listOne.toString());
		System.out.println(listTwo.toString());
		
		//flatten and print out new lists
		listOne.head = listOne.flatten(listOne.head);
		System.out.println(listOne.toString());
		
		listTwo.head = listTwo.flatten(listTwo.head);
		System.out.println(listTwo.toString());


	}
}
