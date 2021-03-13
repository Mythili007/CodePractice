/**
 * https://leetcode.com/problems/set-mismatch/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int n = nums.size();
        vector<int> v;
        int dup = 0, missing = 0;

        for (int i : nums)
            m[i]++;
        for (int i = 1; i <= n; i++)
        {
            if (m.find(i) != m.end() && m[i] > 1)
                dup = i;
            else
                missing = i;
        }
        v.push_back(dup);
        v.push_back(missing);
        return v;
    }
};

void _main()
{
    Solution sol;
    vector<int> n = {1, 2, 2, 4};
    n = {1, 1};
    // n = {2, 2};
    vector<int> res = sol.findErrorNums(n);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}