
/*
 * https://leetcode.com/problems/sort-the-matrix-diagonally/
 * 1329. Sort the Matrix Diagonally
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[i].size(); j++)
                m[i - j].push(mat[i][j]);

        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[i].size(); j++)
            {
                mat[i][j] = m[i - j].top();
                m[i - j].pop();
            }

        return mat;
    }
};

void _main()
{
    Solution sol;
    vector<vector<int>> mat = {{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};
    vector<vector<int>> result = sol.diagonalSort(mat);
    for (vector<int> vec : result)
    {
        for (int i : vec)
            cout << i << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    _main();
    return 0;
}