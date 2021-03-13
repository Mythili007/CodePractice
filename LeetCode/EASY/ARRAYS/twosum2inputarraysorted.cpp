/**
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //brute force solution - O(n^2)
    vector<int> twoSum1(vector<int> &nums, int target)
    {
        vector<int> a;
        int flag = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    a.push_back(i + 1);
                    a.push_back(j + 1);
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }

        return a;
    }
    //two pointer solution
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> a;
        while (left < right)
        {
            int leftEle = nums[left];
            int rightEle = nums[right];
            if (leftEle + rightEle == target)
            {
                a.push_back(left + 1);
                a.push_back(right + 1);
                break;
            }
            else if (leftEle + rightEle > target)
            {
                right--;
            }
            else
            {
                left++;
            }
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