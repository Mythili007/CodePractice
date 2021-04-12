
/*
 * DFS TRAVERSAL OF A GRAPH
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<int, vector<int>> store;
    vector<int> res;
    map<int, bool> visited;

    void insertIntoMap(vector<int> edge)
    {
        if (store.find(edge[0]) == store.end())
            store[edge[0]] = {};

        if (store.find(edge[1]) == store.end())
            store[edge[1]] = {};

        store[edge[0]].push_back(edge[1]);
        store[edge[1]].push_back(edge[0]);
    }

    void traverseTheGraph(int src)
    {
        if (visited[src])
            return;

        visited[src] = true;
        res.push_back(src);
        for (auto i : store[src])
            traverseTheGraph(i);
    }

    vector<int> dfsTraversal(vector<vector<int>> &edges)
    {
        // Insert into map
        for (vector<int> edge : edges)
            insertIntoMap(edge);

        // Initialise boolean array
        for (auto i : store)
            visited[i] = false;

        // traverse the graph
        for (auto i : store)
            traverseTheGraph(i.first);
    }
};

void _main()
{
    Solution sol;
    vector<vector<int>> edges = {{3, 4}, {3, 5}, {3, 6}, {4, 3}, {5, 6}, {5, 3}};
    vector<int> res = sol.dfsTraversal(edges);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}