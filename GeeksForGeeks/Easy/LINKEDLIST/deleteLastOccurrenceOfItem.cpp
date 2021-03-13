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

ListNode *deleteTheLastOccuurrence(ListNode *head, int x)
{
    ListNode *tmp = head;
    ListNode *tmp1;
    while (tmp != NULL)
    {
        if (tmp->val == x)
            tmp1 = tmp;
        tmp = tmp->next;
    }
    tmp = head;
    while (tmp != NULL)
    {
        if (tmp->next == tmp1)
            tmp->next = tmp->next->next;
        tmp = tmp->next;
    }
    return head;
}

class Solution
{
public:
    void printList(ListNode *prev)
    {
        while (prev != NULL)
        {
            cout << prev->val << " ";
            prev = prev->next;
        }
        cout << endl;
    }

    ListNode *deleteOccurrence(ListNode *head, int x)
    {
        ListNode *res = deleteTheLastOccuurrence(head, x);
        printList(res);
        return res;
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
    vector<int> nums = {1, 2, 2, 3};
    nums = {1, 2, 3, 5, 2, 10};
    // TreeNode* root = buildTree(houses, 0);
    ListNode *head = buildList(nums, 0);

    Solution sol;
    int x = 2;

    /* vector<int> result = sol.decode(encoded);
  for(int _r: result) 
    cout << _r << " ";
  cout << endl; */

    // sol.doQuery(functionCall, arr, inputs);

    cout << sol.deleteOccurrence(head, x) << endl;
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}