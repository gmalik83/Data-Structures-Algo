#include <bits/stdc++.h>
using namespace std;
// Transform tree to Binary Tree
class node
{
public:
    char data;
    node *left;
    node *right;
};

// Prototype for Utility Functions
int search(char arr[], int strt, int end, char value);
node *newNode(char data);

// Inorder : ROot in between Before Root: Left SUbtree After Root : Right Subtree
// Pre Order : Root in Front
node *buildTree(char in[], char pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;
    if (inStrt > inEnd)
        return NULL;
    // pick current node from preIndex;
    node *tNode = newNode(pre[preIndex++]);
    // If this Node has no children then return
    if (inStrt == inEnd)
        return tNode;

    // Find index of this node in InOrder Traversal
    int inIndex = search(in, inStrt, inEnd, tNode->data);

    // Using Index in Inorder , Build Left and Right Subtrees
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}
// Function to Find Index of Value in arr
// Value have to present in this array
int search(char arr[], int strt, int end, char value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
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
node *newNode(char data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Optimization : Use Map so that search can be done in O(1) time

int main()
{
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int n = 6;

    node *root = buildTree(in, pre, 0, n - 1);

    // Check BuildTree , if it is equal to in array
    cout << "Inorder Traversal of Constructed Binary Tree:";
    inOrder(root);

    return 0;
}