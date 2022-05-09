#include <bits/stdc++.h>
using namespace std;
// Queue Using Two Stacks : Make Enqueue Costly or Deque Costly
struct Queue
{
    stack<int> s1, s2;
    // Enqueue : Push newest item at bottom
    void enQueue(int x)
    {
        // Move All Element from s1 to s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        // Push X at bottom in S1
        s1.push(x);
        // Push Everything Back to S1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    // Dequeue from Queue :-> TOp from Stack 1
    int deQueue()
    {
        // If First Stack is Empty : Queue is Empty
        if (s1.empty())
        {
            cout << "Queue is Empty.\n";
            exit(0);
        }
        // Return top of S1
        int val = s1.top();
        s1.pop();
        return val;
    }
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;

    return 0;
}