/**
 * https://leetcode.com/problems/height-checker/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int c = 0;
        vector<int> a;

        for (int i = 0; i < heights.size(); i++)
        {
            a.push_back(heights[i]);
        }

        sort(heights.begin(), heights.end());
        for (int i = 0; i < heights.size(); i++)
        {
            if (heights[i] != a[i])
                c++;
        }

        return c;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {1, 1,1,2,4,3};
    int k = 4;
    // nums = {-1, -2, -3, -4};

    int res = sol.heightChecker(nums);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}