/**
 * https://leetcode.com/problems/keyboard-row/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        string firstRow = "qwertyuiopQWERTYUIOP", secondRow = "asdfghjklASDFGHJKL", thirdRow = "zxcvbnmZXCVBNM";
        vector<string> v;
        int f = 0, s = 0, t = 0, k = 0;
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            f = 0, s = 0, t = 0;
            for (int j = 0; j < word.size(); j++)
            {
                for (int k = 0; k < firstRow.size(); k++)
                {
                    if (word[j] == firstRow[k])
                        f++;
                }
                if (f == word.size())
                    v.push_back(word);
                for (int k = 0; k < secondRow.size(); k++)
                {
                    if (word[j] == secondRow[k])
                        s++;
                }
                if (s == word.size())
                    v.push_back(word);
                for (int k = 0; k < thirdRow.size(); k++)
                {
                    if (word[j] == thirdRow[k])
                        t++;
                }
                if (t == word.size())
                    v.push_back(word);
            }
        }
        return v;
    }
};

void _main()
{
    Solution sol;
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
    words = {"okm"};
    words = {"adsdf","sfd"};
    // A = {1, 2, 2, 1}, B = {2, 2};
    vector<string> res = sol.findWords(words);
    for (string i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}