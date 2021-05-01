/**
 * https://leetcode.com/problems/maximum-product-of-three-numbers/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string replaceDigits(string s)
    {
        for (int i = 1; i < s.size(); i++)
        {
            if (i % 2 != 0)
            {
                s[i] = char((int)s[i - 1] + (s[i] - 48));
            }
        }
        return s;
    }
};

void _main()
{
    Solution sol;
    string s = "a1c1e1";
    s = "a1b2c3d4e";
    cout << sol.replaceDigits(s) << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}