/**
 * https://leetcode.com/problems/count-binary-substrings/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        // 00110
        int prv = 0, crnt = 1, cnt = 0, i = 0;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] != s[i + 1])
            {
                prv = crnt;
                crnt = 1;
                cnt++;
            }
            else
            {
                crnt++;
                if (crnt <= prv)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

void _main()
{
    Solution sol;
    string s = "00110011";
    // s = "10101";
    // s = "00100";
    // s = "010011";
    // s = "01";
    // s= "00110";
    int res = sol.countBinarySubstrings(s);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}