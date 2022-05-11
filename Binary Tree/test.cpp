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

// Utility Function to Get Sum of Left and Right Tree
int sum(node *root)
{
    if (root == NULL)
        return 0;
    return sum(root->left) + root->data + sum(root->right);
}
// Return True if Sum Property Holds for Given Node and Both its Children
int isSumTree(node *node)
{
    int ls, rs;
    // If NOde is NULL or Its a Leaf Node then Return True
    if (node == NULL || (node->left == NULL && node->right == NULL))
        return 1;

    // Get Sum of Left and Right Subtrees
    ls = sum(node->left);
    rs = sum(node->right);

    if ((node->data == ls + rs) && isSumTree(node->left) && isSumTree(node->right))
        return 1;

    return 0;
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
    node *root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);

    if (isSumTree(root))
        cout << "The given tree is a SumTree ";
    else
        cout << "The given tree is not a SumTree ";
    return 0;
}