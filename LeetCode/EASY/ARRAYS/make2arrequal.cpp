/**
 * https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> reverseArr(vector<int> &a, int start, int end)
    {
        int temp = 0;
        int aa = end;
        for (int i = start; i < end; i++)
        {
            cout << "a[i] : " << a[i] << " ";

            temp = a[i];
            a[i] = a[aa];
            a[aa] = temp;
            aa--;
        }

        return a;
    }

    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        int m = target.size();
        int n = arr.size();

        if (m != n)
            return false;
        if (m == 1 && arr[0] == target[0])
            return true;

        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i; j < arr.size(); j++)
            {
                if (arr[j] == target[i] && i != j)
                {
                    reverseArr(arr, i, j);
                }
            }
        }
        int c = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (target[i] == arr[i])
                c++;
        }

        if (c == target.size())
            return true;
        else
            return false;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums1 = {3, 7};
    vector<int> nums2 = {3, 7};
    int k = 4;
    // nums = {-1, -2, -3, -4};

    bool res = sol.canBeEqual(nums1, nums2);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}