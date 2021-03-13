/**
 * https://leetcode.com/problems/powerful-integers/
 * POWERFUL INTEGERS
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        vector<int> v;
        return v;
    }
};

void _main()
{
    Solution sol;
    int x = 2, y = 3, bound = 10;
    vector<int> res = sol.powerfulIntegers(x, y, bound);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}