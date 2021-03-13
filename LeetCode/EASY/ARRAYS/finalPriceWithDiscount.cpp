/**
 * https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        for (int i = 0; i < prices.size(); i++)
        {
            for (int j = i + 1; j < prices.size(); j++)
            {
                if (j > i && prices[j] <= prices[i])
                {
                    prices[i] = prices[i] - prices[j];
                    break;
                }
            }
        }
        return prices;
    }
};

void _main()
{
    Solution sol;
    vector<int> prices = {8, 4, 6, 2, 3};

    vector<int> res = sol.finalPrices(prices);

    for (int _v : res)
    {
        cout << _v << " ";
    }
}

int main()
{
    _main();
    return 0;
}