/*
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * 34. Find First and Last Position of Element in Sorted Array
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // O(n)
    vector<int> searchRange_1(vector<int> &nums, int target)
    {
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                v.push_back(i);
        }
        if (v.size() >= 2)
            return {v[0], v[v.size() - 1]};
        else if (v.size() == 1)
            return {v[0], v[0]};
        else
            return {-1, -1};
    }

    vector<int> search(vector<int> &nums, int left, int right, int target)
    {
        if (nums[left] == target && nums[right] == target)
            return {left, right};
        if (nums[left] <= target && nums[right] >= target)
        {
            int mid = left + right / 2;
            vector<int> ll = search(nums, left, mid, target);
            vector<int> rr = search(nums, mid + 1, right, target);

            if (ll[0] == -1)
                return rr;
            if (rr[0] == -1)
                return ll;

            return {ll[0], rr[1]};
        }
        return {-1, -1};
    }

    // O(logn)
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        return search(nums, 0, n - 1, target);
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    nums = {1};
    int t = 6;
    t = 1;
    vector<int> res = sol.searchRange(nums, t);
    cout << res[0] << " " << res[1];
    cout << endl;
}

int main()
{
    _main();
    return 0;
}