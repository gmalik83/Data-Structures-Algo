#include <bits/stdc++.h>
using namespace std;
// LRU Cache

class LRUCache
{
    // Store Keys of Cache
    list<int> dq;
    // Store References of Keys in Cache
    unordered_map<int, list<int>::iterator> ma;
    int csize; // Maximum Size of Cache

public:
    LRUCache(int);
    void refer(int);
    void display();
};
// Declare the Size of Cache
LRUCache::LRUCache(int n)
{
    csize = n;
}
// Refers key x with in the LRU Cache
void LRUCache::refer(int x)
{
    // Not Present in Cache
    if (ma.find(x) == ma.end())
    {
        // Cache is Full
        if (dq.size() == csize)
        {
            // Delete Least Recently Used :=> Back of the Cache
            int last = dq.back();
            dq.pop_back();
            // Erase the last
            ma.erase(last);
        }
    }
    // Present in Cache
    else
        dq.erase(ma[x]);

    // Update Reference
    dq.push_front(x);
    ma[x] = dq.begin();
}
// Function to display Content of Cache
void LRUCache::display()
{
    // Iterate Dequeue and Print All Elements in it
    for (auto it = dq.begin(); it != dq.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
}

int main()
{
    LRUCache ca(4);
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();

    return 0;
}