/**
 * https://leetcode.com/problems/find-lucky-integer-in-an-array/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        int c = 0;
        unordered_map<int, int> m;
        vector<int> a;
        for (int i : arr)
            m[i]++;

        for (auto i : m)
        {
            cout << i.first << "   " << i.second << endl;
            if (i.first == i.second)
            {
                a.push_back(i.first);
            }
        }
        if (a.size() > 0)
            c = *max_element(a.begin(), a.end());
        return c;
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {2, 2, 2, 3, 3};

    int res = sol.findLucky(a);
    // for (int i : res)
    //     cout << i << " ";
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}