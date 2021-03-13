/**
 * https://leetcode.com/problems/binary-prefix-divisible-by-5/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> prefixesDivBy5_1(vector<int> &A)
    {
        long int k = 0;
        long long int sum = 0;
        vector<bool> B; // = {A.size(), false};

        for (int i = 0; i < A.size(); i++)
        {
            k = 0;
            sum = 0;
            for (int j = i; j >= 0; j--)
            {
                if (A[j] == 1)
                    sum += pow(2, k);
                k++;
            }
            if (sum % 5 == 0)
                B.push_back(true);
            else
                B.push_back(false);
        }
        return B;
    }

    vector<bool> prefixesDivBy5(vector<int> &A)
    {
        vector<bool> B;
        int sum =0 ;
        for (int i : A)
        {
            sum = (sum * 2) + i;
            sum = sum % 10;
            B.push_back(sum % 5 == 0);
        }
        return B;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {0, 1, 1, 1, 1, 1};
    nums = {1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1};
    // nums = {1, 0};

    vector<bool> res = sol.prefixesDivBy5(nums);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}