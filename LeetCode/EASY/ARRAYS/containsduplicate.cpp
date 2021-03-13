/**
 * https://leetcode.com/problems/contains-duplicate/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]]++;

        for (auto i : m)
            if (i.second > 1)
                return true;

        return false;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    // nums = {0, 1, 2, 3, 3, 5, 2, 1, 0};

    bool res = sol.containsDuplicate(nums);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}