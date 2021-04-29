/**
 * https://leetcode.com/problems/maximum-product-of-three-numbers/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> multWithoutIndexElement(vector<int> &nums)
    {
        auto multi = accumulate(nums.begin(), nums.end(), 1, multiplies<int>());
        vector<int> res;
        for (int i : nums)
            res.push_back(multi / i);
        return res;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};

    vector<int> res = sol.multWithoutIndexElement(nums);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}