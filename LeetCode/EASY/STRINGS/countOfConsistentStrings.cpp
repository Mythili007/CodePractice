/**
 * https://leetcode.com/problems/count-the-number-of-consistent-strings/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countConsistentStrings1(string allowed, vector<string> &words)
    {
        vector<string> st;
        int flag = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < allowed.length(); j++)
            {
                cout << "words: " << words[i] << endl;
                for (int k = 0; k < words[i].length(); k++)
                {
                    cout << "words[i][j]: " << words[i][j] << endl;
                    if (words[i][k] != allowed[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    break;
                }
                else
                {
                    cout << "words[i]: " << words[i] << endl;
                    st.push_back(words[i]);
                }
            }
        }
        return st.size();
    }

    int countConsistentStrings_accepted(string allowed, vector<string> &words)
    {
        int res = words.size();
        bool alpha[26] = {};

        for (int i : allowed)
            alpha[i - 'a'] = true;

        for (string word : words)
        {
            for (char c : word)
            {
                if (!alpha[c - 'a'])
                {
                    res--;
                    break;
                }
            }
        }
        return res;
    }

    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int res = words.size();
        bool alpha[123] = {};

        for (int i : allowed)
            alpha[i] = true;

        for (string word : words)
        {
            for (char c : word)
            {
                if (!alpha[c])
                {
                    res--;
                    break;
                }
            }
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    string allowed = "ab";
    vector<string> words = {"ad", "bd", "aaab", "baa", "badab"};

    int res = sol.countConsistentStrings(allowed, words);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}