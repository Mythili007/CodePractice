/**
 * https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int c_even = 0;
        int c_odd = 0;
        for (int i = 0; i < position.size(); i++)
        {
            if(position[i]%2 == 0)
                c_even++;
            else
                c_odd++;
        }
        return min(c_even, c_odd);
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {2, 2, 2, 3, 3};
    int k = 4;
    nums = {2,3,3};

    int res = sol.minCostToMoveChips(nums);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}