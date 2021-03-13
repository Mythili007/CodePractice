/**
 * https://leetcode.com/problems/maximum-product-of-three-numbers/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        int n = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            n = nums[i];
            if (n <= min1)
            {
                min2 = min1;
                min1 = n;
            }
            else if (n <= min2)
            {
                min2 = n;
            }

            if (n >= max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = n;
            }
            else if (n >= max2)
            {
                max3 = max2;
                max2 = n;
            }
            else if (n >= max3)
            {
                max3 = n;
            }
        }

        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    // nums = {-1, -2, -3, -4};

    int res = sol.maximumProduct(nums);
    // for (int _v : res)
    // {
    // for (int d : _v)
    // {
    cout << res << " ";
    cout << endl;
    // }
    // }
}

int main()
{
    _main();
    return 0;
}