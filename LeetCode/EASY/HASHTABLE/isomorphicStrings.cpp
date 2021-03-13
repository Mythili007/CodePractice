/**
 * https://leetcode.com/problems/isomorphic-strings/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        char ss[128] = {0};
        char tt[128] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            if (ss[s[i]] != tt[t[i]])
                return false;
            ss[s[i]] = i + 1;
            tt[t[i]] = i + 1;
        }
        return true;
    }
};

void _main()
{
    Solution sol;
    string a = "abba";
    string b = "cdda";
    // b = "cbb";
    bool res = sol.isIsomorphic(a, b);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}