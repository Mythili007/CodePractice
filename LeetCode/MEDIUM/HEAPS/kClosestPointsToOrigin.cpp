/*
 * https://leetcode.com/problems/k-closest-points-to-origin/
 * 973. K Closest Points to Origin
 */

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

class Solution
{
public:
    void swap(vector<int> &arr, int leftInd, int rightInd)
    {
        int temp = arr[leftInd];
        arr[leftInd] = arr[rightInd];
        arr[rightInd] = temp;
    }

    void minHeapify(vector<int> &arr, int size, int ind)
    {
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;

        int smallest = ind;

        if (left < arr.size() && arr[left] < arr[smallest])
            smallest = left;

        if (right < arr.size() && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != ind)
        {
            swap(arr, smallest, ind);
            minHeapify(arr, size, smallest);
        }
    }

    vector<int> buildMinHeap(vector<int> &arr)
    {
        for (int i = (arr.size() - 1) / 2; i >= 0; i--)
        {
            minHeapify(arr, arr.size(), i);
        }
        return arr;
    }

    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        int dist = 0;
        multimap<int, int> m;
        for (int i = 0; i < points.size(); i++)
        {
            int dist = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            m.insert({dist, i});
        }

        vector<vector<int>> res;
        for (auto i : m)
        {
            cout<<"first: "<<i.first<<"  second: "<<i.second<<endl;
            // res.push_back(points[i.second]);
            // k--;
            // if (k == 0)
            //     break;
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {2, 7, 4, 1, 8, 10};
    vector<int> res = sol.buildMinHeap(a);
    vector<vector<int>> points = {{1, 3}, {2, -2}};
    vector<vector<int>> result = sol.kClosest(points, 1);

    for (vector<int> i : result)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    _main();
    return 0;
}