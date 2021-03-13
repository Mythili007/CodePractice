/*
 * https://leetcode.com/problems/top-k-frequent-elements/
 * 347. Top K Frequent Elements
 */

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        for (int i : nums)
        {
            m[i]++;
        }

        vector<int> res;
        priority_queue<pair<int, int>> pq;
        for (auto i : m)
        {
            pq.push(make_pair(i.second, i.first));
            if (pq.size() > m.size() - k)
            {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};

void _main()
{
    Solution sol;

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> result = sol.topKFrequent(nums, 2);

    for (int j : result)
    {
        cout << j << " ";
    }
    cout << endl;
}

int main()
{
    _main();
    return 0;
}