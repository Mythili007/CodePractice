
/*
 * https://leetcode.com/problems/maximum-product-subarray/
 * 152. Maximum Product Subarray
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int prod = nums[0], left = 0, right = 0;
        int size = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++)
        {
            left = ((left != 0) ? left : 1) * nums[i];
            right = (right != 0 ? right : 1) * nums[size - i];

            prod = max(prod, max(left, right));
        }
        return prod;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {2, 3, -2, 4};
    // nums = {-2, -1, -1};
    // nums = {-2, 0, -1};
    int res = sol.maxProduct(nums);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}