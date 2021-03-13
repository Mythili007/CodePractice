/**
 * https://leetcode.com/problems/first-bad-version/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstBadVersion1(int n)
    {
        for (int i = 1; i < n; i++)
        {
            if (isBadVersion(i))
                return i;
        }

        return n;
    }
    //Binary version approach
    int firstBadVersion(int n)
    {
        int left = 1;
        int right = n;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (isBadVersion())
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

void _main()
{
    Solution sol;
    int b = 4;
    int res = sol.firstBadVersion(b);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}