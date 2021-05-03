/*
 * https://leetcode.com/problems/next-greater-element-ii/
 * 503. Next Greater Element II
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findFirstMax(int n, vector<int> v)
    {
        for (int i : v)
        {
            if (i > n)
                return i;
        }
        return -1;
    }

    vector<int> nextGreaterElements_1(vector<int> &nums)
    {
        bool found = false;
        vector<int> ans;
        int j = 0;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (m.find(nums[i]) == m.end())
                    m[nums[i]] = {};
                if (i != j)
                    m[nums[i]].push_back(nums[j]);
            }
        }

        for (auto i : nums)
        {
            // cout << "i.first: " << i.first << endl;

            // for (int j = 0; j < i.second.size(); j++)
            // {
            //     cout << i.second[j] << " ";
            // }
            // cout << endl;
            int el = findFirstMax(i, m[i]);
            ans.push_back(el);
        }
        return ans;
    }

    vector<int> nextGreaterElements(vector<int> &nums)
    {
        // int n = nums.size();
        // vector<int> v1, v2(n, -1);

        // for (int i = 0; i < n * 2; i++)
        // {
        //     while (v1.size() && nums[v1.back()] < nums[i % n])
        //     {
        //         v2[v1.back()] = nums[i % n];
        //         v1.pop_back();
        //     }
        //     v1.push_back(i % n);
        // }
        // return v2;
        vector<int> v(22);
        bool b = (v[6]);
        cout<< !b<<endl;
        return {};

    }
};

void _main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 1};
    nums1 = {1, 5, 3, 6, 8}; //5 6 6 8 -1
    vector<int> res = sol.nextGreaterElements(nums1);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}