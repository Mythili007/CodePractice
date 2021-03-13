/**
 * https://leetcode.com/problems/maximum-subarray/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Kadane's Algorithm
    int maxSubArray(vector<int> &nums)
    {
        int currentMax = nums[0];
        int maxSoFar = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            currentMax = max(nums[i], currentMax + nums[i]);

            if (currentMax > maxSoFar)
                maxSoFar = currentMax;
        }
        return maxSoFar;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    int res = sol.maxSubArray(nums);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}