/**
 * https://leetcode.com/problems/find-pivot-index/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Time limit exceeded
    int pivotIndex1(vector<int> &nums)
    {
        int sum1 = 0;
        int sum2 = 0;
        int pivotInd = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum1 = 0;
            for (int j = 0; j < i; j++)
            {
                sum1 += nums[j];
            }
            sum2 = 0;
            for (int k = i + 1; k < nums.size(); k++)
            {
                sum2 += nums[k];
            }
            if (sum1 == sum2)
            {
                pivotInd = i;
                break;
            }
        }

        return pivotInd;
    }

    int pivotIndex(vector<int> &nums)
    {
        int sum = 0;
        int pivotInd = -1;
        for (int i : nums)
            sum += i;
        int sum1 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (sum1 == sum - sum1 - nums[i])
                return i;

            sum1 += nums[i];
        }

        return pivotInd;
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {1, 7, 3, 6, 5, 6};

    int res = sol.pivotIndex(a);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}