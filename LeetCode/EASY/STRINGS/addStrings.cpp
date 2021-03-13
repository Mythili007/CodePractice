/**
 * https://leetcode.com/problems/add-strings/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int convertToInt(string n)
    {
        stringstream num(n);
        int a = 0;
        num >> a;
        return a;
    }
    string addStrings1(string num1, string num2)
    {
        string res = "";
        int x = convertToInt(num1);
        int y = convertToInt(num2);
        int sum = x + y;
        res = to_string(sum);
        return res;
    }
    //SOLUTION
    string addStrings(string num1, string num2)
    {
        string res = "";
        int carry = 0;
        int p1 = num1.size() - 1;
        int p2 = num2.size() - 1;

        while (p1 >= 0 || p2 >= 0)
        {
            long sum = 0;
            if (p1 >= 0)
            {
                cout<<"num1[p1] - '0': "<<(num1[p1] - '0')<<endl;
                sum += (num1[p1] - '0');
                p1--;
            }
            if (p2 >= 0)
            {
                sum += (num2[p2] - '0');
                p2--;
            }
            sum += carry;
            carry = sum / 10;
            cout<<"carry: "<<carry<<endl;
            sum = sum % 10;
            res += to_string(sum);
            cout<<"res: "<<res<<endl;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

void _main()
{
    Solution sol;
    string num1 = "11";
    string num2 = "1";
    // num1 = "0", num2 = "0";
    // num1 = "6913259244", num2 = "71103343";
    string res = sol.addStrings(num1, num2);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}