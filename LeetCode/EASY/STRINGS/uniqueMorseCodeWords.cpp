/**
 * https://leetcode.com/problems/unique-morse-code-words/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniqueMorseRepresentations1(vector<string> &words)
    {
        unordered_map<char, string> m;
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        vector<string> morseCodes = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        vector<string> v;
        unordered_set<string> uset;
        string res;
        for (int i = 0; i < 26; i++)
            m[alpha[i]] = morseCodes[i];

        //words = ["gin", "zen", "gig", "msg"]
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            res = "";
            for (int j = 0; j < word.size(); j++)
            {
                if (m.find(word[j]) != m.end())
                {
                    res += m[word[j]];
                }
            }
            uset.insert(res);
            // v.push_back(res);
        }
        // vector<string> rr;
        // for (int i = 0; i < v.size(); i++)

        return uset.size();
    }
    //OPTIMISED SOLUTION TO THE ABOVE APPROACH
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> morseCodes = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> uset;
        for (auto word : words)
        {
            string res;
            for (auto ch : word)
            {
                res += morseCodes[ch - 'a'];
            }
            uset.insert(res);
        }
        return uset.size();
    }
};

void _main()
{
    Solution sol;
    vector<string> words = {"gin", "zen", "gig", "msg"};
    int res = sol.uniqueMorseRepresentations(words);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}