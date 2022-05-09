#include <iostream>
using namespace std;

struct stack
{
    int data;
    struct stack *next;
};
// Utility Function to initialize stack
void initStack(struct stack **s) { *s = NULL; }
// To Check if Stack is Empty
int isEmpty(struct stack *s)
{
    if (s == NULL)
        return 1;

    return 0;
}
// Push item to stack
void push(struct stack **s, int x)
{
    struct stack *p = (struct stack *)malloc(sizeof(*p));
    if (p == NULL)
    {
        cout << "Memory Allocation Failed" << endl;
        return;
    }
    p->data = x;
    p->next = *s;
    *s = p;
}
// Pop Item from Stack
int pop(struct stack **s)
{
    int x;
    struct stack *temp;
    x = (*s)->data;
    temp = *s;
    (*s) = (*s)->next;
    free(temp);

    return x;
}
// Top of Stack
int top(struct stack *s) { return (s->data); }
// Recursive Function to Insert Item in Sorted Way
void sortedInsert(struct stack **s, int x)
{
    if (isEmpty(*s) || x > top(*s))
    {
        push(s, x);
        return;
    }
    // If Top is Greater , Remove the top item and Recur
    int temp = pop(s);
    sortedInsert(s, x);
    // Put Back the top item removed earlier
    push(s, temp);
}
// Function to sort Stack
void sortStack(struct stack **s)
{
    // If Stack is not empty
    if (!isEmpty(*s))
    {
        // Remove the top Item
        int x = pop(s);
        // Sort Remaining Stack
        sortStack(s);
        // Push the top item back in sorted Stack
        sortedInsert(s, x);
    }
}
// Print Contents of Stack
void printStack(struct stack *s)
{
    while (s)
    {
        cout << s->data << " ";
        s = s->next;
    }
    cout << "\n";
}

int main()
{
    struct stack *top;
    initStack(&top);
    push(&top, 30);
    push(&top, -5);
    push(&top, 18);
    push(&top, 14);
    push(&top, -3);

    cout << "Stack elements before sorting:\n";
    printStack(top);

    sortStack(&top);
    cout << "\n";

    cout << "Stack elements after sorting:\n";
    printStack(top);

    return 0;
}