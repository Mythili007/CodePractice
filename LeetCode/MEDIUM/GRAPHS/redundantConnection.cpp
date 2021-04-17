
/*
 * Detect cycle in a directed graph - GFG
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(int vertex, vector<int> parent)
    {
        if (vertex == parent[vertex])
            return parent[vertex];

        return parent[vertex] = find(parent[vertex], parent);
    }

    void unionSet(int v1, int v2, vector<int> parent)
    {
        int _x = find(v1, parent);
        int _y = find(v2, parent);

        if (_x != _y)
            parent[_x] = _y;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<int> parent(edges.size());
        for (int i = 0; i < edges.size(); i++)
            parent[i] = i;
        vector<vector<int>> result;
        vector<int> _result;
        for (vector<int> edge : edges)
        {
            int x = find(edge[0], parent);
            int y = find(edge[1], parent);

            if (x == y)
                continue;
            unionSet(edge[0], edge[1], parent);
            result.push_back(edge);
        }
        for (vector<int> re : result)
        {
            cout << "[ " << re[0] << ", " << re[1] << " ]" << endl;
        }
        return result[result.size() - 1];
    }
};

void _main()
{
    Solution sol;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    edges = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    vector<int> res = sol.findRedundantConnection(edges);
    cout << "edge to be removed: "
         << "[ " << res[0] << ", " << res[1] << " ]" << endl;
}

int main()
{
    _main();
    return 0;
}