/**
 * https://leetcode.com/problems/fair-candy-swap/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
    {
        vector<int> c;
        int m = A.size();
        int n = B.size();
        int total_A = 0;
        int total_B = 0;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int minA = A[0];
        int maxA = A[m - 1];

        int minB = B[0];
        int maxB = B[n - 1];

        for (int i = 0; i < m; i++)
            total_A += A[i];

        for (int i = 0; i < n; i++)
            total_B += B[i];

        if (total_A % 2 != 0 && total_B % 2 != 0)
        {
            c.push_back(minA);
            c.push_back(minB);
        }

        if (total_A % 2 == 0 && total_B % 2 == 0)
        {
            c.push_back(maxA);
            c.push_back(maxB);
        }

        return c;
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {1, 2, 5};
    vector<int> b = {2, 4};
    // nums = {0,0,1,1,1,2,2,3,3,4};
    // nums = {3, 2, 3};

    vector<int> res = sol.fairCandySwap(a, b);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}