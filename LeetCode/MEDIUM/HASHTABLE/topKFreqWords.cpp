/*
 * https://leetcode.com/problems/top-k-frequent-words/
 * Top K Frequent Words
 */

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> m;
        for (string st : words)
            m[st]++;

        vector<string> res;
        priority_queue<string> minHeap = 
        while (!pq.empty())
        {
            pair<int, string> p = pq.top();
            cout << "first: " << p.first << "  second: " << p.second << endl;
            pq.pop();
            res.push_back(p.second);
            k--;
            if (k == 0)
                break;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

void _main()
{
    Solution sol;
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    vector<string> res = sol.topKFrequent(words, k);
    for (string s : res)
        cout << s << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}