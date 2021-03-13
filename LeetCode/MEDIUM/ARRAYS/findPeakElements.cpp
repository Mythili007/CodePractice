/**
 * https://leetcode.com/problems/find-peak-element/submissions/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int ind = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                ind = i - 1;
                break;
            }
            else
            {
                ind = i;
            }
        }
        return ind;
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {1, 2, 1, 3, 4, 5, 6, 4};
    int res = sol.findPeakElement(a, b);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}