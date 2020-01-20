/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package linked_list_duplicates;

/**
 *
 * @author ryan
 */
public class LinkedListNode {
    private int Value;
    private LinkedListNode Next;
    
    LinkedListNode(int Value, LinkedListNode Next) {
        this.Value = Value;
        this.Next = Next;
    }
    
    LinkedListNode() {
        this.Value = 0;
        this.Next = null;
    }
    
    void SetNext(LinkedListNode N) {
        this.Next = N;
    }
    
    LinkedListNode GetNext() {
        return this.Next;
    }
    
    void SetValue(int V) {
        this.Value = V;
    }
    
    int GetValue() {
        return this.Value;
    }
    
}
