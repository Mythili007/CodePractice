
/*
 * https://leetcode.com/problems/product-of-array-except-self/
 * 238. Product of Array Except Self
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> leftProd(size);
        vector<int> rightProd(size);
        vector<int> p(size);
        leftProd[0] = 1;
        rightProd[size - 1] = 1;
        for (int i = 1; i < size; i++)
            leftProd[i] = leftProd[i - 1] * nums[i - 1];

        for (int i = size - 2; i >= 0; i--)
            rightProd[i] = rightProd[i + 1] * nums[i + 1];

        for (int i = 0; i < size; i++)
            p[i] = leftProd[i] * rightProd[i];
        return p;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {2, 0, 1, 4};
    // nums = {-2, -1, -1};
    nums = {0, 4, 0};
    vector<int> res = sol.productExceptSelf(nums);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}