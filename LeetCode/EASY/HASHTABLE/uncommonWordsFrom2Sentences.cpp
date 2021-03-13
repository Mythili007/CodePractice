/**
 * https://leetcode.com/problems/uncommon-words-from-two-sentences/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> uncommonFromSentences(string A, string B)
    {
        unordered_map<string, int> m1;
        string res, C = A + ' ' + B;

        vector<string> v;
        for (auto st : C)
        {
            if (st == ' ')
            {
                v.push_back(res);
                res = "";
            }
            else
            {
                res += st;
            }
        }
        v.push_back(res);
        for (int i = 0; i < v.size(); i++)
            m1[v[i]]++;
        v = {};
        // cout << "first:" << i.first << "    second: " << i.second << endl;
        for (auto i : m1)
            if (i.second == 1)
                v.push_back(i.first);
        return v;
    }
};

void _main()
{
    Solution sol;
    string A = "this apple is sweet", B = "this apple is sour";
    vector<string> res = sol.uncommonFromSentences(A, B);
    for (string i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}