/**
 * https://leetcode.com/problems/increasing-decreasing-string/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string sortString(string s)
    {
        string res;
        int cnt[26] = {};
        for (auto ch : s)
        {
            ++cnt[ch - 'a'];
        }
        while (s.size() != res.size())
        {
            for (auto i = 0; i < 26; ++i)
            {
                res += string(--cnt[i] >= 0 ? 1 : 0, 'a' + i);
            }

            for (auto i = 25; i >= 0; --i)
            {
                res += string(--cnt[i] >= 0 ? 1 : 0, 'a' + i);
            }
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    string s = "aaabbbccc";
    string res = sol.sortString(s);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}