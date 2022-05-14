#include<bits/stdc++.h>
using namespace std;

// Implement Dynamic Stack Using Linked List
class StackNode{
    public:
    int data;
    StackNode *next;

};
StackNode* newNode(int data)
{
    StackNode* stacknode = new StackNode();
    stacknode->data = data;
    stacknode->next = NULL;
    return stacknode;
}
int isEmpty(StackNode* root)
{
    return !root;
}
void push(StackNode**root , int data)
{
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    cout<<data<<" pushed to stack\n";

}
int pop(StackNode**root)
{
    if(isEmpty(*root))
    return INT_MIN;
    StackNode*temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}
int peek(StackNode*root)
{
    if(isEmpty(root))
    return INT_MIN;
    return root->data;
}
int main()
{
    StackNode *root= NULL;
    push(&root,10);
    push(&root,20);
    push(&root,30);

    cout<<pop(&root)<<" popped from stack\n";

    cout<<"Top Element is "<<peek(root)<<endl;
    cout<<"Elements present in stack: ";
    while(!isEmpty(root))
    {
        cout<<peek(root)<<" ";
        pop(&root);
    }
    return 0;
}