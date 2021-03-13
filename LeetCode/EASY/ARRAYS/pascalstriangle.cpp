/**
 * https://leetcode.com/problems/pascals-triangle/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        vector<int> a;
        vector<int> b;
        a.push_back(1);
        res.push_back(a);
        // if (numRows == 1)
        // {
        //     return res;
        // }
        // a.push_back(1);
        // a.push_back(1);
        // res.push_back(a);

        // if (numRows == 2)
        //     return res;
        // if (numRows > 2)
        // {
            for (int i = 1; i < numRows; i++)
            {
                a = {};
                b = res[i - 1];
                int crntEle = 0;
                for (int j = 0; j <= i; j++)
                {
                    if (j == 0 || j == i)
                        a.push_back(1);
                    else
                    {
                        crntEle = b[j - 1] + b[j];
                        a.push_back(crntEle);
                    }
                }
                res.push_back(a);
            }
        // }
        return res;
    }
};

void _main()
{
    Solution sol;
    int n = 5;
    vector<vector<int>> res = sol.generate(n);
    for (vector<int> i : res)
    {
        for (int _i : i)
            cout <<" " <<_i << " ";
        cout << endl;
    }

    cout << endl;
}

int main()
{
    _main();
    return 0;
}