/*
 * https://leetcode.com/problems/count-sorted-vowel-strings/
 * 1641. Count Sorted Vowel Strings
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countVowelStrings(int n)
    {
        int dp[n + 1][5];
        for (int i = 0; i < 5; i++)
            dp[0][i] = 1;

        for (int i = 1; i <= n; i++)
        {
            int sum = 0;
            for (int j = 4; j >= 0; j--)
            {
                sum += dp[i - 1][j];
                dp[i][j] = sum;
            }
        }
        return dp[n][0];
    }
};

void _main()
{
    Solution sol;
    int n = 5;
    cout << sol.countVowelStrings(n) << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}