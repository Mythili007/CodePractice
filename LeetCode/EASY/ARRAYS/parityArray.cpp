/**
 * https://leetcode.com/problems/sort-array-by-parity/
 * 
  */


#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        vector<int> B;
        /* for (int i = 0; i < A.size(); i++)
        {
            for (int j = i + 1; j < A.size(); j++)
            {
                if (A[j] % 2 == 0)
                {
                    swap(A[i], A[j]);
                }
            }
        }
        return A; */

        /* ------- Other way ------ */

        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] % 2 == 0)
            {
                B.push_back(A[i]);
            }
        }
        for (int j = 0; j < A.size(); j++)
        {
            if (A[j] % 2 == 1)
            {
                B.push_back(A[j]);
            }
        }
        return B;
    }
};

void _main()
{
    Solution sol;
    vector<int> A = {3, 4, 1, 2};

    vector<int> res = sol.sortArrayByParity(A);

    for (int _v : res)
    {
        cout << _v << " ";
        // cout << endl;
    }
}

int main()
{
    _main();
    return 0;
}