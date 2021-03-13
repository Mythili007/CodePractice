
/**
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findIndex(vector<int> &prices, int n)
    {
        int ind = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] == n)
            {
                ind = i;
                break;
            }
        }
        return ind;
    }
    int maxProfit1(vector<int> &prices)
    {
        if (prices.size() == 1)
            return prices[0];
        int mini = *min_element(prices.begin(), prices.end());
        int min_ind = findIndex(prices, mini);
        int maxi = *max_element(prices.begin() + min_ind, prices.end());
        int max_ind = 0;
        for (int i = min_ind; i < prices.size(); i++)
        {
            if (prices[i] == maxi)
            {
                max_ind = i;
                break;
            }
        }
        if (min_ind < max_ind)
            return maxi - mini;
        else
            return 0;
    }

    int maxProfit2(vector<int> &prices)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < prices.size(); i++)
        {
            for (int j = i + 1; j < prices.size(); i++)
            {
                if (prices[j] - prices[i] > maxi)
                    maxi = prices[j] - prices[i];
            }
        }
        return maxi;
    }

    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (minPrice < prices[i])
                minPrice = prices[i];
            else if (prices[i] - minPrice > maxProfit)
                maxProfit = prices[i] - minPrice;
        }
        return maxProfit;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {7, 1, 5, 3, 6, 4};

    int res = sol.maxProfit(nums);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}