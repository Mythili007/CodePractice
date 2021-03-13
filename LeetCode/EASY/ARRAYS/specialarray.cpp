/**
 * https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        if (nums.size() == 1 && nums[0] >= 1)
            return 1;
        int n = 2, c = 0;
        bool flag = true;
        for (int n = 2; n <= 1000; n++)
        {
            c = 0;
            cout<<"n: "<<n<<endl;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] != 0 && nums[i] >= n)
                {
                    c++;
                }
                if (c > n)
                {
                    cout << "c: " << c << endl;
                    // n = -1;
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                break;
        }
        return n;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {0, 4, 3, 0, 4};

    int res = sol.specialArray(nums);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}