/**
 * https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //ACCEPTED SOLUTION
    string freqAlphabets(string s)
    {
        unordered_map<char, string> mp;
        string st = "abcdefghijklmnopqrstuvwxyz", numStr = "", j = "";
        string res = "";
        int k = 1;
        for (int i = 0; i < 26; i++)
        {
            j = to_string(k);
            if (k > 9)
                j += '#';
            mp[st[i]] = j;
            k++;
        }

        for (int i = 0; i < s.length();)
        {
            numStr = "";
            if (i < s.length() - 2 && s[i + 2] == '#')
            {
                numStr += s[i];
                numStr += s[i + 1];
                numStr += '#';
                i = i + 3;
            }
            else
            {
                numStr += s[i];
                i++;
            }

            for (auto m : mp)
            {
                if (m.second == numStr)
                {
                    res += m.first;
                    break;
                }
            }
        }
        return res;
    }

    //SOLUTION FROM DISCUSSIONS - MOST VOTED
    string freqAlphabets_1(string s)
    {
        string res;
        for (int i = 0; i < s.length(); ++i)
        {
            if (i < s.length() - 2 && s[i + 2] == '#')
            {
                res += 'j' + (s[i] - '1') * 10 + (s[i + 1] - '0');
                i += 2;
            }
            else
                res += 'a' + (s[i] - '1');
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    string s = "10#11#12";
    s = "1326#";
    s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#";
    s = "21#523#12#22#611#71910#721#18#8";
    // cout << "len: " << s.length() << endl;
    // string st = "abc";
    // cout << "check: " << (st += 'j') << endl;
    // cout << "check22: " << (st[2] - '1') * 10 << endl;

    // string res = sol.freqAlphabets(s);
    string res = sol.freqAlphabets_1(s);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}