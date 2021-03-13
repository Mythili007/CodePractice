/**
 * https://leetcode.com/problems/add-to-array-form-of-integer/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //data type error
    vector<int> addToArrayForm1(vector<int> &A, int K)
    {
        int n = A[0];
        vector<int> b;
        vector<int> c;
        for (int i = 1; i < A.size(); i++)
        {
            n = n * 10 + A[i];
        }
        n = n + K;
        int rem = 0;
        while (n > 0)
        {
            rem = n % 10;
            b.push_back(rem);
            n = n / 10;
        }
        for (int i = b.size() - 1; i >= 0; i--)
        {
            c.push_back(b[i]);
        }
        return c;
    }

    vector<int> addToArrayForm(vector<int> &A, int K)
    {
        reverse(A.begin(), A.end());//1 2 0 0 ==> 0 0 2 1
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
    int k = 34;

    vector<int> res = sol.addToArrayForm(a, k);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}