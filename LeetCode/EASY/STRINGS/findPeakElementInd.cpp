/**
 * https://leetcode.com/problems/student-attendance-record-i/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int m INT_MIN, ind = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > m)
            {
                m = arr[i];
                ind = i;
            }
        }
        return ind;
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {24, 69, 100, 99, 79, 78, 67, 36, 26, 19};
    int res = sol.peakIndexInMountainArray(a);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}