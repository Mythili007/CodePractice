/**
 * https://leetcode.com/problems/fibonacci-number/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fib1(int n)
    {
        if (n <= 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
    //top down approach
    int fib(int n)
    {
        if (n <= 1)
            return n;
        if (n == 2)
            return 1;

        int crnt = 0;
        int p1 = 0;
        int p2 = 0;

        for (int i = 3; i <= n; i++)
        {
            crnt = p1 + p2;
            p2 = p1;
            p1 = crnt;
        }
        return crnt;
    }
};

void _main()
{
    Solution sol;
    int n = 6;

    int res = sol.fib(n);
    // for (int i : res)
    //     cout << i << " ";
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}