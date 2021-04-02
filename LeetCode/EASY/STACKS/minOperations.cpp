
/*
 * https://leetcode.com/problems/crawler-log-folder/
 * 1598. Crawler Log Folder
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        stack<string> st;
        if (logs[0] != "./" && logs[0] != "../")
            st.push(logs[0]);

        for (int i = 1; i < logs.size(); i++)
        {
            if (logs[i] == "../" && !st.empty())
                st.pop();
            else if (logs[i] != "./" && logs[i] != "../")
                st.push(logs[i]);
        }
        return st.size();
    }
};

void _main()
{
    Solution sol;
    vector<string> logs = {"d1/", "d2/", "../", "d21/", "./"};
    int res = sol.minOperations(logs);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}