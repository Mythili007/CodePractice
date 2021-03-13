/**
 * https://leetcode.com/problems/largest-substring-between-two-equal-characters/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLengthBetweenEqualCharacters1(string s)
    {
        int cnt = 0, mx = INT_MIN;
        for (int i = 0; i < s.size(); i++)
        {
            cnt = 0;
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    mx = max(mx, cnt);
                    // break;
                }
                cnt++;
            }
        }
        return mx;
    }
    // OPTIMISED MINIMAL SOLUTION FROM DISCUSSIONS
    int maxLengthBetweenEqualCharacters(string s)
    {
        int ind[26] = {}, res = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (ind[s[i] - 'a'] == 0)
                ind[s[i] - 'a'] = i + 1;
            res = max(res, i - ind[s[i] - 'a']);
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    string s = "abba";
    s = "cabbacd";
    s = "mgntdygtxrvxjnwksqhxuxtrv";
    int res = sol.maxLengthBetweenEqualCharacters(s);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}