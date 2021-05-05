/*
 * https://leetcode.com/problems/next-greater-element-i/
 * 496. Next Greater Element I
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> m;
        stack<int> s;
        vector<int> ans;
        for (int i : nums2)
        {
            while (s.size() > 0 && s.top() < i)
            {
                m[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        for (int i : nums1)
        {
            if (m.count(i))
                ans.push_back(m[i]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};
    vector<int> res = sol.nextGreaterElement(nums1, nums2);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}