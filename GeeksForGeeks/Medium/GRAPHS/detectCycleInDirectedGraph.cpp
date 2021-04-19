
/*
 * Detect cycle in a directed graph - GFG
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int vertex, vector<bool> visited, vector<bool> res, vector<int> adj[])
    {
        visited[vertex] = true;
        res[vertex] = true;

        for (auto i : adj[vertex])
        {
            if ((!visited[i] && dfs(i, visited, res, adj)) || (res[i]))
                return true;
        }
        res[vertex] = false;
        return false;
    }

    bool isCyclic(int vertices, vector<int> adj[])
    {
        vector<bool> visited(vertices + 1, false);
        vector<bool> res(vertices + 1, false);

        for (int i = 0; i < vertices; i++)
        {
            if (dfs(i, visited, res, adj))
                return true;
        }
        return false;
    }
};

void _main()
{
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 3}};
    // int n = 6;
    // n = 5, edges = {{0, 1}, {2, 1}, {3, 1}, {1, 4}, {2, 4}};
    // n = 5, edges = {{1, 2}, {3, 2}, {4, 1}, {3, 4}, {0, 2}};
    int vertices = 4;
    int n = 4; //no of edges
    vector<int> adj[vertices];
    for (vector<int> edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }

    cout << sol.isCyclic(vertices, adj);

    cout << endl;
}

int main()
{
    _main();
    return 0;
}