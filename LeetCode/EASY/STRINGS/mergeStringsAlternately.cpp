
/*
 * https://leetcode.com/problems/merge-strings-alternately/
 * 1768. Merge Strings Alternately
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string res;
        if (word1.size() < word2.size())
        {
            int j = 0;
            for (int i = 0; i < word1.size(); i++)
            {
                res += word1[i];
                res += word2[j];
                ++j;
            }
            for (int i = j; i < word2.size(); i++)
                res += word2[i];
        }
        else
        {
            int j = 0;
            for (int i = 0; i < word2.size(); i++)
            {
                res += word1[i];
                res += word2[j];
                ++j;
            }
            for (int i = j; i < word1.size(); i++)
                res += word1[i];
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    string word1 = "abc", word2 = "pqr";
    string res = sol.mergeAlternately(word1, word2);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}