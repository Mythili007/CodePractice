/**
 * https://leetcode.com/problems/find-the-difference/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char findTheDifference1(string s, string t)
    {
        char res;
        int flag = -1;
        unordered_map<char, int> m_t;
        unordered_map<char, int> m_s;
        for (int i = 0; i < s.size(); i++)
            m_s[s[i]]++;

        for (int i = 0; i < t.size(); i++)
            m_t[t[i]]++;
        for (auto ch : m_t)
        {
            if (m_s.find(ch.first) == m_s.end())
                res = ch.first;

            else if (m_s[ch.first] != m_t[ch.first])
                res = ch.first;
        }
        return res;
    }
    // CHECKING THROUGH ASCII VALUES
    char findTheDifference(string s, string t)
    {
        int charCodeS = 0, charCodeT = 0;
        for (int i = 0; i < s.size(); i++)
            charCodeS += (int)s[i];
        for (int i = 0; i < t.size(); i++)
            charCodeT += (int)t[i];
        return (char)(charCodeT - charCodeS);
    }
};

void _main()
{
    Solution sol;
    string s = "abc";
    string t = "abcd";
    // s = "", t = "y";
    // s = "a", t = "aa";
    char res = sol.findTheDifference(s, t);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}