/**
 * https://leetcode.com/problems/path-crossing/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPathCrossing(string path)
    {
        if (path.size() == 2 && path[0] == path[1])
            return false;
        unordered_map<char, int> ch;
        for (int i : path)
            ch[i]++;
        for (auto i : ch)
        {
            if (i.second > 1)
                return true;
        }
        return false;
    }
};

void _main()
{
    Solution sol;
    string path = "NESWW";
    // s = "leetcode";
    // s = "l";
    bool res = sol.isPathCrossing(path);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}