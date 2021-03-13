/**
 * https://leetcode.com/problems/find-the-duplicate-number/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int len = nums.size();
        int dup;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++)
        {
            if(nums[i] == nums[i+1]){
                dup = nums[i];
                break;
            }
        }

        return dup;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {1,3,4,2,2};
    // nums = {0,0,1,1,1,2,2,3,3,4};
    // nums = {1, 0};

    int res = sol.findDuplicate(nums);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}