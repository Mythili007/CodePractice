/*
 * BFS TRAVERSAL OF A GRAPH
  */

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

map<int, set<int>> m;
map<int, bool> visited;
vector<int> res;

class Solution
{
public:
    void insertIntoMap(vector<int> edge)
    {
        if (m.find(edge[0]) == m.end())
            m[edge[0]] = {};

        if (m.find(edge[1]) == m.end())
            m[edge[1]] = {};

        m[edge[0]].insert(edge[1]);
        m[edge[1]].insert(edge[0]);
    }

    void traverseTheGraph(int src)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int front = q.front();
            res.push_back(front);
            q.pop();

            for (auto i : m[front])
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
        for (vector<int> edge : edges)
            insertIntoMap(edge);

        // Create a visted array with false values
        for (auto i : m)
            visited[i.first] = false;

        // traverse for each edge
        traverseTheGraph(m.begin()->first);
        return res;
    }
};

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