/**
 * https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> res;
        for (int i = n / 2; i > 0; i--)
        {
            res.push_back(i);
            res.push_back(-1 * i);
        }

        if (n % 2 != 0)
            res.push_back(0);
        return res;
    }
};

void _main()
{
    Solution sol;
    int n = 5;
    vector<int> res = sol.sumZero(n);

    for (int _v : res)
    {
        cout << _v << " ";
    }
}

int main()
{
    _main();
    return 0;
}