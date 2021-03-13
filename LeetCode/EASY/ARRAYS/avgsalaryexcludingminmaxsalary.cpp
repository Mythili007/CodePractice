/**
 * https://leetcode.com/problems/maximum-product-of-three-numbers/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double average(vector<int> &salary)
    {
        int mini = *min_element(salary.begin(), salary.end());
        int maxi = *max_element(salary.begin(), salary.end());
        int sum = 0;
        for (int i : salary)
        {
            if (i != mini && i != maxi)
            {
                sum += i;
            }
        }
        return sum / (salary.size() - 2);
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {4000,3000,1000,2000};
    // nums = {-1, -2, -3, -4};

    double res = sol.average(nums);
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