/**
 * https://leetcode.com/problems/max-consecutive-ones/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int c = 0;
        int m = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
                c++;
            else
                c = 0;
            
            if (c > m)
                m = c;
        }
        return m;
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {1, 0};

    int res = sol.findMaxConsecutiveOnes(a);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}