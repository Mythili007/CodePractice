/*
* https://leetcode.com/problems/merge-in-between-linked-lists/
* 1669. Merge In Between Linked Lists
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
    void printList(ListNode *prev)
    {
        while (prev != NULL)
        {
            cout << prev->val << " ";
            prev = prev->next;
        }
        cout << endl;
    }

    ListNode *merge(ListNode *list1, ListNode *list2, int a, int b)
    {
        ListNode *t1 = list1;
        ListNode *tmp = list1;
        ListNode *t2 = list2;

        int cnt = 1;
        while (cnt < a)
        {
            t1 = t1->next;
            cnt++;
        }

        t1->next = list2;
        cnt = 1;
        while (cnt <= b)
        {
            tmp = tmp->next;
            cnt++;
        }

        while (t2->next != NULL)
        { //t1 ko aage kaise badana h
            t2 = t2->next;
        }
        t2->next = tmp->next;

        return t1;
    }

    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *newHead = merge(list1, list2, a, b);
        return newHead;
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