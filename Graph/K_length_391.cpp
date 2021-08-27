#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

class Graph
{
    int V; // Number of Vertices
    list<pair<int, int>> *adj;
    bool pathMoreThanKUtil(int src, int k, vector<bool> &path);

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    bool pathMoreThanK(int src, int k);
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair>[V];
}
void Graph::addEdge(int u, int v, int w)
{
    // As Graph is Undirected
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
bool Graph::pathMoreThanK(int src, int k)
{
    vector<bool> path(V, false);
    path[src] = 1;

    return pathMoreThanKUtil(src, k, path);
}
// Utility Function for PathMoreThanK
bool Graph::pathMoreThanKUtil(int src, int k, vector<bool> &path)
{
    if (k <= 0)
        return true;
    // Get all adjacent vertices of Source src and explore all
    list<iPair>::iterator i;
    for (i = adj[src].begin(); i != adj[src].end(); i++)
    {
        int v = (*i).first;
        int w = (*i).second;

        // If Vertex is already there , We Ignore as it cause Cycle
        if (path[v] == true)
            continue;
        if (w >= k)
            return true;
        path[v] = true;

        if (pathMoreThanKUtil(v, k - w, path))
            return true;

        path[v] = false;
    }
    // End Condition

    return false;
}

int main()
{
    int V = 9;
    Graph g(V);
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    int src = 0;
    int k = 62;
    g.pathMoreThanK(src, k) ? cout << "Yes.Path Exist\n" : cout << "No. Path Does not Exist\n";

    k = 60;
    g.pathMoreThanK(src, k) ? cout << "Yes.Path Exist\n" : cout << "No. Path Does not Exist.\n";

      return 0;
}