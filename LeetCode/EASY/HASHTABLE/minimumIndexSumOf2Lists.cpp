/**
 * https://leetcode.com/problems/minimum-index-sum-of-two-lists/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        if (list1 == list2)
            return list1;
        int cnt = 0, minInd = INT_MAX, ind = 0;
        unordered_map<string, int> m;
        unordered_map<int, string> n;
        vector<string> v;
        for (int i = 0; i < list1.size(); i++)
            m[list1[i]] = i;
        for (int i = 0; i < list2.size(); i++)
        {
            cout << "list2[i]: " << list2[i] << endl;
            if (m.count(list2[i]) != 0)
            { //if its found in the map
                ind = m[list2[i]] + i;
                if (ind < minInd)
                    v.clear();
                if (ind <= minInd)
                {
                    minInd = ind;
                    v.push_back(list2[i]);
                }
            }
        }

        return v;
    }
};

void _main()
{
    Solution sol;

    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"}, list2 = {"KFC", "Shogun", "Burger King"};
    list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"}, list2 = {"KFC", "Burger King", "Tapioca Express", "Shogun"};
    vector<string> res = sol.findRestaurant(list1, list2);
    for (string i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}