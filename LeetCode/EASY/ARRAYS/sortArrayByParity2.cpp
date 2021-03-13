/**
 * https://leetcode.com/problems/sort-array-by-parity-ii/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        vector<int> b(A.size());
        int j = 0;
        for (int i : A)
        {
            if (i % 2 == 0)
            {
                b[j] = i;
                j += 2;
            }
        }
        j = 1;
        for (int k : A)
        {
            if (k % 2 != 0)
            {
                b[j] = k;
                j += 2;
            }
        }
        return b;
    }

    //Another approach
    vector<int> sortArrayByParityII_1(vector<int> &A)
    {
        int j = 1;
        int tmp = 0;
        for (int i = 0; i < A.size(); i += 2)
        {
            if (A[i] % 2 != 0)
            {
                while (A[j] % 2 != 0)
                    j += 2;

                tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
        return A;
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {4, 2, 5, 7};
    a = {1, 3, 4, 2};

    vector<int> res = sol.sortArrayByParityII_1(a);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}