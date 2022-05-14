#include <bits/stdc++.h>
using namespace std;
// DFS of Graph

// Graph Class
class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    // Function to Add an Edge to Graph
    void addEdge(int v, int w);
    // DFS Traversal of Vertices Reachable from V
    void DFS(int v);
};
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::DFS(int v)
{
    // Mark Current Node as Visited and Print It
    visited[v] = true;
    cout << v << " ";

    // Recur for all Vertices Adjacent to this Vertex
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

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);

    return 0;
}