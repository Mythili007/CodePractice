/*
 * https://leetcode.com/problems/score-of-parentheses/
 * 856. Score of Parentheses

 * cur record the score at the current layer level.
 *   If we meet '(', we push the current score to stack, enter the next inner layer level, and reset cur = 0.

 *  If we meet ')',the cur score will be doubled and will be at least 1.
 *   We exit the current layer level, and set cur += stack.pop() + cur
 *   Complexity: O(N) time and O(N) space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int scoreOfParentheses(string S)
    {
        stack<int> st;
        int cur = 0;
        for (char ch : S)
        {
            if (ch == '(')
            {
                st.push(cur);
                cur = 0;
            }
            else
            {
                cur += st.top() + max(cur, 1);
                st.pop();
            }
        }
        return cur;
    }
};

void _main()
{
    Solution sol;
    string s = "(()(()))";
    cout << sol.scoreOfParentheses(s);
    cout << endl;
}

int main()
{
    _main();
    return 0;
}