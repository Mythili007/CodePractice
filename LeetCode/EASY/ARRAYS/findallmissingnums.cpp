/**
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> missingNumber(vector<int> &nums)
    {
        vector<int> c;
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            j = abs(nums[i]) - 1;
            // cout<<"j: "<< j <<"   nums[j]: "<< nums[j]<<endl;
            nums[j] = abs(nums[j]) * -1;
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                c.push_back(i + 1);
        }
        return c;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {1, 0, 3};
    // nums = {0,0,1,1,1,2,2,3,3,4};
    nums = {1, 2, 3, 4, 7};

    vector<int> res = sol.missingNumber(nums);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}