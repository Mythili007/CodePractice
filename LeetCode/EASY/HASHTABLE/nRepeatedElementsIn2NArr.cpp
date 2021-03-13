/**
 * https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int repeatedNTimes(vector<int> &A)
    {
        int n = A.size() / 2, res = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < A.size(); i++)
        {
            m[A[i]]++;
        }
        for (auto num : m)
        {
            if (num.second == n)
            {
                res = num.first;
                break;
            }
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    vector<int> A = {1,2,3,3};
    A = {5,1,5,2,5,3,5,4};
    int res = sol.repeatedNTimes(A);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}