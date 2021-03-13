/**
 * https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findSubArraysOfLengthM(vector<int> arr, int m, int index, vector<int> a, int i)
    {
        vector<vector<int>> data;
        // vector<int> a;
        if (index == m)
        {
            for (int j = 0; j < m; j++)
            {
                a.push_back(j);
            }
            data.push_back(a);
        }

        // if (i >= arr.size())
        //     return;
        cout << "index: " << index << endl;
        a[index] = arr[i];
        findSubArraysOfLengthM(arr, m, index + 1, a, i + 1);
        findSubArraysOfLengthM(arr, m, index, a, i + 1);

        return data;
    }

    bool containsPattern1(vector<int> &arr, int m, int k)
    {
        //first find sub arrays that of m length
        vector<int> b;
        vector<vector<int>> a = findSubArraysOfLengthM(arr, m, 0, b, 0);

        for (vector<int> i : a)
        {
            for (int _i : i)
            {
                cout << _i << " ";
            }

            cout << endl;
        }

        return true;
    }
    //reference from discussions
    bool equal(const vector<int> &a, int begin, int end, int position)
    {
        while (begin < end)
        {
            cout<<"a[begin]: "<<a[begin]<<"   a[position]: "<<a[position]<<endl;
            if (a[begin++] != a[position++])
                return false;
        }
        return true;
    }
    bool containsPattern(const vector<int> &arr, int m, int k)
    {
        for (int i = 0; i < arr.size() - m; ++i)
        {
            int c = 1;
            for (int j = i + m; j <= arr.size() - m; j+=m)
            {
                cout<<"j: "<< j<<endl;
                if (equal(arr, i, i + m, j))
                {
                    ++c;
                }
                else
                {
                    break;
                }

                if (c == k)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {1,2,4,4,4,4};
    int m = 2, k = 3;
    
    // nums = {3, 2, 3}, m = 2, k = 3;
    nums = {2, 2, 2, 2}, m = 2, k = 3;
    
    

    bool res = sol.containsPattern(nums, m, k);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}