/**
 * https://leetcode.com/problems/long-pressed-name/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isLongPressedName1(string name, string typed)
    {
        unordered_map<char, int> mNamed;
        unordered_map<char, int> mTyped;
        int flag = 0;
        for (int i = 0; i < name.size(); i++)
        {
            mNamed[name[i]]++;
        }

        for (int i = 0; i < typed.size(); i++)
        {
            mTyped[typed[i]]++;
        }

        // for(auto a:mNamed)

        // for (auto b : mTyped)

        for (auto a : mNamed)
        {
            cout << "a.first: " << a.first << "  : " << a.second << endl;
            for (auto b : mTyped)
            {
                cout << "b.first: " << b.first << "  : " << b.second << endl;
                if (a.first == b.first && b.second < a.second)
                    return false;
                if (a.first == b.first && b.second >= a.second)
                {
                    flag = 1;
                    break;
                }
            }
        }
        return true;
    }

    bool isLongPressedName(string name, string typed)
    {
        int j = 0;
        for (int i = 0; i < typed.size(); i++)
        {
            if (j < name.size() && name[j] == typed[i])
                ++j;
            else if (!i || typed[i] != typed[i - 1])
                return false;
        }
        return j == name.size();
    }
};

void _main()
{
    Solution sol;
    string name = "alex";
    string typed = "aaleex";
    // name = "saeed", typed = "ssaaedd";
    // name = "xnhtq", typed = "xhhttqq";
    bool res = sol.isLongPressedName(name, typed);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}