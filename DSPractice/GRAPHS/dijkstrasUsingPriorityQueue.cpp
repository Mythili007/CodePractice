/*
 * DIJKSTRA'S SHORTEST PATH ALGORITHM USING ADJACENCY LIST
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> intPair;

class Solution
{
public:
    void addEdge(vector<intPair> adj[], int u, int v, int wt)
    {
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }

    vector<int> dijkstra(vector<intPair> adj[], int vertices, int src)
    {
        vector<int> distance(vertices, INT_MAX);
        priority_queue<intPair, vector<intPair>, greater<intPair>> pq;
        //Insert source node with distance as 0
        pq.push(make_pair(0, src));
        distance[src] = 0;

        while (!pq.empty())
        {
            int vertex = pq.top().second;
            pq.pop();

            for (auto v : adj[vertex])
            {
                int x = v.first;
                int weight = v.second;

                if (distance[x] > distance[vertex] + weight)
                {
                    distance[x] = distance[vertex] + weight;
                    pq.push(make_pair(distance[x], x));
                }
            }
        }
        return distance;
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

    vector<int> res = sol.dijkstra(adj, vertices, 0);
    for (int i = 0; i < res.size(); i++)
        cout << i << "   " << res[i] << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}