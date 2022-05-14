#include <bits/stdc++.h>
using namespace std;
// Inorder Traversal of Binary Tree
// Data Structure to Store Binary Tree Node
struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
// Recursive Function for Inorder Traversal
void inorder(Node *root)
{
    // If Current pointer is empty
    if (root == NULL)
        return;
    // Traverse Left Subtree
    inorder(root->left);
    // Display Current Data of Root
    cout << root->data << " ";
    // Traverse the right Subtree
    inorder(root->right);
}

// Iterative Inorder Traversal
void inorderIterative(Node *root)
{
    // create an empty stack
    stack<Node *> stack;
    // Start from current node
    Node *curr = root;
    // If current node is null or stack is  empty
    while (!stack.empty() || curr != NULL)
    {
        // If current is not null , push into stack
        if (curr != NULL)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";

            curr = curr->right;
        }
    }
}
int main()
{
    // Contruct Binary Tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    inorder(root);
    cout << endl;
    inorderIterative(root);

    return 0;
}