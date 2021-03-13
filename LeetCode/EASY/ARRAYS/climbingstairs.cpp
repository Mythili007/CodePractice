/**
 * https://leetcode.com/problems/climbing-stairs/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 3)
            return n;

        int crnt = 0;
        int p1 = 3;
        int p2 = 2;

        for (int i = 4; i <= n; i++)
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
    int n = 4;

    int res = sol.climbStairs(n);
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