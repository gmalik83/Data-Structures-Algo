#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;          // Number of Vertices
    list<int> *adj; // Pointer to an Array
    bool isCyclicUtil(int v, bool visited[], bool *rs);

public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if (visited[v] == false)
    {
        // Mark Visited and Part Of Recursion
        visited[v] = true;
        recStack[v] = true;

        // Recur for all Adjacent Vertices
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
                return true;
            else if (recStack[*i])
            {
                return true;
            }
        }
    }
    recStack[v] = false;
    return false;
}
bool Graph::isCyclic()
{
    // Mark all vertices as not Visited and not part of stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    // Call Recursive Helper Function
    for (int i = 0; i < V; i++)
        if (!visited[i] && isCyclicUtil(i, visited, recStack))
            return true;
    return false;
}
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if (g.isCyclic())
    {
        cout << "Graph Contains Cycle\n";
    }
    else
    {
        cout << "Graph Does not Contain Cycle\n";
    }

    return 0;
}