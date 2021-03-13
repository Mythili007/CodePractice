/**
 * https://leetcode.com/problems/reverse-string/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
//This is done with the help of solution given and is done in JAVA
    void reverseString(vector<char> &s)
    {
        int len = sizeof(s) / sizeof(char *);
        for (int i = len - 1; i >= 0; i--)
            cout << i << " ";
    }
};

void _main()
{
    Solution sol;
    vector<char> a = {"b", "e", "l", "l", "a"};
    sol.reverseString(a);
    /* vector<string> res = sol.commonChars(a);
    for (int i : res)
        cout << i << " "; */
    cout << endl;
}

int main()
{
    _main();
    return 0;
}