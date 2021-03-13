/**
 * https://leetcode.com/problems/flipping-an-image/
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        int k = 0;
        int rows = A.size();
        int cols = A[0].size();
        for (int i = 0; i < rows; i++)
        {
            k = cols - 1;
            for (int j = 0; j < k; j++)
            {
                swap(A[i][j], A[i][k]);
                k--;
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (A[i][j] == 1)
                    A[i][j] = 0;
                else
                    A[i][j] = 1;
            }
        }
        return A;
    }
};

void _main()
{
    Solution sol;

    vector<vector<int>> A = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};

    // A={{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
    vector<vector<int>> res = sol.flipAndInvertImage(A);

    for (vector<int> _v : res)
    {
        for (int d : _v)
        {
            cout << d << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        _main();
    }
    return 0;
}
