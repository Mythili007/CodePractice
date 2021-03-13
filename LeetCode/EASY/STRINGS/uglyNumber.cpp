/**
 * https://leetcode.com/problems/ugly-number/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isUgly(int num)
    {
        if (num > 0)
        {
            for (int i = 2; i < 6; i++)
            {
                while (num % i == 0)
                {
                    num = num / i;
                }
            }
        }
        return num == 1;
    }
};

void _main()
{
    Solution sol;
    int a = 10;
    a = 8;
    a = 6;
    int res = sol.isUgly(a);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}