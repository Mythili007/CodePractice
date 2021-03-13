/**
 * https://leetcode.com/problems/transpose-matrix/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &A)
    {
        int col = A[0].size();
        int row = A.size();
        vector<vector<int>> a(col, vector<int>(row,0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                a[j][i] = A[i][j];
            }
        }
        return a;
    }
};

void _main()
{
    Solution sol;
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> res = sol.transpose(a);
    for (vector<int> i : res)
    {
        for (int _i : i)
            cout << " " << _i << " ";
        cout << endl;
    }

    cout << endl;
}

int main()
{
    _main();
    return 0;
}