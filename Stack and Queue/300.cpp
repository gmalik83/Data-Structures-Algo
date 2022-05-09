#include <bits/stdc++.h>
using namespace std;
// K stacks in a Single Array

class kStacks
{
    int *arr;  // Array of Size N to Store Actual Content of Stack
    int *top;  // Array of size K to store indexes of top element of Stacks
    int *next; // N size to store next entry in all Stacks

    int n, k;
    int free; // Beginning of Free List
public:
    kStacks(int k, int n);
    // Check if Space is Available
    bool isFull() { return (free == -1); }
    // Push item in Stack Number SN where SN is from 0 to K-1
    void push(int item, int sn);
    // To POP item from Stack Number SN
    int pop(int sn);
    // Check if Stack is Empty
    bool isEmpty(int sn) { return (top[sn] == -1); }
};
// Contructor to Create K stacks in array of size N
kStacks::kStacks(int k1, int n1)
{
    // Initialize K and N
    k = k1, n = n1;
    arr = new int[n];
    top = new int[k];
    next = new int[n];
    // Initialize all Spaces as Free
    free = 0;
    for (int i = 0; i < n - 1; i++)
        next[i] = i + 1;
    next[n - 1] = -1; // ENd of List
}
void kStacks::push(int item, int sn)
{
    // Overflow Check
    if (isFull())
    {
        cout << "Stack Overflow\n";
        return;
    }
    int i = free;
    free = next[i];
    // Update next of top and then top for stack number sn
    next[i] = top[sn];
    top[sn] = i;
    // Put item in array
    arr[i] = item;
}
// Pop from stack SN
int kStacks::pop(int sn)
{
    // UnderFlow CHeck
    if (isEmpty(sn))
    {
        cout << "Stack Underflow" << endl;
        return INT_MAX;
    }
    // Find Index of top item in Stack Number SN
    int i = top[sn];
    top[sn] = next[i];
    next[i] = free;
    free = i;
    // return the previous item
    return arr[i];
}

int main()
{
    int k = 3, n = 10;
    kStacks ks(k, n);
    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);

    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

    return 0;
}