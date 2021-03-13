/**
 * https://leetcode.com/problems/rearrange-spaces-between-words/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reorderSpaces(string text)
    {
        string word;
        int spCount = 0, wordCount = 0;
        vector<string> v;
        for (int i = 0; i < text.size(); i++)
        {
            if (text[i] == ' ')
            {
                spCount++;
                if (word != "")
                {
                    v.push_back(word);
                }
                word = "";
            }
            else
            {
                word += text[i];
            }
        }
        if (word != "")
            v.push_back(word);
        if (v.size() == 1)
        {
            while (spCount--)
            {
                v[0] += ' ';
            }
        }

        int m = spCount / (v.size() - 1), n = spCount % (v.size() - 1);
        string str, rs;
        for (int i = 0; i < v.size(); i++)
        {
            int k = m;
            rs = "";
            rs += v[i];
            while (k > 0)
            {
                rs += ' ';
                k--;
            }
            // cout << "rs: " << rs << endl;
            str += rs;
        }
        // return str + string(n, ' ');
        return str.substr(0, str.size() - m) + string(n, ' ');
    }
};

void _main()
{
    Solution sol;
    string text = "  this   is  a sentence ";
    text = " practice   makes   perfect";
    text = "  walks  udp package   into  bar a";
    // s = "leetcode";
    // s = "loveleetcode";
    // s = "aA";
    string res = sol.reorderSpaces(text);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}