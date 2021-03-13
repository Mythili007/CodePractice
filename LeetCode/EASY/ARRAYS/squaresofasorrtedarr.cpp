/**
 * https://leetcode.com/problems/squares-of-a-sorted-array/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

vector<int> sortArr(vector<int> &A)
{
    vector<int> &B;
    int temp = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for(int j=i+1;j<A.size();j++){
            if(A[i]>A[j]){
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    return B;
}

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            A[i] = A[i] * A[i];
        }
        sort(A.begin(), A.end());

        return sortArr(A);
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> res = sol.sortedSquares(nums);

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