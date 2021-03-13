/**
 * https://leetcode.com/problems/find-common-characters/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // SOLUTION FROM MOST VOTED SUBMISSIONS
    vector<string> commonChars(vector<string> &A)
    {
        vector<string> res;
        vector<int> cnt(26, INT_MAX);

        for (auto a : A)
        {
            vector<int> cnt1(26, 0);
            for (auto b : a)
                ++cnt1[b - 'a'];

            for (auto j = 0; j < 26; j++)
                cnt[j] = min(cnt[j], cnt1[j]);
        }

        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < cnt[i]; j++)
            {
                res.push_back(string(1, i + 'a'));
            }
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    vector<string> a = {"bella", "label", "roller"};

    vector<string> res = sol.commonChars(a);
    for (string i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}