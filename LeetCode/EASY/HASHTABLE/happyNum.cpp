/**
 * https://leetcode.com/problems/happy-number/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_map<int, int> mp;
        while (n != 1)
        {
            if (mp[n] == 0)
                mp[n]++;
            else
                return false;

            int sum = 0;
            while (n > 0)
            {
                sum += pow(n % 10, 2);
                n = n / 10;
            }
            n = sum;
        }
        return true;
    }
};

void _main()
{
    Solution sol;
    int n = 19;
    bool res = sol.isHappy(n);
    cout << res << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}