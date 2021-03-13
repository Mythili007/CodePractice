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

ListNode *createNonDuplicateList(ListNode *head)
{
    if (head == NULL)
        return head;
    ListNode *head2 = new ListNode(head->val);
    ListNode *tmp1 = head, *t1 = head, *tmp2 = head2, *t2 = NULL;
    t1 = t1->next;

    while (t1 != NULL)
    {
        if (t1->val == tmp1->val)
        {
            t1 = t1->next;
        }
        else
        {
            ListNode *tmp = new ListNode(t1->val);
            tmp2->next = tmp;
            tmp2 = tmp;
            tmp1 = t1;
            t1 = t1->next;
        }
    }

    return head2;
}

class Solution
{
public:
    ListNode *mergeLists(ListNode *h1, ListNode *h2)
    {
        ListNode dummy(INT_MIN);
        ListNode *h3 = &dummy;
        ListNode *t1 = h1, *t2 = h2;

        while (t1 != NULL && t2 != NULL)
        {
            if (t1->val < t2->val)
            {
                h3->next = t1;
                t1 = t1->next;
            }
            else
            {
                h3->next = t2;
                t2 = t2->next;
            }
            h3 = h3->next;
        }
        h3->next = t1 ? t1 : t2;
        return dummy.next;
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *t1 = l1, *t2 = l2;
        ListNode *mergedList = mergeLists(l1, l2);
        return mergedList;
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
    vector<int> nums1 = {1, 3, 5};
    vector<int> nums2 = {2, 4, 6};
    // nums = {1, 2, 2, 1};

    // TreeNode* root = buildTree(houses, 0);
    ListNode *head1 = buildList(nums1, 0);
    ListNode *head2 = buildList(nums2, 0);

    Solution sol;

    /* vector<int> result = sol.decode(encoded);
  for(int _r: result) 
    cout << _r << " ";
  cout << endl; */

    // sol.doQuery(functionCall, arr, inputs);

    cout << sol.mergeTwoLists(head1, head2) << endl;
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}