/**
 * https://leetcode.com/problems/contains-duplicate-ii/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //TIME LIMIT EXCEEDED
    bool containsNearbyDuplicate_1(vector<int> &nums, int k)
    {
        bool flag = false;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j] && i != j && abs(i - j) <= k)
                {
                    flag = true;
                }

                if (flag == true)
                    break;
            }
            if (flag == true)
                break;
        }

        return flag;
    }

    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.count(nums[i]) && (i - m[nums[i]]) <= k)
                return true;
            else
                m[nums[i]] = i;
        }
        return false;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    // nums = {0, 1, 2, 3, 3, 5, 2, 1, 0};
    int k = 3;

    bool res = sol.containsNearbyDuplicate(nums, k);
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