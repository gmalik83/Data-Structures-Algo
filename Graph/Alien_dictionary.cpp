#include <bits/stdc++.h>
using namespace std;

// Graph 372 Alien Dictionary
class Graph
{
    int V; // Number of Vertex
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
    adj[v].push_back(w);
}
// Recursive UTil Function for Topological Sort
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    Stack.push(v);
}

void Graph::topologicalSort()
{
    stack<int> Stack;
    // Mark all as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    for (int i = 0; i < V; i++)
        if (!visited[i])
            topologicalSortUtil(i, visited, Stack);
    while (!Stack.empty())
    {
        cout << (char)('a' + Stack.top()) << " ";
        Stack.pop();
    }
}
void printOrder(string words[], int n, int alpha)
{
    Graph g(alpha);
    // Process and Create a Graph
    for (int i = 0; i < n - 1; i++)
    {
        string word1 = words[i], word2 = words[i + 1];
        for (int j = 0; j < min(word1.length(), word2.length()); j++)
            // If mismatch is found , then add Edge form char of word1 to char of word2
            if (word1[j] != word2[j])
            {
                g.addEdge(word1[j] - 'a', word2[j] - 'a');
                break;
            }
    }
    // Print Topological Sort
    g.topologicalSort();
}
int main()
{
    string words[] = {"caa", "aaa", "aab"};
    printOrder(words, 3, 3);
    return 0;
}