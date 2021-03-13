/**
 * https://leetcode.com/problems/summary-ranges/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    /* vector<string> pushToC(vector<int>& nums, int st, int e){
        vector<string> c;
        for(int i = st;i<=e;i++){
            c.push_back(nums[st]);
            c.push_back("->");
            // c.push_back(nums[])
        }
    } */

    vector<string> summaryRanges(vector<int>& nums) {
        int startInd = 0;
        int endIndex = 0;
        int count = 0;
        int n = nums.size();
        vector<string> c;
        for(int i=0;i<n;i++){
            if(nums[i+1] - nums[i] == 1){
                count++;
            } else {
                startInd = i - count;
                endIndex = i;
                //push into c 
                c.push_back(nums[startInd]);
            }
        }
        return c;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {0,1,2,4,5,7};
    // nums = {0,0,1,1,1,2,2,3,3,4};
    // nums = {1, 2,2,3,3,4,7};

    vector<string> res = sol.summaryRanges(nums);
    for(int i:res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}