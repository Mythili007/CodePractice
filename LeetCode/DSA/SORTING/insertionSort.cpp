
/**
 * * INSERTION SORT
 * * Call insert to insert the element that starts at index 1 into the sorted subarray in index 0.
 * * Call insert to insert the element that starts at index 2 into the sorted subarray in indices 0 through 1.
 * * Call insert to insert the element that starts at index 3 into the sorted subarray in indices 0 through 2.
 * * …
 * * Finally, call insert to insert the element that starts at index n-1n−1 into the sorted subarray in indices 0 through n−2.
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void insert(vector<int> &arr, int rightInd, int val)
    {
        int j = rightInd;
        for (; j >= 0 && arr[j] > val; j--)
            arr[j + 1] = arr[j];

        arr[j + 1] = val;
    }

    vector<int> insertionSort(vector<int> &arr)
    {
        for (int i = 1; i < arr.size(); i++)
            insert(arr, i - 1, arr[i]);

        return arr;
    }
};

void _main()
{
    Solution sol;
    vector<int> arr = {2, 4, 9, 3, 6};
    vector<int> res = sol.insertionSort(arr);
    // sol.insertionSort(arr);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}