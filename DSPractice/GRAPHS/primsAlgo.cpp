/*
 * PRIMS MINIMAL SPANNING TREE ALGORITHM USING ADJACENCY LIST
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> intPair;

class Solution
{
public:
    void addEdge(vector<intPair> adj[], int src, int dest, int wt)
    {
        adj[src].push_back({dest, wt});
        adj[dest].push_back({src, wt});
    }

    vector<int> prims(vector<intPair> adj[], int vertices, int src)
    {
        // Returns edges
        //DS for heap + map
        vector<int> distance(vertices, INT_MAX);
        priority_queue<intPair, vector<intPair>, greater<intPair>> pq;
        vector<int> parent(vertices, -1);

        distance[src] = 0;
        pq.push({0, src}); // src vertex distance is 0
        distance[src] = 0;
        vector<bool> isInMST(vertices, false);
        while (!pq.empty())
        {
            //get minimum
            int min_vertex = pq.top().second;
            pq.pop();
            isInMST[min_vertex] = true;
            for (auto adjacent : adj[min_vertex])
            {
                int x = adjacent.first;
                int wt = adjacent.second;

                if (!isInMST[x] && distance[x] > wt)
                {
                    distance[x] = wt;
                    pq.push({distance[x], x});
                    parent[x] = min_vertex;
                }
            }
        }
        return parent;
    }
};

void _main()
{
    Solution sol;
    int vertices = 9;
    vector<intPair> adj[vertices];
    //Add edges
    sol.addEdge(adj, 0, 1, 4);
    sol.addEdge(adj, 0, 7, 8);
    sol.addEdge(adj, 1, 2, 8);
    sol.addEdge(adj, 1, 7, 11);
    sol.addEdge(adj, 2, 3, 7);
    sol.addEdge(adj, 2, 8, 2);
    sol.addEdge(adj, 2, 5, 4);
    sol.addEdge(adj, 3, 4, 9);
    sol.addEdge(adj, 3, 5, 14);
    sol.addEdge(adj, 4, 5, 10);
    sol.addEdge(adj, 5, 6, 2);
    sol.addEdge(adj, 6, 7, 1);
    sol.addEdge(adj, 6, 8, 6);
    sol.addEdge(adj, 7, 8, 7);

    vector<int> res = sol.prims(adj, vertices, 0);
    for (int j = 0;j<res.size();j++)
        cout << j << " " << res[j] << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}