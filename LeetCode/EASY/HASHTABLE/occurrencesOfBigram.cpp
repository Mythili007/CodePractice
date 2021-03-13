/**
 * https://leetcode.com/problems/occurrences-after-bigram/
 * Occurrences of bigram
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findOcurrences(string text, string first, string second)
    {
        vector<string> v, u;
        stringstream ss(text);
        string res;
        while (getline(ss, res, ' '))
            v.push_back(res);
        sort(v.begin(), v.end());
        binary_search()
        for (int i = 0; i < v.size() - 2; i++)
        {
            if (v[i] == first && v[i + 1] == second)
                u.push_back(v[i + 2]);
        }
        return u;
    }
};

void _main()
{
    Solution sol;
    string text = "alice is a good girl she is a good student", first = "a", second = "good";
    text = "we will we will rock you", first = "we", second = "will";
    vector<string> res = sol.findOcurrences(text, first, second);
    for (string i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}