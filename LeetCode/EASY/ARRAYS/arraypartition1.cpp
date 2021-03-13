/**
 * https://leetcode.com/problems/array-partition-i/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        int sum = 0;
        sort(nums.begin(), nums.end());
        //TO-DO Do with out sorting it 
        for (int i = 0; i < nums.size(); i += 2)
        {
            int a = nums[i];
            int b = nums[i + 1];
            sum += ((a > b) ? b : a);
        }
        return sum;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {1, 4, 2, 3};

    int res = sol.arrayPairSum(nums);
    cout << res << " ";
}

int main()
{
    _main();
    return 0;
}