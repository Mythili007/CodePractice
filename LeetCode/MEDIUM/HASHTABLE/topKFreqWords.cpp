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
        for (string &st : words)
            m[st]++;

        vector<vector<string>> list(words.size());
        for (auto i : m)
            list[i.second].push_back(i.first);

        vector<string> res;
        for (int i = (int)list.size() - 1; k > 0 && i >= 0; i--)
        {
            if (!list[i].empty())
            {
                int n = min(k, (int)list[i].size());
                res.insert(res.end(), list[i].begin(), list[i].begin() + n);
                k -= n;
            }
            if (k == 0)
                break;
        }
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