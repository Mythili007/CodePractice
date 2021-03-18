
/*
 * https://leetcode.com/problems/defanging-an-ip-address/
 * 1108. Defanging an IP Address
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string defangIPaddr(string address)
    {
        string res;
        string ss = "[.]";
        for (int i = 0; i < address.size(); i++)
        {
            if (address[i] == '.')
                res += ss;
            else
                res += address[i];
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    string address = "1.1.1.1";
    string res = sol.defangIPaddr(address);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}