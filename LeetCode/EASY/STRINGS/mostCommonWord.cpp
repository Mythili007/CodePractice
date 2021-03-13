/**
 * https://leetcode.com/problems/most-common-word/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        unordered_map<string, int> mp;
        int n = paragraph.size();
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        string res;
        for (int i = 0; i < n; i++)
        {
            if (paragraph[i] >= 97 && paragraph[i] <= 122 || paragraph[i] == ' ')
            {
                res += paragraph[i];
            }
            else
            {
                res += ' ';
            }
        }
        stringstream ss(res);
        string s;
        while (getline(ss, s, ' '))
        {
            mp[s]++;
        }

        // cout << "first: " << i.first << "  second: " << i.second << endl;
        for (int j = 0; j < banned.size(); j++)
        {
            mp.erase(banned[j]);
        }
        int max = INT_MIN;
        string word;
        for (auto i : mp)
        {
            cout << "aaa" << endl;
            if (i.first != "" && i.second > max)
            {
                max = i.second;
                word = i.first;
            }
        }
        return word;
    };
};

void _main()
{
    Solution sol;
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    paragraph = "a, a, a, a, b,b,b,c, c";

    vector<string> banned = {"hit"};
    banned = {"a"};

    paragraph = "abc abc? abcd the jeff!";
    banned = {"abc", "abcd", "jeff"};
    string res = sol.mostCommonWord(paragraph, banned);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}