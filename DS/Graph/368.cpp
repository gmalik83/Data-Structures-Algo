#include <bits/stdc++.h>
using namespace std;
// Topological Sort

class Graph
{
    int V;
    list<int> *adj;
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    // Mark Current Node as Visited
    visited[v] = true;
    // Recur for all Vertices Adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
    }
    Stack.push(v);
}

void Graph::topologicalSort()
{
    stack<int> Stack;
    // Mark ALl Nodes as Not Visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call Helper Function to Store Topological Sort One by One
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
    }
    // Print Contents of Stack
    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is the topological sort of the Graph: ";

    g.topologicalSort();
    cout << endl;

    return 0;
}