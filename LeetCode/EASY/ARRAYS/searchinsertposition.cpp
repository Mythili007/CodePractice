/**
 * https://leetcode.com/problems/search-insert-position/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int c = 0;
        if (nums[0] == target)
            c = 0;
        else if (target == nums[nums.size() - 1])
            c = nums.size() - 1;
        else if (target > nums[nums.size() - 1])
            c = nums.size();
        else
        {
            for (int i = 1; i <= nums.size() - 1; i++)
            {
                if (nums[i] == target)
                {
                    cout << "check 1" << endl;
                    c = i;
                }
                else if (target > nums[i - 1] && target < nums[i])
                {
                    cout << "check 2" << endl;
                    c = i;
                    break;
                }
            }
        }
        return c;
    }

    int searchInsert1(vector<int> &nums, int target)
    {
        if (target < nums[0])
            return 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (target <= nums[i])
                return i;
        }
        return nums.size();
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {1, 3, 5, 6};
    // vector<int> b = {2, 4};
    // nums = {0,0,1,1,1,2,2,3,3,4};
    // nums = {3, 2, 3};
    int b = 7;

    int res = sol.searchInsert(a, b);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}