/**
 * https://leetcode.com/problems/get-maximum-in-generated-array/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        vector<int> nums;
        int maxi = INT_MIN;
        if (n == 0)
            return 0;
        if (n < 1)
        {
            return 1;
        }
        else
        {

            nums.push_back(0);
            nums.push_back(1);
            // nums[2] = nums[1];
            /* 
        nums[2 * i] = nums[i] when 2 <= 2 * i <= n
        nums[2*1] = nums[1]
        nums[2*1+1] = nums[1]+nums[2]
        nums[2*2] = nums[2];
        nums[2*2+1] = nums[2]+nums[3];
        nums[2 * i + 1] = nums[i] + nums[i + 1] when 2 <= 2 * i + 1 <= n
         */
            for (int i = 2; i < (n + 1); i++)
            {
                if (i % 2 == 0)
                {
                    nums.push_back(nums[(i / 2)]);
                }
                else
                    nums.push_back(nums[i / 2] + nums[(i / 2) + 1]);
            }

            for (int i : nums)
            {
                if (i > maxi)
                    maxi = i;
            }
        }

        return maxi;
    }
};

void _main()
{
    Solution sol;
    // vector<int> nums = {0, 1, 1, 1, 1, 1};
    // nums = {1, 0};
    int n = 7;
    int res = sol.getMaximumGenerated(n);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}