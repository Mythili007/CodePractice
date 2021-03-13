/**
 * https://leetcode.com/problems/contains-duplicate-ii/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &a, int n)
    {
        int size = a.size();
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if(a[i] == 0 && (i == 0 || a[i-1] == 0) && (i == size - 1 || a[i+1] == 0)){
                a[i] = 1;
                count++;
            }
        }

        if (count >= n)
            return true;
        else
            return false;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {1, 0, 0, 0, 1};
    // nums = {0, 1, 2, 3, 3, 5, 2, 1, 0};
    int k = 2;

    bool res = sol.canPlaceFlowers(nums, k);
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