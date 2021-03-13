/**
 * https://leetcode.com/problems/maximum-score-after-splitting-a-string/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore1(string s)
    {
        int zerosCount = 0, onesCount = 0, m = INT_MIN;
        if (s.size() == 2 && (s[0] == '0' && s[1] == '0'))
            return 1;
        for (int i = 0; i < s.size(); i++)
        {
            zerosCount = 0, onesCount = 0;
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[j] == '1')
                    onesCount++;
            }
            for (int k = 0; k <= i; k++)
            {
                if (s[k] == '0')
                    zerosCount++;
            }
            if (onesCount == 0)
                zerosCount = zerosCount - 1;
            m = max(m, (zerosCount + onesCount));
        }
        return m;
    }

    int maxScore(string s)
    {
        int zerosCount = 0, onesCount = 0, m = INT_MIN;
        for (char i : s)
            if (i == '1')
                onesCount++;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                zerosCount++;
            else
                onesCount--;
            m = max(m, (zerosCount + onesCount));
        }
        return m;
    }
};

void _main()
{
    Solution sol;
    string s = "011101";
    s = "00111";
    s = "1111";
    int res = sol.maxScore(s);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}