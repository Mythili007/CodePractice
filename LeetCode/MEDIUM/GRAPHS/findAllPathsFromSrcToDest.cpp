
/*
 * FIND ALL PATHS FROM SOURCE TO DESTINATION
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<int, set<int>> store;
    map<int, bool> visited;
    vector<int> res;
    vector<vector<int>> paths;
    vector<int> path;
    void insertIntoMap(vector<int> edge)
    {
        if (store.find(edge[0]) == store.end())
            store[edge[0]] = {};

        if (store.find(edge[1]) == store.end())
            store[edge[1]] = {};

        store[edge[0]].insert(edge[1]);
        store[edge[1]].insert(edge[0]);
    }

    void dfs(vector<vector<int>> edges, int src, int dest, vector<vector<int>> &paths, vector<int> &path)
    {
        path.push_back(src);
        if (src == dest)
        {
            paths.push_back(path);
            return;
        }

        for (int i : store[src])
            dfs(edges, i, dest, paths, path);
    }

    vector<vector<int>> dfsTraversal(vector<vector<int>> edges)
    {
        //Insertion into map
        for (vector<int> edge : edges)
            insertIntoMap(edge);

        dfs(edges, 0, edges.size() - 1, paths, path);
        return paths;
    }
};

void _main()
{
    Solution sol;
    vector<vector<int>> edges = {{3, 4}, {3, 5}, {3, 6}, {4, 3}, {5, 6}, {5, 3}};
    vector<vector<int>> res = sol.dfsTraversal(edges);
    for (vector<int> i : res)
    {
        for (int j : i)
        {
            cout << j << "->";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    _main();
    return 0;
}