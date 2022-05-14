#include <bits/stdc++.h>
using namespace std;

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;

public:
    twoStacks(int n)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }
    // Method to Push Element to Stack 1
    void push1(int x)
    {
        // If there is atleast 1 empty space for new element
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = x;
        }
        else
        {
            cout << "Stack Overflow" << endl;
            exit(1);
        }
    }
    // Method to Push Element x to stack 2
    void push2(int x)
    {
        if (top1 < top2 - 1)
        {
            top2--;
            arr[top2] = x;
        }
        else
        {
            cout << "Stack Overflow" << endl;
            exit(1);
        }
    }
    // Pop from stack 1
    int pop1()
    {
        if (top1 >= 0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        else
        {
            cout << "Stack UnderFlow" << endl;
            exit(1);
        }
    }
    int pop2()
    {
        if (top2 < size)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        cout << "Stack UnderFlow" << endl;
        exit(1);
    }
};

int main()
{
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is "
         << ts.pop1()<<endl;
    ts.push2(40);
    cout << "\nPopped element from stack2 is "
         << ts.pop2()<<endl;
    return 0;

    return 0;
}