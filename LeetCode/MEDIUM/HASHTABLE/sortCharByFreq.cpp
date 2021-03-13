/*
 * https://leetcode.com/problems/sort-characters-by-frequency/
 * Sort Characters By Frequency
 */

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> m;
        for (char ch : s)
            m[ch]++;

        priority_queue<pair<int, char>> pq;
        string res;
        for (auto i : m)
        {
            cout << "first: " << i.first << "  second: " << i.second << endl;
            pq.push(make_pair(i.second, i.first));
        }
        while (!pq.empty())
        {
            pair<int, char> p = pq.top();
            cout << p.first << "   " << p.second << endl;
            for (int i = 0; i < p.first; i++)
                res += p.second;
            pq.pop();
        }

        return res;
    }
};

void _main()
{
    Solution sol;
    string st = "tree";
    st = "Aabb";
    st = "raaeaedere";

    cout << sol.frequencySort(st) << endl;

    cout << endl;
}

int main()
{
    _main();
    return 0;
}