/**
 * https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

int maximumElement(int startInd, vector<int> &arr)
{
    int maximumEl = INT_MIN;
    for (int i = startInd; i < arr.size(); i++)
    {
        if (arr[i] > maximumEl)
            maximumEl = arr[i];
    }
    return maximumEl;
}

class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (i == arr.size() - 1)
            {
                arr[i] = -1;
                break;
            }
            else
            {
                arr[i] = maximumElement(i + 1, arr);
            }
        }
        return arr;
    }
};

void _main()
{
    Solution sol;
    vector<int> arr = {17, 18, 5, 4, 6, 1};

    vector<int> res = sol.replaceElements(arr);

    for (int _v : res)
    {
        cout << _v << " ";
    }
}

int main()
{
    _main();
    return 0;
}