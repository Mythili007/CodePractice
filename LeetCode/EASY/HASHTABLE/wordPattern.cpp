/**
 * https://leetcode.com/problems/word-pattern/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordPattern(string s, string t)
    {
        stringstream ss(t);
        string res;
        vector<string> v;
        while (getline(ss, res, ' '))
            v.push_back(res);

        if(s.size() != v.size()) return false;
        map<char, string> charToWord;
        map<string, char> wordToChar;
        for (int j = 0; j < v.size(); j++)
        {
            char ch = s[j];
            string word = v[j];
            if (charToWord.find(ch) == charToWord.end())
            {
                if (wordToChar.find(word) != wordToChar.end())
                    return false;
                else
                {
                    charToWord[ch] = word;
                    wordToChar[word] = ch;
                }
            }
            else
            {
                string found = charToWord[ch];
                if (found != word)
                    return false;
            }
        }

        return true;
    }
};

void _main()
{
    Solution sol;
    string a = "abba";
    string b = "dog cat cat dog";
    a = "jquery", b = "jquery";
    // b = "cbb";
    bool res = sol.wordPattern(a, b);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}