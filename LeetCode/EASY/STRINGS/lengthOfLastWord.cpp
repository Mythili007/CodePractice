/**
 * https://leetcode.com/problems/length-of-last-word/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s == "" || s == " ")
            return 0;

        vector<string> v;
        stringstream st(s);
        string res;

        while (getline(st, res, ' '))
            v.push_back(res);
        string len = "";
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (v[i] != "")
            {
                len += v[i];
                break;
            }
        }

        return len.length();
    }
};

void _main()
{
    Solution sol;
    string command = "Hello World";
    command = " ";
    command = "b   a    ";
    int res = sol.lengthOfLastWord(command);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}