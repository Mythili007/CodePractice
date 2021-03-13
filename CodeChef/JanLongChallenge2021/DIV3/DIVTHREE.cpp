/**
 * https://leetcode.com/problems/transpose-matrix/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxNumOfDiv3Contests(int N, int K, int D, int a[])
    {
        int sum = 0, res = 0;
        for (int i = 0; i < N; i++)
            sum += a[i];

        res = sum / K;
        if (res > D)
            res = D;
        return res;
    }
};

void _main()
{
    Solution sol;
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int N, K, D;
        cin >> N >> K >> D;
        int a[N];
        for (int i = 0; i < N; i++)
            cin >> a[i];
        int res = sol.maxNumOfDiv3Contests(N, K, D, a);
        cout << res << endl;
    }
}

int main()
{
    _main();
    return 0;
}