/**
 * https://leetcode.com/problems/lucky-numbers-in-a-matrix/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        bool flag = false;
        for (int i = 0; i < arr.size(); i++)//3,1,7,11
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i])
                {
                    flag = true;
                }

                if (flag == true)
                    break;
            }
            if (flag == true)
                break;
        }
        return flag;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {3, 7, 9, 11, 13};
    nums = {3, 1, 7, 11};

    bool res = sol.checkIfExist(nums);
    // for (int _v : res)
    // {
    // for (int d : _v)
    // {
    cout << res << " ";
    cout<<endl;
    // }
    // }
}

int main()
{
    _main();
    return 0;
}