/* 
    *https://www.codechef.com/START3C/problems/RISK
 */

#include <bits/stdc++.h>

#define pb push_back
#define ll long long
#define mp make_pair
#define for_loop(i, n) for (int i = 0; i < n; i++)

using namespace std;

int n, m, c;

void dfs(int x, int y, vector<string> &g, vector<vector<bool>> &visited)
{
    if (x < 0 or x >= n or y < 0 or y >= m or visited[x][y] or g[x][y] == '0')
        return;

    visited[x][y] = 1;
    c++;
    dfs(x - 1, y, g, visited);
    dfs(x + 1, y, g, visited);
    dfs(x, y - 1, g, visited);
    dfs(x, y + 1, g, visited);
}

void maxRisk()
{
    cin >> n >> m;
    vector<string> g(n);
    for_loop(i, n) cin >> g[i];

    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    vector<int> comps;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                c = 0;
                dfs(i, j, g, visited);
                comps.pb(c);
            }
        }
    }
    sort(comps.begin(), comps.end());
    reverse(comps.begin(), comps.end());
    int ans = 0;
    for (int i = 1; i < comps.size(); i += 2)
        ans += comps[i];

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        maxRisk();
    }
    return 0;
}