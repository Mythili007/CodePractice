/**
 * https://leetcode.com/problems/split-a-string-in-balanced-strings/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int r = 0, l = 0, cnt = 0, i = 0;

        while (i < s.size())
        {
            for (i = 0; i < s.size();)
            {
                if ((s[i] == 'R' && s[i + 1] == 'L') || ((s[i] == 'L' && s[i + 1] == 'R')))
                {
                    cnt++;
                    i += 2;
                }
                else
                {
                    if (s[i] == 'R')
                        r++;
                    else
                        l++;
                    i++;
                    if (l == r)
                    {
                        cnt++;
                        l = 0;
                        r = 0;
                    }
                }
            }
        }
        return cnt;
    }
};

void _main()
{
    Solution sol;
    string s = "RLRRLLRLRL";
    // s = "00111";
    // s = "1111";
    int res = sol.balancedStringSplit(s);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}