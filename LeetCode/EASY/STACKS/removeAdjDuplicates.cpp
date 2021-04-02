
/*
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
 * 1047. Remove All Adjacent Duplicates In String
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string S)
    {
        stack<char> st;
        st.push(S[0]);
        for (int i = 1; i < S.size(); i++)
        {
            if (st.empty() || st.top() != S[i])
                st.push(S[i]);
            else
            {
                if (st.top() == S[i])
                {
                    st.pop();
                }
            }
        }
        string res;
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

void _main()
{
    Solution sol;
    string word1 = "abbaca";
    string res = sol.removeDuplicates(word1);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}