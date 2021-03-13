/**
 * https://leetcode.com/problems/relative-sort-array/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray1(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> arr3;
        vector<int> arr4;
        vector<int> arr5;
        int j = 0;
        int k = 0;
        int l = 0;
        for (int i = 0; i < arr2.size(); i++)
        {
            cout << "check1" << endl;

            for (int j = 0; j < arr1.size(); j++)
            {
                if (arr2[i] == arr1[j])
                {
                    cout << "check2" << endl;
                    arr3[k] = arr1[j];
                    k++;
                }
                else
                {
                    cout << "check3" << endl;

                    arr4[l] = arr1[j];
                    l++;
                }
            }
        }
        for (int i = 0; i < arr3.size(); i++)
        {
            cout << arr3[i] << " ";
        }
        cout << endl;
        arr5.reserve(arr3.size() + arr4.size());
        arr5.insert(arr5.end(), arr3.begin(), arr3.end());
        arr5.insert(arr5.end(), arr4.begin(), arr4.end());
        return arr5;
    }

    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> dp(1001, 0);
        vector<int> res;
        for (int i = 0; i < arr1.size(); i++)
            dp[arr1[i]]++;

        for (int i = 0; i < arr2.size(); i++)
        {
            for (int j = 0; j < dp[arr2[i]]; j++){
                // cout<<dp[arr2[i]]<<" ";
                res.push_back(arr2[i]);
            }
            dp[arr2[i]] = 0;
        }

        for (int i = 0; i <= 1000; i++)
        {
            for (int j = 0; j < dp[i]; j++)
                res.push_back(i);
        }

        return res;
    }
};

void _main()
{
    Solution sol;
    vector<int> a1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> a2 = {2, 1, 4, 3, 9, 6};
    // a = {1, 3, 4, 2};

    vector<int> res = sol.relativeSortArray(a1, a2);
    // for (int i : res)
    //     cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}