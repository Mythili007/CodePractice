/**
 * https://leetcode.com/problems/unique-number-of-occurrences/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> m;
        unordered_set<int> res;
        for (int i = 0; i < arr.size(); i++)
        {
            m[arr[i]]++;
        }
        for (auto &i : m)
        {
            res.insert(i.second);
        }
        return m.size() == res.size();
    }
};

void _main()
{
    Solution sol;
    vector<int> A = {1, 2, 3, 3};
    // A = {5, 1, 5, 2, 5, 3, 5, 4};
    A = {-3,0,1,-3,1,1,1,-3,10,0};
    A = {1,2};
    int res = sol.uniqueOccurrences(A);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}