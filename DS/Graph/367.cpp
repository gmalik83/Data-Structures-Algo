#include <bits/stdc++.h>
using namespace std;

#define V 9

// Dijsktra Algorithm

void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t" << dist[i] << endl;
}

int minDistance(int dist[], bool splSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (splSet[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[][V], int src)
{
    int dist[V]; // Hold distance from src to i

    bool splSet[V]; // If i is included in Shortest Path Tree
    // Initialize all distances as Infinite and splSet[] as False
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        splSet[i] = false;
    }
    // Distance of Source from Itself is 0
    dist[src] = 0;

    // Find Shortest Path For All Vertices
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, splSet);
        // Mark Vertex as Processed
        splSet[u] = true;

        // Update distance Value of Adjacent Vertices
        for (int v = 0; v < V; v++)
        {
            if (!splSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    printSolution(dist);
}

int main()
{
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
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