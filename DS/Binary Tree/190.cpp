#include <bits/stdc++.h>
using namespace std;
// Check if binary tree is height balanced
class node
{
public:
    int data;
    node *left, *right;
};
// Prototype Function for Finding Height
int height(node *root);

// Function for finding if Binary tree is Balanced or Not
bool isBalanced(node *root)
{
    int lh; // Height of Left Subtree
    int rh; // Height of Right Subtree
    // Null Tree is always balanced
    if (root == NULL)
        return true;

    // Get Height of Left and Right Subtrees
    lh = height(root->left);
    rh = height(root->right);
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;

    // if we reach here than tree is not height Balanced
    return false;
}

// Function for finding Height of Binary Tree
int height(node *root)
{
    if (root == NULL)
        return 0;

    // If tree is not empty , then it is 1+max of left , right height
    return 1 + max(height(root->left), height(root->right));
}

// Helper Function for allocating new Node
node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);

    if (isBalanced(root))
        cout << "Tree is Balanced.\n";
    else
        cout << "Tree is Not Balanced.\n";

    return 0;
}