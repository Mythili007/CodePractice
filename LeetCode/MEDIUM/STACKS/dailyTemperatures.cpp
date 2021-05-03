/*
 * https://leetcode.com/problems/daily-temperatures/
 * 739. Daily Temperatures
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        int c = 0;
        bool found = false;
        vector<int> ans;
        for (int i = 0; i < T.size(); i++)
        {
            c = 1;
            found = false;
            for (int j = i + 1; j < T.size(); j++)
            {
                if (T[j] > T[i])
                {
                    found = true;
                    ans.push_back(c);
                    break;
                }
                else
                {
                    c++;
                }
            }
            if (!found)
                ans.push_back(0);
        }
        return ans;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums1 = {73, 74, 75, 71, 69, 72, 76, 73};
    // nums1 = {1, 5, 3, 6, 8}; //5 6 6 8 -1
    vector<int> res = sol.dailyTemperatures(nums1);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}