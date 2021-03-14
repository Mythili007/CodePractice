/*
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
 * 378. Kth Smallest Element in a Sorted Matrix
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pushToVector(vector<vector<int>> m)
    {
        vector<int> arr;
        for (vector<int> i : m)
        {
            for (int j = 0; j < i.size(); j++)
            {
                arr.push_back(i[j]);
            }
        }
        return arr;
    }

    void swap(vector<int> &arr, int leftInd, int rightInd)
    {
        int temp = arr[leftInd];
        arr[leftInd] = arr[rightInd];
        arr[rightInd] = temp;
    }

    void maxHeapify(vector<int> vv, int ind)
    {
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;
        int largest = ind;
        if (left < vv.size() && vv[left] > vv[largest])
            largest = left;

        if (right < vv.size() && vv[right] > vv[largest])
            largest = right;

        if (largest != ind)
        {
            swap(vv, ind, largest);
            maxHeapify(vv, largest);
        }
    }

    vector<int> buildMaxHeap(vector<int> abc)
    {
        for (int i = (abc.size() / 2) - 1; i >= 0; i--)
        {
            maxHeapify(abc, i);
        }
        return abc;
    }

    int findKthSmallest(vector<int> vec, int k)
    {
        priority_queue<int> pq;
        for (int i : vec)
        {
            pq.push(i);
        }
        int s = vec.size() - k + 1;
        while (!pq.empty())
        {
            // if (s--)
            cout<<pq.top()<<" ";
                pq.pop();
            if (s == 0)
                break;
        }
        
        return 1;
    }

    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        //smallest - max heap
        vector<int> v = pushToVector(matrix);
        vector<int> arr = buildMaxHeap(v);
        return findKthSmallest(arr, k);
    }
};

void _main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    matrix = {{1, 2}, {1, 3}};
    int k = 3;
    k = 2;
    cout << sol.kthSmallest(matrix, k) << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}