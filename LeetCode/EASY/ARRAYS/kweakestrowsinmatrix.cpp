/**
 * https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool sortByVal(pair<int, int> &a,
                          pair<int, int> &b)
    {
        if (a.second == b.second)
            return a.first < b.first;

        return (a.second < b.second);
    }

    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<int> b;
        // map<int, int> mp;
        int s = mat.size();
        vector<pair<int, int>> a(s);
        if (s == 0)
            return {};
        int m = mat[0].size();
        for (int i = 0; i < s; i++)
        {
            int count = 1;
            a[i].first = i;
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    a[i].second = count++;
                }
            }
        }

        sort(a.begin(), a.end(), sortByVal);
        for (int i = 0; i < k; i++)
        {
            b.push_back(a[i].first);
        }

        return b;
    }
};

void _main()
{
    Solution sol;
    vector<vector<int>> a = {{1, 1, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 1, 1, 1, 1}};
    a = {{1, 0}, {1, 0}, {1, 0}, {1, 1}};
    int k = 4;

    vector<int> res = sol.kWeakestRows(a, k);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}