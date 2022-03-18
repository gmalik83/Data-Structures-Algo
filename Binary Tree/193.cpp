#include <bits/stdc++.h>
using namespace std;
// Construct Binary Tree from String Representation
// First is Root Then in First Bracket LEFT Subtree , in Second RIGHT Subtree

// Structure of Binary Tree
struct Node
{
    int data;
    Node *left, *right;
};
// Allocate New Node
Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
// Preorder printing
void preOrder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
// Function to Return index of Close Parenthesis
int findIndex(string str, int si, int ei)
{
    if (si > ei)
        return -1;

    // Stack for Storing Char
    stack<char> s;

    for (int i = si; i <= ei; i++)
    {
        // Open Parenthese , push it
        if (str[i] == '(')
            s.push(str[i]);

        // If Close Paretheses
        else if (str[i] == ')')
        {
            if (s.top() == '(')
            {
                s.pop();
                if (s.empty())
                    return i;
            }
        }
    }
    return -1;
}
// Function to Construct Tree From String
Node *treeFromString(string str, int si, int ei)
{
    // Base Case
    if (si > ei)
        return NULL;
    // New Root of Tree
    Node *root = newNode(str[si] - '0');
    int index = -1;

    // If Next is ( , then Find Index of Closing Bracket
    if (si + 1 <= ei && str[si + 1] == '(')
        index = findIndex(str, si + 1, ei);

    // If Found Index
    if (index != -1)
    {
        // Call for Left Subtree
        root->left = treeFromString(str, si + 2, index - 1);
        // Call for Right Subtree
        root->right = treeFromString(str, index + 2, ei - 1);
    }
    return root;
}
int main()
{
    string str = "4(2(3)(1))(6(5))";
    Node *root = treeFromString(str, 0, str.length() - 1);
    preOrder(root);

    return 0;
}