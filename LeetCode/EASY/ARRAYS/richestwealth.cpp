/**
 * https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int sum = 0;
        int maxi = INT_MIN;
        for (vector<int>& i: accounts)
        {
            sum = accumulate(i.begin(), i.end(), 0);
            maxi = max(sum, maxi);
        }
        return maxi;
    }
};

void _main()
{
    Solution sol;
    vector<vector<int>> accounts = {{3, 7, 8}, {9, 1, 3}, {1, 6, 17}};
    accounts = {{1,2,3}, {3,2,1}};
    int res = sol.maximumWealth(accounts);
    cout << res << endl;
    /* for (int _v : res)
    {
        cout << _v << " ";
    } */
}

int main()
{
    _main();
    return 0;
}