
/*
 * 1557. Minimum Number of Vertices to Reach All Nodes
 * https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<int, set<int>> store;
    map<int, bool> visited;
    vector<int> res;
    unordered_set<int> un_set;
    void insertIntoMap(vector<int> edge)
    {
        if (store.find(edge[0]) == store.end())
            store[edge[0]] = {};

        // if (store.find(edge[1]) == store.end())
        //     store[edge[1]] = {};

        store[edge[0]].insert(edge[1]);
        // store[edge[1]].insert(edge[0]);
    }

    void dfs(int src)
    {
        if (visited[src]){
            return;
        }
        visited[src] = true;
        for (auto i : store[src])
        {
            dfs(i);
            un_set.erase(i);
        }
    }

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        for (vector<int> edge : edges)
            insertIntoMap(edge);

        for (auto i : store)
            un_set.insert(i.first);

        //Initialise visited map with false values
        for (auto i : store)
            visited[i.first] = false;

        //Traverse the graph
        for (auto i : store)
            dfs(i.first);

        for (auto i : un_set)
            res.push_back(i);
        return res;
    }
};

void _main()
{
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
    int n = 6;
    n = 5, edges = {{0, 1}, {2, 1}, {3, 1}, {1, 4}, {2, 4}};
    n = 5, edges = {{1, 2}, {3, 2}, {4, 1}, {3, 4}, {0, 2}};
    vector<int> res = sol.findSmallestSetOfVertices(n, edges);
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    _main();
    return 0;
}