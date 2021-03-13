
/**
 * https://leetcode.com/problems/the-k-strongest-values-in-an-array/
 * 1471. The k Strongest Values in an Array
 * My initial solution during the contest was to sort the array 
 * to figure out the median, and then sort the array again based on the abs(arr[i] - median) criteria.
 * Then I noticed that we have smallest and largest elements in the array in the result. That makes sense based on the problem definition.
 * So, instead of sorting the array again,we can use the two pointers pattern to enumerate smallest and largest numbers, 
 * picking the largest abs(a[i] - median) each time.
 * The code above has one trick: we check that a[i] > a[j] first. This way, if a[i] == a[j], we pick the element from the right side, 
 * which is largest because the array is sorted!
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getStrongest(vector<int> &arr, int k)
    {
        //get median
        sort(arr.begin(), arr.end());
        int medianEle = arr[(arr.size() - 1) / 2];
        int left = 0;
        int right = arr.size() - 1;

        while (--k >= 0)
        {
            if (medianEle - arr[left] > arr[right] - medianEle)
                ++left;
            else
                --right;
        }
        arr.erase(arr.begin() + left, arr.begin() + right + 1);
        return arr;
    }
};

void _main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    vector<int> res = sol.getStrongest(arr, k);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}