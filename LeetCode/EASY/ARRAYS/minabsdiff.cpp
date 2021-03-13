/**
 * https://leetcode.com/problems/minimum-absolute-difference/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> arr_1;
        int mini = INT_MAX;
        for (int i = 1; i < arr.size(); i++)
        {
            if (abs(arr[i - 1] - arr[i]) < mini)
            {
                mini = abs(arr[i - 1] - arr[i]);
            }
        }

        for (int i = 1; i < arr.size(); i++)
        {
            vector<int> a;
            if (abs(arr[i-1] - arr[i]) == mini)
            {
                a.push_back(arr[i-1]);
                a.push_back(arr[i]);
                arr_1.push_back(a);
            }
        }
        
        return arr_1; 
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {4, 2, 1, 3};
    // nums = {-1, -2, -3, -4};

    vector<vector<int>> res = sol.minimumAbsDifference(nums);
    for (vector<int> _v : res)
    {
        for (int d : _v)
        {
            cout << d << " ";
        }
        cout << endl;
    }
}

int main()
{
    _main();
    return 0;
}