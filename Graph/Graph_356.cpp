#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    map<int, list<pair<int, int>>> adjList;
    // Bidirect = 1 means Graph is undirected
    void addEdge(int u, int v, int dist, bool bidirec = 1)
    {
        adjList[u].push_back(make_pair(v, dist));
        // If Graph is Undirected then push other edge also
        if (bidirec == 1)
        {
            adjList[v].push_back(make_pair(u, dist));
        }
    }
    void print_adj()
    {
        for (auto n : adjList)
        {
            cout << n.first << ":";
            for (auto a : n.second)
            {
                cout << "(" << a.first << "," << a.second << ")";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph g;
    // Last Parameter in Add Edge 0 - means Directed Graph 1- means Undirected Graph
    g.addEdge(0, 1, 4, 0);
    g.addEdge(0, 7, 8, 0);
    g.addEdge(1, 7, 11, 0);
    g.addEdge(1, 2, 8, 0);
    g.addEdge(7, 8, 7, 0);
    g.addEdge(2, 8, 2, 0);
    g.addEdge(8, 6, 6, 0);
    g.addEdge(2, 5, 4, 0);
    g.addEdge(6, 5, 2, 0);
    g.addEdge(2, 3, 7, 0);
    g.addEdge(3, 3, 14, 0);
    g.addEdge(3, 4, 9, 0);
    g.addEdge(5, 4, 10, 0);
    g.addEdge(7, 6, 1, 0);
    g.print_adj();
    return 0;
}