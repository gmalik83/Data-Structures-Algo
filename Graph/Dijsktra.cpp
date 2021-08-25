#include <bits/stdc++.h>
using namespace std;

#define V 9

int minDistance(int dist[], bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}
void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << " \t\t" << dist[i] << endl;
    }
}
void dijkstra(int graph[V][V], int src)
{
    int dis[V];
    bool splSet[V];
    // Initialise all distance as INT_MAX and splSet as False
    for (int i = 0; i < V; i++)
    {
        dis[i] = INT_MAX, splSet[i] = false;
    }
    // Mark Distance of Source as 0
    dis[src] = 0;
    // Find Shortest Path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dis, splSet);
        splSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!splSet[v] && graph[u][v] && dis[u] != INT_MAX && dis[u] + graph[u][v] < dis[v])
                dis[v] = dis[u] + graph[u][v];
        }
    }
    printSolution(dis);
}
int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}