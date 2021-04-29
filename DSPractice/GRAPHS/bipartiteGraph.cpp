
/*
 * BIPARTITE GRAPH
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BFS
    bool isGraphBipartite(vector<vector<int>> &adj)
    {
        vector<int> color(adj.size(), 0);
        queue<int> q;
        for (int i = 0; i < adj.size(); i++)
        {
            if (color[i])
                continue;
            q.push(i);
            color[i] = 1;

            while (!q.empty())
            {
                int u = q.front();
                for (int v : adj[u])
                {
                    if (!color[v])
                    {
                        color[v] = -color[u];
                        q.push(v);
                    }
                    else if (color[u] == color[v])
                        return false;
                }
                q.pop();
            }
        }
        return true;
    }
};

void _main()
{
    Solution sol;
    vector<vector<int>> edges = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    edges = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    vector<vector<int>> adj;
    for (vector<int> edge : edges)
        adj.push_back(edge);

    cout << sol.isGraphBipartite(adj);
    cout << endl;
}

int main()
{
    _main();
    return 0;
}