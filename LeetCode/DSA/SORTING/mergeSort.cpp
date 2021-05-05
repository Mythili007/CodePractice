
/**
 * *
 * MERGE SORT
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void printArr(int arr[], int n)
    {
        for (int i =0; i<n;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void merge(int arr[], int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int leftArr[n1];
        int rightArr[n2];

        //copy data to the left and right temp arrays
        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];

        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
        {
            if (leftArr[i] <= rightArr[j])
            {
                arr[k] = leftArr[i];
                i++;
            }
            else
            {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }
        //copy the remaining elements
        while (i < n1)
        {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    void mergeSort(int arr[], int left, int right)
    {
        if (left >= right)
            return;
        int mid = left + right / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
};

void _main()
{
    Solution sol;
    int arr[5] = {2, 4, 9, 3, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    sol.mergeSort(arr, 0, size - 1);
    sol.printArr(arr, size);
    cout << endl;
}

int main()
{
    _main();
    return 0;
}