/**
 * https://leetcode.com/problems/missing-number/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber1(vector<int> &nums)
    {
        int len = nums.size();
        int sum = 0;
        int sum1 = 0;
        for (int i = 0; i <= len; i++)
        {
            sum1 += i;
        }
        for (int i = 0; i < len; i++)
        {
            sum += nums[i];
        }

        return abs(sum1 - sum);
    }

    int missingNumber(vector<int> &nums)
    {
        int a = nums[0];
        int b = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            a = a ^ nums[i];
        }
        for (int i = 1; i < nums.size() + 1; i++)
        {
            b = b ^ nums[i];
        }
        return a ^ b;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {1, 0, 3};
    // nums = {0,0,1,1,1,2,2,3,3,4};
    nums = {1, 2,2,3,3,4,7};

    int res = sol.missingNumber(nums);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}