#include<bits/stdc++.h>
using namespace std;

// Structure of Double Linked List Node
typedef struct Node{
    int data ;
    Node* next;
    Node* prev;
}Node;
// Insert Node in Double Linked List

void DLLInsert(Node**head,int data,int position)
{
    int k=1;
    Node*temp , *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    if(!newNode)
    {
        cout<<"Memory Error\n";
        return;
    }
    newNode->data = data;
    if(position==1){
        newNode->next = * head;
        newNode->prev = NULL;
        if(*head)
        (*head)->prev = newNode;

        return;
    }
    temp = *head;
    while((k<position-1)&&temp->next!=NULL){
        temp = temp->next;
        k++;
    }
    if(k!=position)
    {
        cout<<"Position does not exist.\n";
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next)
        temp->next = newNode;
    temp->next = newNode;
    return;
}
// DELETE Node from Double LL
void DLLDelete(Node**head,int position){
    Node*temp=*head ,*temp2;;
    int k=1;
    if(*head==NULL)
    {
        cout<<"List is Empty\n";
        return;
    }
    if(position==1){
        *head = (*head)->next;
        if(*head!=NULL)
        (*head)->prev = NULL;
        free(temp);
        return;
    }
    while((k<position)&&temp->next!=NULL){
        temp = temp->next;
        k++;
    }
    if(k!=position-1)
    {
        cout<<"Desired Position does not exist\n";

    }
    temp2 = temp2->prev;
    temp2->next = temp->next;
    if(temp->next)
        temp->next->prev = temp2;
    free(temp);
    return;
}
// Print Doubly Linked List
void printDLL(Node*head)
{
    Node*current = head;
    if(head==NULL){
        cout<<"List is Empty\n";
        return;
    }
    cout<<"Nodes in Doubly Linked List are:\n";
    while(current!=NULL)
    {
        cout<<current->data<<" ";
        current = current->next;
    }
}
int main()
{
    Node* head;
    head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;
    head->prev = NULL;
    DLLInsert(&head,1,1);
    DLLInsert(&head,2,2);
    DLLInsert(&head,3,3);
    printDLL(head);
    return 0;
}
