/**
 * https://leetcode.com/problems/monotonic-array/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Its failing for equals to
    bool isMonotonic1(vector<int> &A)
    {
        int c = 0;
        if (A.size() <= 2)
            return true;
        if (A[0] >= A[1])
        {
            for (int i = 1; i < A.size(); i++)
            {
                if (A[i - 1] != A[i] && A[i - 1] - A[i] < 0)
                    return false;
            }
        }
        else if (A[0] <= A[1])
        {
            for (int i = 1; i < A.size(); i++)
            {
                if (A[i - 1] != A[i] && A[i - 1] - A[i] > 0)
                    return false;
            }
        }

        return true;
    }

    bool isMonotonic(vector<int> &A)
    {
        bool inc = true;
        bool dec = true;

        for (int i = 1; i < A.size(); i++)
        {
            if (A[i - 1] > A[i])
                inc = false;
            if (A[i - 1] < A[i])
                dec = false;
        }
        return inc || dec;
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {1, 1, 2};

    bool res = sol.isMonotonic(a);
    // for (int i : res)
    //     cout << i << " ";
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}