
/*
 * https://leetcode.com/problems/path-with-maximum-probability/
 * 1514. Path with Maximum Probability
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> intPair;

class Solution
{
public:
    void createGraph(vector<vector<int>> &edges, vector<double> &succProb, vector<vector<pair<int, double>>> &graph)
    {
        int i = 0;
        for (vector<int> edge : edges)
        {
            double wt = succProb[i];
            graph[edge[0]].push_back(make_pair(edge[1], wt));
            graph[edge[1]].push_back(make_pair(edge[0], wt));
            i++;
        }
    }

    vector<double> dijkstra(vector<vector<pair<int, double>>> &graph, int start, vector<bool> &visited)
    {
        priority_queue<pair<double, int>> pq;
        pq.push(make_pair((double)1.0, start));

        vector<double> distance(n, (double)0.0);
        distance[start] = 1.0;

        while (!pq.empty())
        {
            double crnt_prob = pq.top().first;
            int vertex = pq.top().second;
            pq.pop();

            if (!visited[vertex])
            {
                visited[vertex] = true;
                for (auto i : graph[vertex])
                {
                    int x = i.first;
                    double wt = i.second;
                    if (distance[x] < crnt_prob * wt)
                    {
                        distance[x] = crnt_prob * wt;
                        pq.push(make_pair(distance[x], x));
                    }
                }
            }
        }
        return distance;
    }

    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<vector<pair<int, double>>> graph(n);
        vector<bool> visited(n, false);

        createGraph(edges, succProb, graph);

        vector<double> res = dijkstra(graph, succProb, start, end, n, visited);

        // for (double i : res)
        //     cout << "i: " << i << " ";
        // cout << endl;
        return res[end];
    }
};

void _main()
{
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};
    int start = 0, end = 2, n = 3;

    double res = sol.maxProbability(n, edges, succProb, start, end);
    cout << res << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}