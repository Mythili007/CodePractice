
/**
 * https://leetcode.com/problems/reformat-the-string/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reformat(string s)
    {
        string res = "";
        int digCnt = 0, letCnt = 0;
        vector<char> ch;
        vector<int> dg;

        if (s.size() == 1)
            return s;

        for (int i : s)
        {
            if (i >= 97 && i <= 122)
            {
                letCnt++;
                ch.push_back(i);
            }
            else if (i >= 48 && i <= 57)
            {
                digCnt++;
                dg.push_back(i);
            }
        }

        cout << "letters: " << letCnt << "  char: " << digCnt << endl;

        if (letCnt == 0 || digCnt == 0)
            return res;

        if ((letCnt > digCnt && (letCnt == digCnt + 1)) || (letCnt == digCnt))
        {
            int j = 0, k = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (i % 2 == 0)
                {
                    res += ch[j];
                    j++;
                }
                else
                {
                    res += dg[k];
                    k++;
                }
            }
        }
        else if (letCnt < digCnt && (letCnt == digCnt - 1))
        {
            int j = 0, k = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (i % 2 == 0)
                {
                    res += dg[j];
                    j++;
                }
                else
                {
                    res += ch[k];
                    k++;
                }
            }
        }
        else
        {
            return res;
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    string s = "a0b1c2";
    s = "leetcode";
    // s = "l";
    string res = sol.reformat(s);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}