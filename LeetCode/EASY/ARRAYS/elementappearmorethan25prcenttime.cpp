/**
 * https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        unordered_map<int, int> m;
        int n = arr.size();
        int res = 0;
        int k = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }

        for (auto i : m)
        {
            cout << "i.first : " << i.first << "    i.second: " << i.second << endl;
            if (i.second > k)
            {
                k = i.second;
                res = i.first;
            }
        }

        return res;
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {1, 2, 2, 6, 6, 6, 6, 7, 10};
    int k = 34;
    a = {5668, 5668, 5668, 5668, 22011};

    int res = sol.findSpecialInteger(a);
    // for (int i : res)
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}