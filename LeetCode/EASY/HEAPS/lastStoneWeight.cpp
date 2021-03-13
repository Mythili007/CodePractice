/*
 * https://leetcode.com/problems/last-stone-weight/
 * 1046. Last Stone Weight
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int stoneWeight(vector<int> &stones, int end)
    {
        if (end == 0)
        {
            return end;
        }
        else if (end > 0)
        {
            sort(stones.begin(), stones.end());
            int x = stones[end];
            int y = stones[end - 1];

            if (x == y)
            {
                //erase both indexes
                return stoneWeight(stones, end - 2);
            }

            else if (x != y)
            {
                //erase the min index, get the diff, put it at the end
                stones[end - 1] = x - y;
                return stoneWeight(stones, end - 1);
            }
        }
        return -1;
    }

    int lastStoneWeight(vector<int> &stones)
    {
        if (stones.size() == 0)
            return 0;

        int ind = stoneWeight(stones, stones.size() - 1);
        return (ind != -1) ? stones[ind] : 0;
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {2, 7, 4, 1, 8, 1};
    a = {1, 1, 1, 1};
    cout << sol.lastStoneWeight(a) << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}