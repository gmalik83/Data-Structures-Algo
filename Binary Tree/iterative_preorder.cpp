#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    
};
Node* newNode(int data)
{
    Node *root=new Node();
    root->data = data;
    root->right = NULL;
    root->left = NULL;
    return root;   
}
void preOrderTraversal(Node*root)
{
    stack<Node*> st;
    if(root==NULL)
    {
        cout<<"Cannot Process . Tree is Empty.";
        return;
    }
    st.push(root);
    while(!st.empty())
    {
        Node * temp = st.top();
        st.pop();
        cout<<temp->data<<" ";
        if(temp->right)
        st.push(temp->right);
        if(temp->left)
        st.push(temp->left);
    }
}
int main()
{
     Node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);
    preOrderTraversal(root);
    return 0;
}
