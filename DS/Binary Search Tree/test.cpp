#include <bits/stdc++.h>
using namespace std;

class BST
{
    int data;
    BST *left, *right;

public:
    // Default Constructor
    BST();
    // Parameterized Constructor
    BST(int);
    // Insert Function
    BST *Insert(BST *, int);
    // Inorder Traversal
    void Inorder(BST *);
};
// Default Constructor definition
BST ::BST() : data(0), left(NULL), right(NULL)
{
}
// Parameterized Constructor Definition
BST::BST(int value)
{
    data = value;
    left = right = NULL;
}
// Insert Function
BST *BST::Insert(BST *root, int value)
{
    if (!root)
    {
        // Insert First Node , if root is NULL
        return new BST(value);
    }
    // Insert Data
    if (value > root->data)
    {
        // Insert in Right Node and Process Right Node
        root->right = Insert(root->right, value);
    }
    else
    {
        // Process Left Node
        root->left = Insert(root->left, value);
    }
    return root;
}
// InOrder Traversal : Gives Data in Sorted Order
void BST::Inorder(BST *root)
{
    if (!root)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
int main()
{
    BST b, *root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);

    b.Inorder(root);
    return 0;
}
