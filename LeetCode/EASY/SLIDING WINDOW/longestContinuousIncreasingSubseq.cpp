/*
 * https://leetcode.com/problems/longest-continuous-increasing-subsequence/
 * 674. Longest Continuous Increasing Subsequence
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int res = 0;
        int anchor = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i - 1] >= nums[i])
                anchor = i;

            res = max(res, i - anchor + 1);
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {1, 2, 3, 4, 6, 7};

    cout << sol.findLengthOfLCIS(a) << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}