
/*
 * https://leetcode.com/problems/count-nice-pairs-in-an-array/
 * 1814. Count Nice Pairs in an Array
  */

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

class Solution
{
public:
    int rev(int n)
    {
        int reversedNum = 0, rem = 0;
        while (n > 0)
        {
            rem = n % 10;
            reversedNum *= 10 + rem;
            n /= 10;
        }
        cout<<"rev: "<<reversedNum<<endl;
        return reversedNum;
    }

    int countNicePairs(vector<int> &nums)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                cout << "rev[j]: " << rev(nums[j]) << "  rev[i]: " << nums[i] << endl;
                // if (nums[i] + rev(nums[j]) == nums[j] + rev(nums[i]))
                //     cnt++;
            }
        }
        return cnt % MOD;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {42, 11, 1, 97};
    cout << sol.countNicePairs(nums) << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}