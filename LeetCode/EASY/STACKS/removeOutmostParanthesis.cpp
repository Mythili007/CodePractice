/*
 * https://leetcode.com/problems/remove-outermost-parentheses/
 * 1021. Remove Outermost Parentheses
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int opened = 0;
        string res;
        for (char ch : s)
        {
            if (ch == '(' && opened++ > 0)
                res += ch;
            if (ch == ')' && opened-- > 1)
                res += ch;
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    string s = "(()())(())";
    s = "(()())(())(()(()))";
    string res = sol.removeOuterParentheses(s);
    cout << res << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}