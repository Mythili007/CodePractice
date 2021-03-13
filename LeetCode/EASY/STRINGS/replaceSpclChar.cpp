
/**
 * https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/
 * 1576. Replace All ?'s to Avoid Consecutive Repeating Characters
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string modifyString(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            int __ascii = 34;
            if (i == 0)
            {
                if (s[i] == '?')
                {
                    if (((int)s[i] + __ascii) == (int)s[i + 1])
                        __ascii = __ascii + 1;
                    s[i] = char((int)s[i] + __ascii);
                    cout << "ch1: " << s[i] << endl;
                }
            }
            else
            {
                if (s[i] == '?')
                {
                    if ((int)s[i] + __ascii == (int)s[i - 1])
                        __ascii++;

                    if ((int)s[i] + __ascii == (int)s[i + 1])
                        __ascii++;

                    char ch = char((int)s[i] + __ascii);
                    if (ch == s[i - 1] || ch == s[i + 1])
                        __ascii++;
                    s[i] = char((int)s[i] + __ascii);
                    //(char((int)s[i] + __ascii) != s[i-1] || s[i+1]) ? char((int)s[i] + __ascii) : char((int)s[i] + (++__ascii));
                    cout << "ch2: " << s[i] << endl;
                }
            }
        }
        return s;
    }
};

void _main()
{
    Solution sol;
    string st = "?zs";
    st = "ubv?w";
    st = "j?qg??b";
    st = "??yw?ipkj?";
    st = "b?a";
    st = "a?b";
    string res = sol.modifyString(st);
    cout << res << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}