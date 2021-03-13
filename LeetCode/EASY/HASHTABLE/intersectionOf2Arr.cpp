/**
 * https://leetcode.com/problems/intersection-of-two-arrays/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> v;
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        for (int i = 0; i < nums1.size(); i++)
            m1[nums1[i]]++;
        for (int i = 0; i < nums2.size(); i++)
            m2[nums2[i]]++;

        if (m2.size() <= m1.size())
        {
            for (auto i : m2)
            {
                cout << "@@@first: " << i.first << "    second: " << i.second << endl;
                if (m1.find(i.first) != m1.end())
                    v.push_back(i.first);
            }
        }
        else
        {
            for (auto i : m1)
            {
                cout << "first: " << i.first << "    second: " << i.second << endl;
                if (m2.find(i.first) != m2.end())
                    v.push_back(i.first);
            }
        }
        return v;
    }
};

void _main()
{
    Solution sol;
    vector<int> A = {1, 2, 3};
    vector<int> B = {1, 4, 3};
    A = {1, 2, 2, 1}, B = {2, 2};
    vector<int> res = sol.intersection(A, B);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}