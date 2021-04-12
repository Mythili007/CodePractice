
/*
 * DIJKSTRA'S SHORTEST PATH ALGORITHM
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, set<int>> store;
    vector<bool> visited;
    vector<pair<int, int>> init_vec(store.size());
    map<pair<int, int>, int> weights;
    vector<int> dist_vec;
    map<int, vector<int>> path_map;

    void insertIntoMap(vector<int> &edge)
    {
        if (store.find(edge[0]) == store.end())
            store[edge[0]] = {};

        if (store.find(edge[1]) == store.end())
            store[edge[1]] = {};

        store[edge[0]].insert(edge[1]);
        store[edge[1]].insert(edge[0]);
    }

    int minDistance(vector<int> dist, map<int, bool> visited)
    {
        int min_dist = INT_MAX;
        int min_ind = 0;

        for(int i = 0;i<store.size();i++){
            if(!visited[i] && dist[i] <= min_dist)
                min_dist = dist[i.first];
                min_ind = i.first;
        }
        return min_ind;
    }

    int shortestDist(vector<vector<int>> &edges)
    {
        //Insert into map
        for (vector<int> edge : edges)
            insertIntoMap(edge);

        /* int j = 0;
        for (auto i : store)
        {
            init_vec[j] = make_pair(INT_MAX, i.first);
            j++;
        }

        for (int i = 0; i < init_vec.size(); i++)
        {
            if (dist_vec.find(init_vec[i].second) == dist_vec.end())
                dist_vec[init_vec[i].second] = {};
        } */

        for (int i = 0;i<store.size();i++){
            dist_vec[i] = INT_MAX;
            visited[i] = false;
        }

        dist_vec[store[0].first] = 0;

        // loop through all vertices
        for (int i = 0;i<store.size()-1;i++)
        {
            int min_dist = minDistance(dist_vec, vistied);
            visited[i] = true;

            for(int j = 0;j<store.size();j++){
                if(!visited[j] && )
            }
        }
    }
};

void _main()
{
    Solution sol;
    vector<vector<int>> edges = {{3, 4, 3}, {3, 5, 2}, {3, 6, 1}, {4, 6, 2}, {5, 6, 3}, {5, 7, 1}};

    int shortest_dist = sol.shortestDist(edges);
    cout << shortest_dist << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}