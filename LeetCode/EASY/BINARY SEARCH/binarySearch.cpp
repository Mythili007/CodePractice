/**
 * https://leetcode.com/problems/binary-search/
 * 704. Binary Search
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
};

void _main()
{
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    nums = {5};
    int target = 9;
    target = -5;
    int res = sol.search(nums, target);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}