
/*
 * https://leetcode.com/problems/possible-bipartition/
 * 886. Possible Bipartition
 * Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
 * Each person may dislike some other people, and they should not go into the same group. 
 * Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
 * Return true if and only if it is possible to split everyone into two groups in this way.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<int, int> color;
    vector<int> *adjList;

public:
    bool dfs(int node, int c)
    {
        if (color.find(node) != color.end())
            return color[node] == c);
        else
            color.insert({node, c});
        // color each adjacent node with alternate color (2 way graph coloring)
        for (auto itr = adjList[node].begin(); itr != adjList[node].end(); ++itr)
        {
            // if a node already exists in map and its color differ from the one in this dfs call then return false (graph cannot be bipartite)
            if (!dfs(*itr, c ^ 1))
                return false;
        }
        return true;
    }

    bool possibleBipartition(int N, vector<vector<int>> &dislikes)
    {
        adjList = new vector<int>[N + 1];

        for (const vector<int> &d : dislikes)
        {
            adjList[d[0]].emplace_back(d[1]);
            adjList[d[1]].emplace_back(d[0]);
        }
        // for all connected components check if they are bipartite
        for (int i = 1; i <= N; i++)
        {
            // check if a node doesn't already exist in hash map and if dfs on it returns false then that connected component is not bipartite
            if (color.find(i) == color.end() && !dfs(i, 0))
                return false;
        }
        return true;
    }
};

void _main()
{
    Solution sol;
    vector<vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 4}};
    int n = 4;

    cout << sol.possibleBipartition(n, dislikes);
    cout << endl;
}

int main()
{
    _main();
    return 0;
}