/**
 * https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string res1 = "";
        string res2 = "";

        for (int i = 0; i < word1.size(); i++)
        {
            res1 += word1[i];
        }

        for (int i = 0; i < word2.size(); i++)
        {
            res2 += word2[i];
        }

        if (res1 == res2)
            return true;
        else
            return false;
    }
};

void _main()
{
    Solution sol;
    vector<string> word1 = {"ab", "c"};
    vector<string> word2 = {"a", "bc"};
    word1 = {"jbboxe", "yshcrtanrtlzyyp", "vudsssnzuef", "lde"}, word2 = {"jbboxeyshcrtanrt", "lzyypvudsssnzueflde"};
    bool res = sol.arrayStringsAreEqual(word1, word2);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}