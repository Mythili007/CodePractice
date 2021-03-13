/*
 * https://leetcode.com/problems/kth-largest-element-in-an-array/
 * 215. Kth Largest Element in an Array
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time complexity: O(nlogn) - SORTING
    int findKthLargest_1(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
    // USING PRIORITY QUEUE
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;

        for(int i: nums){
            pq.push(i);

            if(pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {2, 7, 4, 1, 8, 1};
    // a = {};
    int k = 2;
    cout << sol.findKthLargest(a, k) << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}