/**
 * https://leetcode.com/problems/single-number/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int n = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        for (auto i : m)
        {
            if (i.second == 1)
            {
                n = i.first;
                break;
            }
        }
        return n;
    }
};

void _main()
{
    Solution sol;
    vector<int> A = {1, 2,2, 3, 3};
    // A = {5, 1, 5, 2, 5, 3, 5, 4};
    // A = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    // A = {1, 2};
    int res = sol.singleNumber(A);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}