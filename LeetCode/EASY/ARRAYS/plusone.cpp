/**
 * https://leetcode.com/problems/plus-one/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &A)
    {
        reverse(A.begin(), A.end());//1 2 0 0 ==> 0 0 2 1
        K = 1;
        for (int i = 0; i < A.size(); i++)
        {
            A[i] += K;//34
            K = A[i] / 10;
            A[i] = A[i] % 10;
        }

        while (K)
        {
            A.push_back(K % 10);
            K = K / 10;
        }

        reverse(A.begin(), A.end());
        return A;
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {1, 2, 3, 9};

    vector<int> res = sol.plusOne(a);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}