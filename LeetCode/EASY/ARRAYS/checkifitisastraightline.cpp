/**
 * https://leetcode.com/problems/check-if-it-is-a-straight-line/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int n = coordinates.size();
        //0 - {1,2}, 1 - {2,3}
        int diff = coordinates[1][0] - coordinates[0][0];
        float slope = 0;

        if (coordinates[1][0] - coordinates[0][0] == 0)
        {
            slope = INT_MAX;
        }
        else
        {
            slope = float(coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
        }
        for (int i = 2; i < n; i++)
        {
            if (coordinates[i][0] - coordinates[i - 1][0] == 0)
            { // || coordinates[i + 1][1] - coordinates[i][1] != diff2){
                if (slope != INT_MAX)
                    return false;
            }
            else if (float(coordinates[i][1] - coordinates[i - 1][1]) / (coordinates[i][0] - coordinates[i - 1][0]) != slope)
                return false;
        }
        return true;
    }
};

void _main()
{
    Solution sol;
    vector<vector<int>> a = {{1, 1}, {2, 2}, {3, 3}};
    int k = 34;

    bool res = sol.checkStraightLine(a);
    // for (int i : res)
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}