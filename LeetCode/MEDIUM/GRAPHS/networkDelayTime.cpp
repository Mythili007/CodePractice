
/*
 * https://leetcode.com/problems/network-delay-time/
 * 743. Network Delay Time
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> intPair;

class Solution
{
public:
    /* void dfs(int src, int &dist, map<int, bool> &visited, map<int, set<intPair>> store)
    {
        if (visited[src])
            return;
        visited[src] = true;
        for (auto i : store[src])
        {
            int vertex = i.first;
            int wt = i.second;
            dist += wt;
            // visited[vertex] = true;
            dfs(vertex, dist, visited, store);
        }
    } */

    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<intPair> store[n + 1];
        for (vector<int> edge : times)
            store[edge[0]].push_back({edge[1], edge[2]});

        vector<int> distance(n + 1, INT_MAX);
        priority_queue<intPair, vector<intPair>, greater<intPair>> pq;
        int dist = 0;
        pq.push({0, k});
        distance[k] = 0;

        while (!pq.empty())
        {
            int vertex = pq.top().second;
            pq.pop();

            for (auto i : store[vertex])
            {
                int x = i.first;
                int wt = i.second;

                if (distance[x] > distance[vertex] + wt)
                {
                    distance[x] = distance[vertex] + wt;
                    pq.push({distance[x], x});
                }
            }
        }

        dist = *max_element(distance.begin() + 1, distance.end());
        return dist == INT_MAX ? -1 : dist;
    }
};

void _main()
{
    Solution sol;
    vector<vector<int>> edges = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4, k = 2;
    edges = {{1, 2, 1}};
    n = 2, k = 2;

    cout << sol.networkDelayTime(edges, n, k);
    cout << endl;
}

int main()
{
    _main();
    return 0;
}