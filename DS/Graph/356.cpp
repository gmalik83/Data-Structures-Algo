#include <bits/stdc++.h>
using namespace std;

// Utility Function to Add Edge in Undirected Graph
void addEdge(vector<int> adj[], int u, int v)
{
    // Undirected => Add from both sides
    adj[u].push_back(v);
    adj[v].push_back(u);
}
// function to print Graph
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; v++)
    {
        cout << "Adjacency List of Vertex " << v << "\nhead ";
        for (auto x : adj[v])
        {
            cout << "->" << x;
        }
        cout << endl;
    }
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);

    return 0;
}