/*
 * https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3710/
 * Remove All Adjacent Duplicates in String II
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void markIndexes(string st, int index, vector<bool> &mark)
    {
        mark[index] = mark[index - 1] = mark[index - 2] = 1;
    }

    string remove_dup(string st, int k, vector<bool> &mark)
    {
        string res;
        int cnt = 1;
        for (int i = 1; i < st.size(); i++)
        {
            if (st[i] == st[i - 1])
            {
                cnt++;
                if (cnt == k)
                    markIndexes(st, i, mark);
            }
            else
                cnt = 1;
        }
        for (int i = 0; i < st.size(); i++)
        {
            if (mark[i] == 0)
                res += st[i];
        }
        mark = {};
        // for(int i = 0;i<res.size();i++)
        // mark(res.size(), 0);
        return res;
    }

    bool isStringCleanedUp(string st, int k)
    {
        int cnt = 1;
        for (int i = 1; i < st.size(); i++)
        {
            if (st[i] == st[i - 1])
            {
                cnt++;
                if (cnt == k)
                    return false;
            }
            else
                cnt = 1;
        }
        return true;
    }

    string removeDuplicates(string s, int k)
    {
        /* vector<bool> mark(s.size(), 0);

        while (true)
        {
            string res = remove_dup(s, k, mark);
            if (isStringCleanedUp(res, k))
                return res;
            else
                remove_dup(res, k, mark);
        } */

        vector<int> cnt(s.size(), 1);
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            s[j] = s[i];
            if (j > 0 && s[j] == s[j - 1])
                cnt[j] = cnt[j - 1] + 1;
            else
                cnt[j] = 1;
            if (cnt[j] == k)
                j -= k;
            j++;
        }
        return s.substr(0, j);
    }
};

void _main()
{
    Solution sol;
    string st = "deeedbbcccbdaa";
    int k = 3;
    cout << sol.removeDuplicates(st, k);
    cout << endl;
}

int main()
{
    _main();
    return 0;
}