/**
 * https://leetcode.com/problems/reverse-only-letters/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        vector<char> ch;
        for (int i : s)
        {
            if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
            {
                ch.push_back(i);
            }
        }
        int j = ch.size() - 1;
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
            {
                s[i] = ch[j];
                j--;
            }
        }
        cout << "s: " << s << endl;
        return s;
    }
};

void _main()
{
    Solution sol;
    string s = "a-bC-dEf-ghIj";
    string res = sol.reverseOnlyLetters(s);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}