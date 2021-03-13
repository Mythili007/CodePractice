/**
 * https://leetcode.com/problems/valid-perfect-square/
 * 367. Valid Perfect Square
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int right = nums.size() - 1;
        int left = 0;
        while (left < right)
        {
            int mid = (right + left-1) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }

    bool isPerfectSquare(int num)
    {
        long right = num, left = 1;
        while (left <= right)
        {
            long mid = left + (right - left) / 2;
            if (mid * mid == num)
                return true;
            else if (mid * mid > num)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};

void _main()
{
    Solution sol;
    int num = 16;
    num = 4;
    num = 2000105819;
    bool res = sol.isPerfectSquare(num);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}