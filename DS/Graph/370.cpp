#include <bits/stdc++.h>
using namespace std;

// Return Adjacency List Representation
vector<unordered_set<int>> make_graph(int numTasks, vector<pair<int, int>> &prereq)
{
    vector<unordered_set<int>> graph(numTasks);
    for (auto pre : prereq)
    {
        graph[pre.second].insert(pre.first);
    }

    return graph;
}

bool dfs_cycle(vector<unordered_set<int>> &graph, int node, vector<bool> &onpath, vector<bool> &visited)
{
    if (visited[node])
        return false;
    onpath[node] = visited[node] = true;
    for (int neigh : graph[node])
        if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
            return true;
    return onpath[node] = false;
}
// To Check Whether Possible to Finish Tasks or not
bool canFinish(int numTasks, vector<pair<int, int>> &prereq)
{
    vector<unordered_set<int>> graph = make_graph(numTasks, prereq);
    vector<bool> onpath(numTasks, false), visited(numTasks, false);
    for (int i = 0; i < numTasks; i++)
    {
        if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
            return false;
    }
    return true;
}

int main()
{
    int numberOfTasks = 4;
    vector<pair<int, int>> prereq;
    prereq.push_back(make_pair(1, 0));
    prereq.push_back(make_pair(2, 1));
    prereq.push_back(make_pair(3, 2));

    if (canFinish(numberOfTasks, prereq))
        cout << "Possible to Finish All Tasks!";
    else
        cout << "Impossible to Finish All Tasks!";
    cout << endl;

    return 0;
}