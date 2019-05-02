#include <iostream>
using namespace std;
struct ListNode
{
public:
    int data;
    ListNode* next;
};

/* Reverses the linked list in groups
of size k and returns the pointer
to the new head node. */
ListNode *reverse (ListNode *head, int k)
{
    ListNode* current = head;
    ListNode* next = NULL;
    ListNode* prev = NULL;
    int count = 0;

    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */
    if (next != NULL)
        head->next = reverse(next, k);

    /* prev is new head of the input list */
    return prev;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(ListNode** head_ref, int new_data)
{
    /* allocate node */
    ListNode* new_node = new ListNode();

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Function to print linked list */
void printList(ListNode *node)
{
    while (node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
}

/* Driver code*/
int main()
{
    /* Start with the empty list */
    ListNode* head = NULL;

    push(&head, 19);
    push(&head, 18);
    push(&head, 17);
    push(&head, 16);
    push(&head, 15);
    push(&head, 13);
    push(&head, 12);
    push(&head, 11);
    push(&head, 10);
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);


    cout<<"Given linked list \n";
    printList(head);
    head = reverse(head, 5);

    cout<<"\nReversed Linked list in groups of given size\n";
    printList(head);
    return(0);
}
