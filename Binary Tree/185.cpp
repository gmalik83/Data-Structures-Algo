#include <bits/stdc++.h>
using namespace std;
// Left View of Binary Tree
struct Node
{
    int data;
    struct Node *left, *right;
};
// Function to create new binary tree Node
struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
// Recursive function to print Left View
void leftViewUtil(struct Node *root, int level, int *max_level)
{
    // Base case
    if (root == NULL)
        return;
    // If Node is First for this level
    if (*max_level < level)
    {
        cout << root->data << " ";
        *max_level = level;
    }
    // Recur for left Subtree first
    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
}

// Wrapper Function over leftViewUtil()
void leftView(struct Node *root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}
// Print Left View Using Queue
void printLeftView(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        // Number of Nodes at current level
        int n = q.size();

        // Traverse All Nodes at Current Level
        for (int i = 1; i <= n; i++)
        {
            Node *temp = q.front();
            q.pop();
            // Print Leftmost element at the level
            if (i == 1)
            {
                cout << temp->data << " ";
            }
            // Add Left Node to Queue
            if (temp->left != NULL)
                q.push(temp->left);
            // Add Right to queue
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}
int main()
{
    Node *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);

    leftView(root);
    cout << endl;
    cout << "Printing Left View Using Queue:\n";
    printLeftView(root);

    return 0;
}