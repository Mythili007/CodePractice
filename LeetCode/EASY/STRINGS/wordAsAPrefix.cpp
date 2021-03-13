/**
 * https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
 * 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //ACCEPTED SOLUTION
    int isPrefixOfWord1(string sentence, string searchWord)
    {
        stringstream ss(sentence);
        string res;
        vector<string> v;
        while (getline(ss, res, ' '))
            v.push_back(res);
        int wordSize = searchWord.size(), cnt = 0;
        for (int i = 0; i < v.size(); i++)
        {
            string s = v[i];
            if (s.size() >= wordSize)
            { //burger, burg
                cout << s << endl;
                cnt = 0;
                for (int j = 0; j < wordSize; j++)
                {
                    if (s[j] != searchWord[j])
                        break;
                    else
                        cnt++;
                }
                if (cnt == wordSize)
                    return i + 1;
            }
        }
        return -1;
    }
    //Not accepted
    int isPrefixOfWord(string sentence, string searchWord)
    {
        int j = 0, k = 0;
        for (int i = 0; i < sentence.size(); i++)
        {
            if (sentence[i] == ' '){
                j++;
                k = 0;
            }
            if (sentence[i] == searchWord[k])
                k++;
            if (k == searchWord.size())
                return j+1;
        }
        return -1;
    }
};

void _main()
{
    Solution sol;
    string sentence = "i love eating burger", searchWord = "burg";
    // sentence = "this problem is an easy problem", searchWord = "pro";
    // sentence = "dumb dream duck duck i", searchWord = "drea";
    sentence = "hellohello hellohellohello", searchWord = "ell";

    int res = sol.isPrefixOfWord(sentence, searchWord);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}