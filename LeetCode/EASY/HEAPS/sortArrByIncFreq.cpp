/*
 * https://leetcode.com/problems/sort-array-by-increasing-frequency/
 * 1636. Sort Array by Increasing Frequency
 */

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        map<int, int> m;
        for (int i : nums)
            m[i]++;

        priority_queue<pair<int, int>> pq;
        vector<int> res;
        for (auto i : m){
            pq.push(make_pair(i.second, i.first));
        }

        stack<pair<int, int>> st;
        while (!pq.empty())
        {
            pair<int, int> tmp = pq.top();
            cout << "fir: " << tmp.first << "  sec: " << tmp.second << endl;
            pq.pop();
            st.push(make_pair(tmp.second, tmp.first));
        }
        /* while (!st.empty())
        {
            pair<int, int> tmp = st.top();
            cout << "st:fir: " << tmp.first << "  st:sec: " << tmp.second << endl;
            for (int i = 0; i < tmp.second; i++)
                res.push_back(tmp.first);
            st.pop();
        } */
        return res;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    nums = {2, 3, 1, 3, 2};
    vector<int> res = sol.frequencySort(nums);
    for (int i : res)
        cout << i << " ";

    cout << endl;
}

int main()
{
    _main();
    return 0;
}