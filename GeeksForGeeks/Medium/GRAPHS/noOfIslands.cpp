// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /* void recdfs(vector<char> adj[], int s, stack<char> &st, vector<bool> &visited)
    {
        visited[s] = true;
        for (auto i : adj[s])
        {
            if (!visited[i])
                recdfs(adj, i, st, visited);
        }
        st.push(s);
    }

    void dfs(int v, vector<bool> &visited, vector<char> adj[], stack<char> &st)
    {
        // visited[v] = true;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
                recdfs(adj, i, st, visited);
        }
    }

    void rec1(vector<char> rev[], int t, vector<bool> &visited)
    {
        visited[t] = true;
        for (int u : rev[t])
        {
            if (visited[u] == false)
                rec1(rev, u, visited);
        }
    }

    int scc(int v, vector<char> adj[])
    {
        stack<char> st;
        vector<bool> visited(v, false);
        dfs(v, visited, adj, st);
        vector<char> rev[v];
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                rev[i].push_back(j);
            }
        }

        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
        }
        int cnt = 0;
        while (!st.empty())
        {
            int v = st.top();
            st.pop();

            if (!visited[v])
            {
                cnt++;
                rec1(rev, v, visited);
            }
        }
        return cnt;
    } */

    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        vector<char> adj[grid[0].size()];
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    adj[i].push_back(j);
                }
            }
        }
        int v = grid[0].size();

        return scc(v, adj);
    }
};

// { Driver Code Starts.
int main()
{
    /* int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
    } */
    Solution obj;
    vector<vector<char>> grid = {{0, 1}, {1, 0}, {1, 1}, {1, 0}};
    grid = {{0, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 1, 0, 1, 0}};
    int ans = obj.numIslands(grid);
    cout << ans << '\n';
    return 0;
} // } Driver Code Ends