/**
 * https://leetcode.com/problems/reverse-string-ii/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseStr1(string s, int k)
    {
        int len = s.size();
        string res = "";
        for (int i = 0; i < len;)
        {
            if (k > len)
            {
                reverse(s.begin(), s.end());
                break;
            }
            // reverse(s.begin() + i, s.begin() + k);
            reverse(s.begin() + i, s.begin() + i + k);
            i += 2 * k;
        }

        return s;
    }

    string reverseStr(string s, int k)
    {
        int len = s.size();
        for (int i = 0; i < len; i += 2 * k)
        {
            int j = i, l = min(i + k - 1, len - 1);
            while (j < l)
            {
                char tmp = s[j];
                s[j++] = s[l];
                s[l--] = tmp;
            }
        }
        return s;
    }
};

void _main()
{
    Solution sol;
    string s = "abcdefg";
    int k = 2;
    k = 3;
    string res = sol.reverseStr(s, k);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}