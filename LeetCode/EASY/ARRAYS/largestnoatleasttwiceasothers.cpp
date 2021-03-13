/**
 * https://leetcode.com/problems/maximum-product-of-three-numbers/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dominantIndex(vector<int>& nums)
    {
        int m = *max_element(nums.begin(), nums.end());
        int c = 0;
        int ind = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == m)
                ind = i;
            if (2*nums[i] <= m)
                c++;
        }
        if (c == nums.size())
            return ind;
        else
            return -1;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    // nums = {-1, -2, -3, -4};

    int res = sol.dominantIndex(nums);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}