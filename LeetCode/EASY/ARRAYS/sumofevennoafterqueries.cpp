/**
 * https://leetcode.com/problems/sum-of-even-numbers-after-queries/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sumEvenAfterQueries1(vector<int> &A, vector<vector<int>> &queries)
    {
        vector<int> a;
        int val = 0;
        int ind = 0;
        int sum = 0;
        for (int i = 0; i < A.size(); i++)
        {
            val = queries[i][0];
            ind = queries[i][1];
            A[ind] = A[ind] + val;
            sum = 0;
            for (int j = 0; j < A.size(); j++)
            {
                if (A[j] % 2 == 0)
                {
                    sum += A[j];
                }
            }
            a.push_back(sum);
        }
        return a;
    }

    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries)
    {
        int s = 0;
        for (int i : A)
            if (i % 2 == 0)
                s += i;

        vector<int> a;
        for (int i = 0; i < A.size(); i++)
        {
            val = queries[i][0];
            ind = queries[i][1];
            if (A[ind] % 2 == 0)
                s -= A[ind];
            A[ind] += val;
            if (A[ind] % 2 == 0)
                s += A[ind];
            a.push_back(s);
        }
        return a;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> queries = {{1, 0}, {-3, 1}, {-4, 0}, {2, 3}};
    int k = 4;
    // nums = {2,3,3};

    vector<int> res = sol.sumEvenAfterQueries(nums, queries);
    for (int v : res)
        cout << v << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}