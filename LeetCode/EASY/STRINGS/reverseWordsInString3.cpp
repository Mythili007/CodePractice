/**
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
//solved it in JS
    string reverseWords(string s)
    {
        string res = "";
        for (int i = 0; i < s.size(); i+=)
        {
            while(s[i]!=' '){

            }
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    string s = "abc def";
    string res = sol.reverseWords(s);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}