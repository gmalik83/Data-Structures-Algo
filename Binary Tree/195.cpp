#include <bits/stdc++.h>
using namespace std;
// Transform tree to Binary Tree
class node
{
public:
    int data;
    node *left;
    node *right;
};

// Every node Contains Sum of Values of Node in Left and Right Subtrees in the Original Tree
int toSum(node *Node)
{
    // Base Case
    if (Node == NULL)
        return 0;

    // Store the Old Value
    int old_data = Node->data;
    // Recursively call for left and right subtrees and store sum as old value of this node
    Node->data = toSum(Node->left) + toSum(Node->right);
    return Node->data + old_data;
}

// InOrder Binary Traversal
void inOrder(node *Node)
{
    if (Node == NULL)
        return;
    inOrder(Node->left);
    cout << " " << Node->data;
    inOrder(Node->right);
}
// Utility Function to create a new Binary Tree Node
node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main()
{
    node *root = NULL;
    int x;
    // Constructing Tree
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);

    toSum(root);

    // Print Inorder Traversal for New TRee
    cout << "InOrder Traversal of New Tree:";
    inOrder(root);

    return 0;
}