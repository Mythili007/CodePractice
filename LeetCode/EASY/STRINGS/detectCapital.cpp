/**
 * https://leetcode.com/problems/detect-capital/
 * 520. Detect Capital
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        //Either all are capital or all are small or only first letter capital
        int ucount = 0, lcount = 0;
        bool firstChar = false;
        for (int i = 0; i < word.size(); i++)
        {
            if (isupper(word[i]))
                ucount++;
            else if (islower(word[i]))
                lcount++;
        }
        if (ucount == word.size() || lcount == word.size())
            return true;
        else if (isupper(word[0]) && lcount == word.size() - 1)
            return true;

        return false;
    }
};

void _main()
{
    Solution sol;
    string word = "Google";
    word = "USA";
    word = "FlaG";
    word = "AmAzON";
    word = "ggh";
    // num1 = "0", num2 = "0";
    // num1 = "6913259244", num2 = "71103343";
    bool res = sol.detectCapitalUse(word);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}