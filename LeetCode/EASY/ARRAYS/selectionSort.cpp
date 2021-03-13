
/**
 * SELECTION SORT
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void swap(vector<int> &arr, int firstInd, int minInd)
    {
        int temp = arr[firstInd];
        arr[firstInd] = arr[minInd];
        arr[minInd] = temp;
    }

    int findMinInd(vector<int> &arr, int startInd)
    {
        int minVal = arr[startInd];
        int minInd = startInd;

        for (int i = minInd + 1; i < arr.size(); i++)
        {
            if (arr[i] < minVal)
            {
                minVal = arr[i];
                minInd = i;
            }
        }
        return minInd;
    }

    void selectionSort(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            int minInd = findMinInd(arr, i);
            swap(arr, i, minInd);
        }
        return arr;
        /* for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i];
            if (i != arr.size() - 1)
                cout << ", ";
        } */
    }
};

void _main()
{
    Solution sol;
    vector<int> arr = {2, 4, 9, 3, 6};
    // vector<int> res = sol.selectionSort(arr);
    sol.selectionSort(arr);
    // for (int i : res)
    //     cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}