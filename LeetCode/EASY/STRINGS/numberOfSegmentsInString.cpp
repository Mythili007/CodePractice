/**
 * https://leetcode.com/problems/number-of-segments-in-a-string/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSegments(string s)
    {
        int cnt = 0, charCnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            charCnt = (s[i] == ' ') ? 0 : charCnt += 1;

            if (charCnt == 1)
                cnt++;
        }
        return cnt;
    }
};

void _main()
{
    Solution sol;
    string s = "abc def";
    s = "my name";
    s = "";
    s = "     ";
    s = "My    name";
    s = "The one-hour drama series Westworld is a dark odyssey about the dawn of artificial consciousness and the evolution of sin. Set at the intersection of the near future and the reimagined past, it explores a world in which every human appetite, no matter how noble or depraved, can be indulged.";
    int res = sol.countSegments(s);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}