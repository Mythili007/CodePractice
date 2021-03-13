/**
 * https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasGroupsSizeX1(vector<int> &deck)
    {
        /* 
            70/74 cases passed 
            [1,1,1,1,2,2,2,2,2,2] - is failed.. dnt knw y
        */
        int n = deck.size();
        if (n == 1)
            return false;

        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[deck[i]]++;
        }

        int m1 = INT_MAX;
        for (auto i : m)
        {
            if (i.second < 2)
            {
                return false;
            }
            if (i.second < m1)
                m1 = i.second;
        }

        for (auto i : m)
        {
            if (i.second % m1 != 0)
                return false;
        }

        return true;
    }

    int gcd(int a, int b)
    {
        if (b == 0)
            return a;

        return gcd(b, a % b);
    }

    bool hasGroupsSizeX(vector<int> &deck)
    {
        int n = deck.size();
        if (n == 1)
            return false;

        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[deck[i]]++;
        }
        int g = -1;
        for (auto i : m)
        {
            if (i.second > 0)
            {
                if (g == -1)
                    g = i.second;
                else
                    g = gcd(g, i.second);
            }
        }

        return g >= 2;
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {1, 2, 3, 4, 4, 3, 2, 1};
    a = {0, 0, 0, 1, 1, 1, 2, 2, 2};

    bool res = sol.hasGroupsSizeX(a);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}