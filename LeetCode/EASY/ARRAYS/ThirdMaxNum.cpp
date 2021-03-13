/**
 * https://leetcode.com/problems/third-maximum-number/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int val = 0;
        int size = nums.size();
        if (size == 1)
            val = nums[0];
        int c = 1;
        for (int i = size - 2; i >= 0; i--)
        {
            if (nums[i + 1] != nums[i])
                c++;

            if (c == 3)
            {
                return nums[i];
            }
        }

        return nums[nums.size() - 1];
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {2, 2, 3, 1};
    // a = {{1, 0}, {1, 0}, {1, 0}, {1, 1}};
    // int k = 4;

    int res = sol.thirdMax(a);
    // for (int i : res)
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}