package linked_list_duplicates;

import java.util.HashSet;
import java.util.LinkedList;

/**
 *
 * @author ryan
 */
public class Linked_List_Duplicates {

    public static LinkedListNode RemoveDuplicatesWithBuffer(LinkedListNode Start) {
        if (Start == null || Start.GetNext() == null) {
            return Start;
        }

        HashSet<Integer> set = new HashSet<>();

        LinkedListNode Curr = Start;
        LinkedListNode Prev = Curr;

        while (Curr != null) {
            if (set.contains(Curr.GetValue())) {

                Prev.SetNext(Curr.GetNext());
                Curr = Curr.GetNext();

            } else {

                set.add(Curr.GetValue());
                Prev = Curr;
                Curr = Curr.GetNext();

            }
        }
        return Start;
    }

    //ToDo: This
    public static LinkedListNode RemoveDuplicatesWithoutBuffer(LinkedListNode Start) {
        if (Start == null || Start.GetNext() == null) {
            return Start;
        }

        LinkedListNode Curr = Start;
        LinkedListNode Prev = Start;
        LinkedListNode Check = Start;

        while (Curr != null) {
            
            boolean duplicate = false;
            
            Check = Start;
            
            while (Check != null && !duplicate) {
                if (Check.GetValue() == Curr.GetValue()) {
                    duplicate = true;
                } else {
                    Check = Check.GetNext();
                }
            }
            
            //Remove the node
            if (duplicate) {
                Prev.SetNext(Curr.GetNext());
            }
            
            Prev = Curr;
            Curr = Curr.GetNext();
        }
        
        return Start;

    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Test1();
        Test2();
        Test3();
        Test4();

    }

    public static void Test1Buffer() {
        System.out.println("Test 1");

        LinkedListNode Head = new LinkedListNode(5, null);
        LinkedListNode Prev = Head;

        for (int i = 0; i < 3; i++) {
            LinkedListNode T = new LinkedListNode(1, null);
            Prev.SetNext(T);
            Prev = Prev.GetNext();
        }
        for (int i = 0; i < 30; i++) {
            LinkedListNode T = new LinkedListNode(i, null);
            Prev.SetNext(T);
            Prev = Prev.GetNext();
        }
        for (int i = 30; i < 00; i++) {
            LinkedListNode T = new LinkedListNode(i, null);
            Prev.SetNext(T);
            Prev = Prev.GetNext();
        }

//        RemoveDuplicatesWithBuffer(Head);
        RemoveDuplicatesWithoutBuffer(Head);

        while (Head != null) {
            System.out.println("Node: " + Head.GetValue());
            Head = Head.GetNext();
        }
    }

    public static void Test2Buffer() {
        System.out.println("Test 2");

        LinkedListNode Head = new LinkedListNode(1, null);
        LinkedListNode Prev = Head;

        for (int i = 0; i < 30; i++) {
            LinkedListNode T = new LinkedListNode(1, null);
            Prev.SetNext(T);
            Prev = Prev.GetNext();
        }

//        RemoveDuplicatesWithBuffer(Head);
        RemoveDuplicatesWithoutBuffer(Head);

        while (Head != null) {
            System.out.println("Node: " + Head.GetValue());
            Head = Head.GetNext();
        }
    }

    public static void Test3Buffer() {
        System.out.println("Test 3");

        LinkedListNode Head = new LinkedListNode(1, null);
        LinkedListNode Prev = Head;

//        RemoveDuplicatesWithBuffer(Head);
        RemoveDuplicatesWithoutBuffer(Head);

        while (Head != null) {
            System.out.println("Node: " + Head.GetValue());
            Head = Head.GetNext();
        }
    }

    public static void Test4() {
        System.out.println("Test 4");

//        RemoveDuplicatesWithBuffer(null);
        RemoveDuplicatesWithoutBuffer(null);

    }

}
