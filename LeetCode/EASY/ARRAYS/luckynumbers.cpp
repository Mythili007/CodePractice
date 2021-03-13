/**
 * https://leetcode.com/problems/lucky-numbers-in-a-matrix/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int m = 0;
        int n = 0;

        vector<int> minInRow;
        vector<int> maxInCol;
        vector<int> res;
        for (int i = 0; i < matrix.size(); i++)
        {
            m = INT_MAX;
            for (int j = 0; j < matrix[i].size(); j++)
            {
                m = min(m, matrix[i][j]);
            }
            minInRow.push_back(m);
        }
        for (int i = 0; i < matrix[0].size(); i++)
        {
            n = INT_MIN;
            for (int j = 0; j < matrix.size(); j++)
            {
                n = max(n, matrix[j][i]);
            }
            maxInCol.push_back(n);
        }

        for (int i = 0; i < maxInCol.size(); i++)
        {
            for (int j = 0; j < minInRow.size(); j++)
            {
                if (maxInCol[i] == minInRow[j])
                    res.push_back(maxInCol[i]);
            }
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    vector<vector<int>> nums = {{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
    nums = {{1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}};

    vector<int> res = sol.luckyNumbers(nums);
    for (int _v : res)
    {
        cout << _v << " ";
    }
}

int main()
{
    _main();
    return 0;
}