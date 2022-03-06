#include <bits/stdc++.h>
using namespace std;

// Reverse Linked List with group size K

// Linked List Node
class Node
{
public:
    int data;
    Node *next;
};
// Reverse the Linked List in size of K and return new Head
Node *reverse(Node *head, int k)
{
    if (!head)
        return NULL;
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;
    int count = 0;
    // Reverse First K nodes of Linked List
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = reverse(next, k);
    }
    // Prev is the new head of Linked List
    return prev;
}

// Function to Push a Node
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    // Put data in New Node
    new_node->data = new_data;
    // Link the list
    new_node->next = (*head_ref);
    // Move head to point to new Node
    (*head_ref) = new_node;
}
// Function to Print Linked List
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    // Start with empty list
    Node *head = NULL;
    // Create Linked List 1->2->3->4->5->6->7->8->9
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    // Given Linked List
    cout << "Given Linked List: ";
    printList(head);
    head = reverse(head, 3);
    cout << "\nReversed Linked List: ";
    printList(head);

    return 0;
}