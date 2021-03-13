
/**
 * https://leetcode.com/problems/slowest-key/
 * 1629. Slowest Key
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed)
    {
        int maxPressed = releaseTimes[0], res = keysPressed[0];

        for (int i = 1; i < releaseTimes.size(); i++)
        {
            int diff = releaseTimes[i] - releaseTimes[i - 1];
            if (maxPressed <= diff)
            {
                if (maxPressed == diff)
                    res = max((char)res, keysPressed[i]);
                else
                    res = keysPressed[i];

                maxPressed = diff;
            }
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    vector<int> releaseTimes = {9, 29, 49, 50};
    string keysPressed = "cbcd";

    cout << sol.slowestKey(releaseTimes, keysPressed) << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}