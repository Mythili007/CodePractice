/**
 * https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        int count = 0;
        for (int i = 0; i < arr1.size(); i++)
        {
            for (int j = 0; j < arr2.size(); j++)
            {
                int dist = abs(arr1[i] - arr2[j]);
                if (dist <= d && dist != 0)
                    count++;
            }
        }
        return count;
    }
};

void _main()
{
    Solution sol;
    vector<int> a1 = {1, 4, 2, 3};
    vector<int> a2 = {-4, -3, 6, 10, 20, 30};
    // a = {1, 3, 4, 2};
    int d = 3;

    int res = sol.findTheDistanceValue(a1, a2, d);
    // for (int i : res)
    //     cout << i << " ";
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}