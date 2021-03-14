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
    bool hasAllCodes(string s, int k)
    {
        //1 length binary codes: 0, 1
        //2 length binary codes: 00, 01, 10, 11
        //3 length binary codes: 000, 001, 010, 100, 111, 110, 101, 011
        //4 length binary codes: 0000, 1111
        int check = 1 << k;
        set<string> ss;
        for (int i = k; i < s.length(); i++)
        {
            string st = s.substr(i - k, i);
            if (ss.find(st) == ss.end())
            {
                ss.insert(st);
                check--;
                if (check == 0)
                    return true;
            }
        }
        return false;
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