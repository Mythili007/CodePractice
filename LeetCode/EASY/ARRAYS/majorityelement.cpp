/**
 * https://leetcode.com/problems/majority-element/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> mp;
        int n = nums.size();
        int val = 0;
        int m = 0;
        for (int i = 0; i < n; i++)
            mp[nums[i]]++;

        for (auto i : mp)
        {
            if (i.second > m)
                m = i.second;
        }

        for (auto i : mp)
        {
            if (m == i.second && i.second >= n / 2)
                val = i.first;
        }
        return val;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    // nums = {0,0,1,1,1,2,2,3,3,4};
    nums = {3, 2, 3};

    int res = sol.majorityElement(nums);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}