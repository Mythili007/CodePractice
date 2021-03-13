/**
 * https://leetcode.com/problems/valid-anagram/
 * Valid Anagram
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> ums;
        unordered_map<char, int> umt;
        for (char ch : s)
            ums[ch]++;

        for (char ch : t)
            umt[ch]++;

        for (auto ch : umt)
        {
            if (ums.find(ch.first) == ums.end() || ums[ch.first] != ch.second)
                return false;
        }

        return true;
    }
};

void _main()
{
    Solution sol;
    string s = "anagram", t = "nagaram";
    s = "aacc", t = "ccac";
    bool res = sol.isAnagram(s, t);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}