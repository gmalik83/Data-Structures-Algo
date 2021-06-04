#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data ;
    Node* next;
}Node;
//Counting Nodes in Circular Linked List
int CircularListLength(Node*head)
{
    Node* current = head;
    int count =0;
    if(head==NULL)
    {
        return 0;
    }
    do{
        current = current->next;
        count++;
    }while(current!=head);
    return count;
}
// Printing Circular Linked List 
void PrintingList(Node*head)
{
    Node* current = head;
    if(head==NULL) // List is Empty
    return;
    do {
        cout<<current->data<<" ";
        current = current->next;

    }while(current!=head);
}
// INsert element at Last in Circular Linked List
void InsertAtEnd(Node**head,int data)
{
    Node* current = *head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode)
    {
        cout<<"Memory Error";
        return;

    }
    newNode->data = data;
    while(current->next!=*head)
        current = current->next;
    
    newNode->next = newNode;
    if(*head==NULL)
     *head = newNode;
     else {
         newNode->next = *head;
         current->next = newNode;
     }
}
//Insert First ELement 
void InsertOne(Node**head,int data)
{
    if(*head==NULL)
    {
        Node*temp ;
        temp = (Node*)malloc(sizeof(Node));
        temp->data = data;
        temp->next = NULL;
        *head = temp;
    }
}
// INsert AT Front of Circular Linked List
void InsertAtFront(Node**head,int data)
{
    Node*current = *head;
    Node*newNode = (Node*)malloc(sizeof(Node));
    if(!newNode)
    {
        cout<<"Memory Error";
        return;

    }
    newNode->data = data;
    while(current->next!=*head)
        current = current->next;
    newNode->next = newNode;
    if(*head==NULL)
    *head = newNode;
    else {
        newNode->next = *head;
        current->next = newNode;
        *head = newNode;

    }
    return;
}
// Delete Last Node in Circular LL
void DeleteLastNode(Node**head)
{
    Node*temp = *head,*current = *head;
    if(*head==NULL)
    {
        cout<<"List is Empty\n";
        return;
    }
    while(current->next!=*head){
        temp= current;
        current = current->next;

    }
    temp->next = current->next;
    free(current);
    return;

}
//Delete First Node in Circular Linked List
void DeleteFirstNode(Node**head)
{
    Node*temp=*head,*current=*head;
    if(*head==NULL)
    {
        cout<<"LIst is Empty\n";
        return;
    }
    while(current->next!=*head)
        current = current->next;
    current->next = (*head)->next;
    *head = (*head)->next;
    free(temp);
    return;

}


int main()
{
    Node* head;
    InsertOne(&head,1);
    InsertAtFront(&head,1);
    InsertAtEnd(&head,2);
    InsertAtEnd(&head,3);
    PrintingList(head);

}