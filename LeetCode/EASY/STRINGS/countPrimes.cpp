/**
 * https://leetcode.com/problems/count-primes/
 * 
  */

#include <bits/stdc++.h>
#include <cctype>
using namespace std;

class Solution
{
public:
    // SIEVE OF EROSTHENES
    int countPrimes(int n)
    {
        if (n == 0 || n == 1)
            return 0;
        vector<bool> v(n, true);
        v[0] = v[1] = false;
        for (int j = 2; j < sqrt(n); j++)
        {
            if (v[j])
            {
                for (int i = j * j; i < n; i += j)
                {
                    v[i] = false;
                }
            }
        }
        return count(v.begin(), v.end(), true);
    }
};

void _main()
{
    Solution sol;
    int a = 10;
    a = 0;
    int res = sol.countPrimes(a);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}