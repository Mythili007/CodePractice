/*
 * BFS TRAVERSAL OF A GRAPH
  */

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

class Solution
{
public:
    Solution()
    {
        fastio;
    }
    map<int, set<int>> store;
    map<int, bool> visited;
    vector<int> res;

    void insertIntoMap(vector<int> &edge)
    {
        if (store.find(edge[0]) == store.end())
            store[edge[0]] = {};

        if (store.find(edge[1]) == store.end())
            store[edge[1]] = {};

        store[edge[0]].insert(edge[1]);
        store[edge[1]].insert(edge[0]);
    }

    void traverseTheGraph(int src)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int val = q.front();
            q.pop();
            res.push_back(val);

            for (int i : store[val])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    vector<int> bfsTraversal(vector<vector<int>> &edges)
    {
        // Insert into map
        for (auto &edge : edges)
            insertIntoMap(edge);

        res.reserve(store.size());

        // Initialise the visited with the false values
        for (auto &i : store)
            visited[i.first] = false;

        // traverse the graph
        traverseTheGraph(store.begin()->first);
        return res;
    }
};

vector<vector<int>> generateGraph()
{
    int n = 1 * 1e4;
    cout << "n = " << n << endl;
    vector<vector<int>> res;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            res.push_back({i, j});
        }
    }

    return res;
}

void _main()
{
    Solution sol;
    vector<vector<int>> edges = {{3, 4}, {3, 5}, {3, 6}, {4, 3}, {4, 8}, {5, 6}, {5, 3}, {5, 7}};
    // vector<vector<int>> edges = generateGraph();
    /**
     * 3 -> [4, 5, 6]
     * 4-> [3, 8 ]
     * 5-> [3, 6, 7]
     * 6-> [3, 5]
     * 7->[5]
     * 8-> [4]
     * 
     * 3, 4, 5, 6, 8, 7
     * 
     */
    vector<int> res = sol.bfsTraversal(edges);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}