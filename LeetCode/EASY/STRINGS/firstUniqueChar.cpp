/**
 * https://leetcode.com/problems/first-unique-character-in-a-string/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        char ch;
        // int[] c = new int[26];
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            // cout<<"first: "<<i.first<<"  second: "<<i.second<<endl;
            if (m[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

void _main()
{
    Solution sol;
    string s = "hello";
    s = "leetcode";
    s = "loveleetcode";
    // s = "aA";
    int res = sol.firstUniqChar(s);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}