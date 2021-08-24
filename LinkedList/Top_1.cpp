// Print Middle element of Linked List
#include <bits/stdc++.h>
using namespace std;
typedef struct ListNode
{
    int data;
    struct ListNode *next;

} ListNode;
/*
    Three Case of LL insertion
    1. Beginning 
    2.At the end
    3.In between
                            */
// Head Can be a single or double pointer
ListNode *insert(ListNode *head, int data, int position)
{

    int k = 1;
    ListNode *p, *q, *newNode;
    newNode = (ListNode *)malloc(sizeof(ListNode));

    if (!newNode)
    {
        cout << "Memory Error";
        return NULL;
    }
    newNode->data = data;
    p = head;
    // Insert at beginning
    if (position == 1)
    {
        newNode->next = p;
        head = newNode;
    }
    else
    {
        // Traverse the list until the position where we want to insert
        while ((p != NULL) && (k < position))
        {
            k++;
            q = p;
            p = p->next;
        }
        q->next = newNode;
        newNode->next = p;
    }
    return head;
}
// Insert Single Node in Linked List
void insertSingle(ListNode **head_ref, int new_data)
{
    /* 1. allocate node */
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));

    ListNode *last = *head_ref; /* used in step 5*/

    /* 2. put in the data  */
    new_node->data = new_data;

    /* 3. This new node is going to be the last node, so make next of
          it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

//Delete Node From Linked List
/*
    1. Delete Head Node
    2. Delete Tail Node
    3. Delete Intermediate Node in LL*/
void DeleteNode(ListNode **head, int position)
{
    int k = 1;
    ListNode *p, *q;
    if (*head == NULL)
    {
        cout << "List Empty" << endl;
        return;
    }
    p = *head;
    // Head Node
    if (position == 1)
    {
        *head = (*head)->next;
        free(p);
        return;
    }
    else
    {
        while ((p != NULL) && (k < position))
        {
            k++;
            q = p;
            p = p->next;
        }
        if (p == NULL)
            cout << "Position Does not exist\n";
        else
        {
            q->next = p->next;
            free(p);
        }
    }
}
//Print Middle of Linked List
/*
    Approaches:
    1.Find Total Length and then traverse till middle element
    2.Use Slow and Fast Pointer
    3.Increment count only when it is odd*/
void printMiddle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    if (head == NULL)
    {
        cout << "List is Empty.\n";
    }
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle Element is:" << slow->data;
}
int main()
{
    ListNode *head = NULL;
    insertSingle(&head, 1);
    insertSingle(&head, 2);
    insertSingle(&head, 3);
    insertSingle(&head, 4);
    // insertSingle(&head, 5);
    printMiddle(head);
    return 0;
}