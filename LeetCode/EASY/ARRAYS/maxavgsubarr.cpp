/**
 * https://leetcode.com/problems/maximum-product-of-three-numbers/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMaxAverage1(vector<int> &nums, int l)
    {
        int n = nums.size();
        double sum = 0;
        int flag = 0;
        double res = 0;
        double m = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (i + j + 1 == l)
                {
                    cout << "xx: " << (i + j + 1) << endl;
                    sum = 0;
                    res = 0;
                    for (int k = i; k <= j; k++)
                    {
                        cout << nums[k] << " ";
                        sum += nums[k];
                    }
                    cout << endl;
                    res = sum / l;
                    cout << "res: " << res << endl;
                    if (res > m)
                    {
                        m = res;
                    }
                }
            }
        }
        cout << endl;
        return m;
    }

    double findMaxAverage(vector<int> &nums, int l)
    {
        vector<int> sum;
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            sum[i] = sum[i - 1] + nums[i];
        }

        double res = (sum[l - 1] * 1.0) / l;

        for (int i = l; i < nums.size(); i++)
        {
            res = max(res, (sum[i] - sum[i - l]) * 1.0 / l);
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    // nums = {-1, -2, -3, -4};

    int res = sol.findMaxAverage(nums, k);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}