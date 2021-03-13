/**
 * https://leetcode.com/problems/add-binary/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int p1 = a.size() - 1, p2 = b.size() - 1, carry = 0;
        string resp = "";
        while (p1 >= 0 || p2 >= 0 || carry != 0)
        {
            if (p1 >= 0)
            {
                carry += ((a[p1] == '0') ? 0 : 1);
                p1--;
            }
            cout<<"carry1: "<<carry<<endl;
            if (p2 >= 0)
            {
                carry += ((b[p2] == '0') ? 0 : 1);
                p2--;
            }
            cout<<"carry2: "<<carry<<endl;
            resp = ((carry % 2 == 0) ? "0" : "1") + resp;
            carry = carry / 2;
        }
        return resp;
    }
};

void _main()
{
    Solution sol;
    string a = "11", b = "1";
    // a = "0", b = "0";
    string res = sol.addBinary(a, b);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}