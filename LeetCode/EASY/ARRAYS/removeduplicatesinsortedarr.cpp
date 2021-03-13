/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int len = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[len])
            {
                // nums.erase(nums.begin() + (i));
                len++;
                nums[len] = nums[i];
            cout << "nums[len] : " << nums[len] << endl;
            }
        }
        return len + 1;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 3, 3};
    nums = {0,0,1,1,1,2,2,3,3,4};
    // nums = {1, 1, 2};

    int res = sol.removeDuplicates(nums);
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