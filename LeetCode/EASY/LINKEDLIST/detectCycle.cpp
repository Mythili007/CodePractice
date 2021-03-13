/*
* https://leetcode.com/problems/remove-duplicates-from-sorted-list/
* 83. Remove Duplicates from Sorted List
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *tmp = head;
        unordered_map<string, bool> m;
        while (tmp != NULL)
        {
            if (m[tmp] == m.end())
                m[tmp] = 0;
            else
                return false;
            tmp = tmp->next;
        }
        return true;
    }
};

ListNode *buildList(vector<int> nums, int ind)
{
    if (nums.size() == ind)
        return NULL;

    ListNode *tmp = new ListNode(nums[ind]);
    tmp->next = buildList(nums, ind + 1);

    return tmp;
}

void _main()
{
    vector<int> nums = {1, 2, 3};
    nums = {1, 2, 2, 1};

    // TreeNode* root = buildTree(houses, 0);
    ListNode *head = buildList(nums, 0);

    Solution sol;

    /* vector<int> result = sol.decode(encoded);
  for(int _r: result) 
    cout << _r << " ";
  cout << endl; */

    // sol.doQuery(functionCall, arr, inputs);

    cout << sol.deleteDuplicates(head) << endl;
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}