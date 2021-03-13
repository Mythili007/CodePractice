/**
 * https://leetcode.com/problems/distribute-candies/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        int maxSize = candyType.size() / 2, size = s.size(), res = 0;
        unordered_set<int> s(candyType.begin(), candyType.end());
        for (int i = 0; i < candyType.size(); i++)
            s.insert(candyType[i]);
        res = min(maxSize, size);
        return res;
    }
};

void _main()
{
    Solution sol;
    vector<int> A = {1, 1, 2, 2, 3, 3};
    // A = {1, 2, 2, 1}, B = {2, 2};
    int res = sol.distributeCandies(A);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}