#include <bits/stdc++.h>
using namespace std;
vector<unordered_set<int>> make_graph(int n, vector<pair<int, int>> &preReq)
{
    vector<unordered_set<int>> graph(n);
    for (auto pre : preReq)
        graph[pre.second].insert(pre.first);

    return graph;
}
bool dfs_cycle(vector<unordered_set<int>> &graph, int node, vector<bool> &onPath, vector<bool> &visited)
{
    if (visited[node])
        return false;
    onPath[node] = visited[node] = true;
    for (int neigh : graph[node])
        if (onPath[neigh] || dfs_cycle(graph, neigh, onPath, visited))
            return true;
    return onPath[node] = false;
}
int canFinish(int n, vector<pair<int, int>> &preReq)
{
    vector<unordered_set<int>> graph = make_graph(n, preReq);
    vector<bool> onPath(n, false), visited(n, false);
    for (int i = 0; i < n; i++)
        if (!visited[i] && dfs_cycle(graph, i, onPath, visited))
            return false;

    return true;
}
int main()
{
    int numofTasks = 4;
    vector<pair<int, int>> preReq;
    // 1 0 2 1 3 2
    preReq.push_back(make_pair(1, 0));
    preReq.push_back(make_pair(2, 1));
    preReq.push_back(make_pair(3, 2));
    if (canFinish(numofTasks, preReq))
        cout << "Possible to finish all Tasks.\n";
    else
        cout << "Impossible to finish all Tasks.\n";
    return 0;
}