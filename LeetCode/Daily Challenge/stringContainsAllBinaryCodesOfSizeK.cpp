/*
 * https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3669/
 * Check If a String Contains All Binary Codes of Size K
 */

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

class Solution
{
public:
    vector<string> getSubStringsOfLenK(string s, int k)
    {
        vector<string> res;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 1; j <= s.size() - i; j++)
            {
                string st = s.substr(i, j);
                if (st.size() == k)
                    res.push_back(st);
            }
        }
        return res;
    }

    bool hasAllCodes(string s, int k)
    {
        //1 length binary codes: 0, 1
        //2 length binary codes: 00, 01, 10, 11
        //3 length binary codes: 000, 001, 010, 100, 111, 110, 101, 011
        //4 length binary codes: 0000, 1111
        vector<string> tmp = getSubStringsOfLenK(s, k);
        return (tmp.size() >= pow(2, k)) ? true : false;
    }
};

void _main()
{
    Solution sol;
    string s = "00110110";
    int k = 2;
    cout << sol.hasAllCodes(s, k) << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}