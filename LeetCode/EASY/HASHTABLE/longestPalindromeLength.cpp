/**
 * https://leetcode.com/problems/longest-palindrome/solution/
 * Longest Palindrome
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        if (s.size() == 0)
            return 0;
        set<char> hs;
        for (char ch : s)
        {
            if (hs.find(ch) != hs.end())
                hs.erase(ch);
            else
                hs.insert(ch);
        }

        for(auto it = hs.begin();it!=hs.end();++it)
            cout<<*it<<" ";


        if (hs.size() <= 1)
            return s.size();
        return s.size() - hs.size() + 1;
    }
};

void _main()
{
    Solution sol;
    string s = "abccccdd";
    // s = "aacc", t = "ccac";
    int res = sol.longestPalindrome(s);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}