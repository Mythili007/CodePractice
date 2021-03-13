/**
 * https://leetcode.com/problems/maximum-product-of-three-numbers/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositive_1(vector<int> &arr, int k)
    {
        int maxEle = arr[arr.size()-1];
        int n = arr.size();
        int missingElements = (n > maxEle) ? (n - maxEle) : (maxEle - n);
        cout<<"missingElements: " <<missingElements<<endl;
        int count = 0;
        int kthMissingElement = 0;
        int j =0;
        vector<int> a;
        for (int i = 1; i <= maxEle; i++)
        {
            cout<<"a[j]: "<<i<<" ";
            a[j] = i;
            j++;
        }
        cout<<endl;
        if (k > missingElements)
        {
            int till = maxEle - k;
            cout<<"till: "<<till<<" ";
            for (int i = maxEle + 1; i <= till; i++)
            {
                a[j] = i;
            }
        }

        kthMissingElement = a[k];
        // if (missingElements >= k)
        // {
        //     for (int i = 1; i < maxEle; i++)
        //     {
        //         for (int j = 0; j < n; j++)
        //         {
        //             if (i != arr[j])
        //             {
        //                 count++;
        //                 cout <<" i: " << i << "   count: " << count << " ";
        //             }
        //             if (count == k)
        //             {
        //                 kthMissingElement = i;
        //                 break;
        //             }
        //         }
        //     }
        // }
        // else
        // {
        //     kthMissingElement = maxEle + abs(missingElements - k);
        // }
        return kthMissingElement;
    }

    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int maxEle = arr[n - 1];
        int j = 0;

        for (int i = 1; i <= maxEle; i++)
        {
            if (i == arr[j])
            {
                j++;//j=3
            }
            else
            {
                k--; //0
                if (k == 0)
                    return i;
            }
        }

        while (k > 0)
        {
            maxEle++;
            k--;
        }
        return maxEle;
    }
};

void _main()
{
    Solution sol;
    vector<int> nums = {2, 3, 4, 7, 11};
    int k = 5;
    nums = {1, 2, 3, 5}, k=4;

    int res = sol.findKthPositive(nums, k);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}