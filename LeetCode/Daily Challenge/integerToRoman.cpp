/**
 * https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3667/
 * Integer to Roman
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getClosest(int num)
    {
        int closest;
        if (num >= 1000)
            closest = 1000;
        else if (num >= 900)
            closest = 900;
        else if (num >= 500)
            closest = 500;
        else if (num >= 400)
            closest = 400;
        else if (num >= 100)
            closest = 100;
        else if (num >= 90)
            closest = 90;
        else if (num >= 50)
            closest = 50;
        else if (num >= 40)
            closest = 40;
        else if (num >= 10)
            closest = 10;
        else if (num >= 9)
            closest = 9;
        else if (num >= 5)
            closest = 5;
        else if (num >= 4)
            closest = 4;
        else
            closest = 1;
        return closest;
    }
    string intToRoman(int num)
    {
        map<int, string> m;
        m[1] = "I";
        m[5] = "V";
        m[10] = "X";
        m[50] = "L";
        m[100] = "C";
        m[500] = "D";
        m[1000] = "M";

        m[4] = "IV";
        m[9] = "IX";
        m[40] = "XL";
        m[90] = "XC";
        m[400] = "CD";
        m[900] = "CM";
        string res;
        while (num > 0)
        {
            int n = getClosest(num);
            res += m[n];
            num = num - n;
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    int num = 1994;
    num = 100;
    string res = sol.intToRoman(num);
    cout << res << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}