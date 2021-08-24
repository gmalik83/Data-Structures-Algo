// Implement Stack Using Arrays

#include<bits/stdc++.h>
using namespace std;
#define MAX 100
class Stack{
    int top;
    public :
        int a[MAX];
        Stack(){ top = -1;}
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
        bool isFull();
};
bool Stack::push(int x)
{
    if(top>=MAX-1)
    {
        cout<<"Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        cout<<x<<" pushed into stack\n";
        return true;
    }
}
int Stack::pop()
{
    if(top<0) {
        cout<<"Stack Underflow";
        return 0;

    }
    else {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()
{
    if(top<0){
        cout<<"Stack is Empty";
        return 0;
    }
    return a[top];
}
bool Stack::isEmpty()
{
    return (top<0);

}
bool Stack::isFull()
{
    return (top>=MAX-1);
}
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.pop()<<" Popped from Stack\n";
    // Print Elements in Stack
    cout<<"Element Present in Stack:";
    while(!s.isEmpty())
    {
        // Print Top Element
        cout<<s.peek()<<" ";
        // Remove Top Element from Stack
        s.pop();

    }

    return 0;
}