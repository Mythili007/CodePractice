/**
 * https://leetcode.com/problems/remove-outermost-parentheses/
 * 1021. Remove Outermost Parentheses
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        for(int i = 1;i<s.size();i++){
            if(s[i-1] == '(' && s[i] == ')'){
                st.push(s[i]);
                st.push(s[i-1]);
            }
        }
        string res;
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            res+=ch;
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
    cout<<res<<endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}