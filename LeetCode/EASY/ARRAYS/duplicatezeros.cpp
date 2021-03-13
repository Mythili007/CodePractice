/**
 * https://leetcode.com/problems/duplicate-zeros/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int j = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                j++;
                arr[j] = 0;
                // j++;
                // j++;
                // arr[j] = 0;
            } else {
                arr[j] = arr[i];
            }
            // j++;
            cout << "arr[i]: " << arr[i] << " ";
        }
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {1, 0, 2, 3, 0, 4, 5, 0};
    nums = {0,1,2,3};

    sol.duplicateZeros(nums);
    // for (int _v : res)
    // {
    // for (int d : _v)
    // {
    // cout << res << " ";
    cout << endl;
    // }
    // }
}

int main()
{
    _main();
    return 0;
}