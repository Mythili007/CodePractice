/**
 * https://leetcode.com/problems/student-attendance-record-i/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkRecord(string s)
    {
        int cnt_A = 0, cnt_L = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'A')
                cnt_A++;
            else if (s[i] == 'L' && s[i + 1] == 'L') //ALLL
                cnt_L++;
            else
                cnt_L = 0;
            if (cnt_A > 1 || cnt_L > 1)
                return false;
        }
        return true;
    }
};

void _main()
{
    Solution sol;
    string s = "PPALLP";
    s = "PPALLL";
    // s = "LLPPPLL";
    // s = "aA";
    bool res = sol.checkRecord(s);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}