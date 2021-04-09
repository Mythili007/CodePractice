
/*
 * https://leetcode.com/problems/number-of-provinces/
 * 547. Number of Provinces
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(int city, int parent[])
    {
        if (parent[city] == city)
            return parent[city];

        return parent[city] = find(parent[city], parent);
    }

    void unionSet(int city1, int city2, int parent[])
    {
        int _parent1 = find(city1, parent);
        int _parent2 = find(city2, parent);

        if (_parent1 != _parent2)
            parent[_parent1] = _parent2;
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int len = isConnected.size();
        int parent[len];
        // Make set
        for (int i = 0; i < len; i++)
            parent[i] = i;

        int provinceCnt = len;
        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    int x = find(i, parent);
                    int y = find(j, parent);

                    if (x == y)
                        continue;

                    unionSet(i, j, parent);
                    provinceCnt--;
                }
            }
        }
        return provinceCnt;
    }
};

void _main()
{
    Solution sol;
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << sol.findCircleNum(isConnected) << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}