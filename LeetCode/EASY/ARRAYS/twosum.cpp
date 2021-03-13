/**
 * https://leetcode.com/problems/two-sum/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //brute force solution - O(n^2)
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> a;
        int flag = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    a.push_back(i);
                    a.push_back(j);
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }

        return a;
    }
    //two pass hash map - O(n)
    vector<int> twoSum1(vector<int> &nums, int target)
    {
        vector<int> a;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int c = target - nums[i];
            cout<<"m: "<<(m.find(i) == m.end())<<endl;
            // if (m.find(c))
            // {
            //     a.push_back(i);
            //     a.push_back(j);
            //     break;
            // }
        }
        return a;
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {2, 7, 11, 15};
    int t = 9;

    vector<int> res = sol.twoSum(a, t);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}