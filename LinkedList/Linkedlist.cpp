#include<bits/stdc++.h>
using namespace std;

// Structure of Linked List Node
typedef struct ListNode{
    int data ;
    ListNode* next;
};
/*
    Three Case of LL insertion
    1. Beginning 
    2.At the end
    3.In between
                            */
// Head Can be a single or double pointer
ListNode* insert(ListNode*head,int data,int position)
{
    
        int k=1;
        ListNode*p,*q,*newNode;
        newNode = (ListNode*)malloc(sizeof(ListNode));

        if(!newNode)
        {
            cout<<"Memory Error";
            return NULL;

        }
        newNode->data = data;
        p=head;
        // Insert at beginning 
        if(position == 1)
        {
            newNode->next = p;
            head = newNode;
        }
        else {
            // Traverse the list until the position where we want to insert
            while((p!=NULL)&&(k<position))
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
ListNode* insertSingle(ListNode*head,int data)
{
    ListNode* newNode = head,*p=head;
    if(newNode==NULL)
    {
        newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }
    newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;
    while()

}
// Find Lenght of Linked List and print it
int ListLength(ListNode*head)
{
    ListNode*current = head;
    int count = 0;
    while(current!=NULL){
        count++;
        cout<<current->data<<" ";
        current=current->next;
    }
    return count;
    // TC - O(n)
}

int main()
{
    ListNode* head ;
    

    return 0;
}