/**
 * https://leetcode.com/problems/find-the-duplicate-number/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge1(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int j = n;
        if (m == n)
        {
            for (int i = 0; i < m; i++)
            {
                nums1[i] = nums2[i];
            }
            for (int i = 0; i < nums1.size(); i++)
            {
                cout << nums1[i] << " ";
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                nums1[j] = nums2[i];
                j++;
            }
            sort(nums1.begin(), nums1.end());
            for (int i = 0; i < nums1.size(); i++)
            {
                cout << nums1[i] << " ";
            }
        }
    }

    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int j = 0;
        for (int i = m; i < m+n; i++)
        {
            nums1[i] = nums2[j];
            j++;
        }
        sort(nums1.begin(), nums1.end());
        for (int hh : nums1)
            cout << hh << " ";

        cout << endl;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    nums1 = {0};
    int m = 1;
    vector<int> nums2 = {1};
    int n = 1;
    // nums = {0,0,1,1,1,2,2,3,3,4};
    // nums = {1, 0};

    sol.merge(nums1, m, nums2, n);
    // cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}