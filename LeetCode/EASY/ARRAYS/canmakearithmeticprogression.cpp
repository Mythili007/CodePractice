/**
 * https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        bool flag = true;
        sort(arr.begin(), arr.end());
        int diff = (arr[1] - arr[0]);
        for (int i = 2; i < arr.size(); i++)
        {
            if ((arr[i] - arr[i - 1]) != diff)
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {1, 2, 5};
    // nums = {0,0,1,1,1,2,2,3,3,4};
    nums = {3, 5, 1};

    bool res = sol.canMakeArithmeticProgression(nums);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}