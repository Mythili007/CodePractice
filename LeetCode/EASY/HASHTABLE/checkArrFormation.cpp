
/**
 * https://leetcode.com/problems/check-array-formation-through-concatenation/
 * 1640. Check Array Formation Through Concatenation
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
    {
        map<int, vector<int>> m;
        for (vector<int> i : pieces)
            m[i[0]] = i;

        vector<int> res;
        for (int i : arr)
        {
            if (m.find(i) != m.end())
            {
                vector<int> v = m[i];
                for (auto j : v)
                {
                    res.push_back(j);
                }
            }
        }
        return res == arr;
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {1, 2, 3, 9};
    vector<vector<int>> p = {{1, 2}, {3, 9}};

    cout << sol.canFormArray(a, p) << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}