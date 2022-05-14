#include <bits/stdc++.h>
using namespace std;
// Structure of Binary Tree
class node
{
public:
    int data;
    node *left;
    node *right;
};
// Prototype Functions
int height(node *root);
void printCurrentLevel(node *root, int data);

// Function to print Level Order Traversal
void printLevelOrder(node *root)
{
    int h = height(root);
    int i;
    for (int i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
// Function to print Current Level
void printCurrentLevel(node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
// Function for finding Height of Binary Tree
int height(node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        // Calculate Height for Left and Right Subtree
        int lheight = height(root->left);
        int rheight = height(root->right);
        // Height : Maximum of Left and Right Subtree
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
// Helper Function that allocate New Node with NULL Left and Right Pointer
node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

int main()
{
    // Creating Binary Tree
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "Level Order Traversal for Binary Tree is:\n";
    printLevelOrder(root);

    return 0;
}