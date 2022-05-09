#include <bits/stdc++.h>
using namespace std;

// BFS Traversal for Vertices Reachable from S

class Graph
{
    int V; // Number of Vertices
    // Pointer to an Array Containing Adjacency List
    vector<list<int>> adj;

public:
    Graph(int V); // Constructor
    // Add Edge to Graph
    void addEdge(int v, int w);
    // Print BFS from given source
    void BFS(int s);
};
Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::BFS(int s)
{
    // Mark All Vertices as Not Visited
    vector<bool> visited;
    visited.resize(V, false);

    // Queue for BFS
    list<int> queue;

    // Mark Current as Visited and Enqueue it
    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty())
    {
        // Dequeue a Vertex and Print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all Adjacent Vertices of Dequeued vertex S
        for (auto adjacent : adj[s])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

int main()
{
    // Graph with 4 vertices
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal (2 as Source): ";
    g.BFS(2);
    cout << endl;

    return 0;
}