/**
 * https://leetcode.com/problems/valid-mountain-array/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int size = arr.size() - 1;
        int i = 0;

        while (i + 1 < size && arr[i] < arr[i + 1])
            i++;

        if (i == 0 || i == size - 1)
            return false;

        while (i + 1 < size && arr[i] > arr[i + 1])
            i++;

        return i == size - 1;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {0, 3, 3, 1};
    nums = {0, 1, 2, 3, 3, 5, 2, 1, 0};

    bool res = sol.validMountainArray(nums);
    // for (int _v : res)
    // {
    // for (int d : _v)
    // {
    cout << res << " ";
    cout << endl;
    // }
    // }
}

int main()
{
    _main();
    return 0;
}