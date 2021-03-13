/**
 * https://leetcode.com/problems/make-the-string-great/
 * 
  */

#include <bits/stdc++.h>
#include <cctype>
using namespace std;

class Solution
{
public:
    bool removeAdjChar(string s)
    {
        bool isUpperCaseExist = true;
        while (isUpperCaseExist)
        {
            for (int i = 0; i < s.size()-3;)
            {
                cout<<"s[i]: "<<s[i]<<endl;
                if (s[i] == (s[i + 1] + 32))
                {
                    s.erase(i);
                    s.erase(i + 1);
                    i += 2;
                    // cout<<"i: "<<i<<endl;
                }
                i++;
                if (s[i] == s[i] - 32)
                    isUpperCaseExist = true;
                else
                    isUpperCaseExist = false;
            }
        }
        //abBAcC
        return isUpperCaseExist;
    }
    string makeGood(string s)
    {
        bool res = removeAdjChar(s);
        cout<<"res: "<<res<<endl;
        return s;
    }
};

void _main()
{
    Solution sol;
    string a = "leEeetcode";
    a = "abBAcC";
    string res = sol.makeGood(a);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}