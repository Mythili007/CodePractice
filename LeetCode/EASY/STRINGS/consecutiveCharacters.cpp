/**
 * https://leetcode.com/problems/consecutive-characters/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //TIME LIMIT EXCEEDED
    int maxPower1(string s)
    {
        vector<string> st;
        string res = "";
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i + 1; j < s.length(); j++)
            {
                res = "";
                for (int k = i; k <= j; k++)
                {
                    res += s[k];
                }
                st.push_back(res);
            }
        }
        int m = 1;
        for (string word : st)
        {
            char firstChar = word[0];
            int cnt = 0;
            for (char c : word)
            {
                if (c != firstChar)
                    break;
                cnt++;
            }
            if (cnt == word.length())
                m = max(m, cnt);
        }

        return m;
    }

    //We need longest substring with all common char
    int maxPower(string s)
    {
        int cnt = 0;
        int m = 0;

        char prev = ' ';

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[0];
            if (c == prev)
            {
                cnt++;
            }
            else
            {
                cnt = 1;
                prev = c;
            }
            m = max(m, cnt);
        }
        return m;
    }
};

void _main()
{
    Solution sol;
    string s = "leetcode";
    s = "abbcccddddeeeeedcba";
    s = "hooraaaaaaaaaaay";
    s = "tourist";
    s = "uufeeqckthvgnrypadofsbgwolaiarlzdqwqijitybovzgdrpyroyeddtzohintrchtxyvbsxnnctkbjusawfrkphybysdtaaowpirgcrkgmypuezimowmhwtbglcbskwtuvbpycvqmmknfdiefekrkqwytncsjzdxsxaaqufeswdyvauywyummucsklrxbxsvrrbrwxdcjaztvctsdsnaigkewojnztvsvfxgabgg";
    int res = sol.maxPower(s);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}