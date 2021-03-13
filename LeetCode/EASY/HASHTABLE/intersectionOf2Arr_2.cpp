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

        if (m1.size() <= m2.size())
        {
            for (auto i : m1)
            {
                if (m2.find(i.first) != m2.end())
                {
                    //take the minimum
                    int m = min(i.second, m2[i.first]);
                    cout << "m: " << m << endl;
                    for (int j = 0; j < m; j++)
                        v.push_back(i.first);
                }
            }
        }
        else
        {
            for (auto i : m2)
            {
                if (m1.find(i.first) != m1.end())
                {
                    //take the minimum
                    int m = min(i.second, m1[i.first]);
                    cout << "m: " << m << endl;
                    for (int j = 0; j < m; j++)
                        v.push_back(i.first);
                }
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
    A = {2, 2, 2}, B = {2, 2, 2, 2};
    // A = {3, 1, 2}, B = {1, 1};
    vector<int> res;
    res = sol.intersection(A, B);

    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}