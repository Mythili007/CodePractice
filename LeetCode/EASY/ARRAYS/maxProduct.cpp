/**
 * https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int max = 0;
        int prod = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                prod = (nums[i] - 1) * (nums[j] - 1);
                if (prod > max)
                    max = prod;
            }
        }
        return max;
    }
};

void _main()
{
    Solution sol;

    vector<int> nums = {3, 4, 5, 2};
    nums = {1, 5, 4, 5};
    // A={{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
    int res = sol.maxProduct(nums);

    /* for (vector<int> _v : res)
    {
        for (int d : _v)
        {
            cout << d << " ";
        }
        cout << endl;
    } */
    cout << res << endl;
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
