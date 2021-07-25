#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    
};
// Function Prototypes
void printGivenLevel(Node*root,int level);
int height(Node*node);
Node* newNode(int data);
// Function to Print Reverse Level Order Traversal a tree
void reverseLevelOrder(Node *root)
{
    int h = height(root);
    int i;
    for(int i=h;i>=1;i--)
        printGivenLevel(root,i);

}
void printGivenLevel(Node * root,int level)
{
    if(root==NULL)
        return ;
    if(level==1)
        cout<<root->data<<" ";
    else if(level>1)
    {
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
}
int height(Node *node)
{
    if(node==NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if(lheight>rheight)
            return lheight+1;
        else return rheight+1;
    }
}
Node* newNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main()
{   
            /*
            1
          /   \
          2     3
         /  \
        4    5
            */
    Node *root = newNode(1);
    root ->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout<<"Reverse Level Order Traversal Of Binary Tree is :\n";
    reverseLevelOrder(root);
    return 0;
}