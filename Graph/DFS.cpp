#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    map<int, list<int>> adj;
    map<int, bool> visited;
    void addEdge(int v, int w);
    void DFS(int v);
};
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
void Graph::DFS(int v)
{
    // Mark Current as Visited and print
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (!visited[*i])
        {
            DFS(*i);
        }
    }
}
int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Performing DFS of Graph:\n";
    g.DFS(2);
    return 0;
}