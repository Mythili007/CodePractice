/*
* https://leetcode.com/problems/sort-list/
* 148. Sort List 
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
    void swap(ListNode *first, ListNode *second)
    {
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
    //BUBBLE SORT
    ListNode *sortList1(ListNode *head)
    {
        bool swapped = false;
        do
        {
            swapped = false;
            ListNode *tmp = head;
            while (tmp != NULL && tmp->next != NULL)
            {
                if (tmp->val > tmp->next->val)
                {
                    swap(tmp, tmp->next);
                    swapped = true;
                }
                tmp = tmp->next;
            }
        } while (swapped);
        return head;
    }

    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode dummy(INT_MIN);
        ListNode *t1 = &dummy;

        while (head1 != NULL && head2 != NULL)
        {
            if (head1->val <= head2->val)
            {
                t1->next = head1;
                head1 = head1->next;
            }
            else
            {
                t1->next = head2;
                head2 = head2->next;
            }
            t1 = t1->next;
        }

        if (head1 != NULL)
            t1->next = head1;
        else
            t1->next = head2;

        return dummy.next;
    }

    ListNode *midOfTheList(ListNode *head)
    {
        ListNode *tmp = head;
        ListNode *t1 = NULL;
        while (tmp != NULL && tmp->next != NULL)
        {
            t1 = (t1 == NULL) ? tmp : t1->next;
            tmp = tmp->next->next;
        }
        ListNode *mid = t1->next;
        t1->next = NULL;
        return mid;
    }

    //MERGE SORT
    ListNode* sortList(ListNode *head)
    {
        ListNode *mid = midOfTheList(head);
        ListNode *leftList = sortList(head);
        ListNode *rightList = sortList(mid);

        ListNode *mergedHead = merge(leftList, rightList);
        return mergedHead;
    }
};

ListNode *buildList(vector<int> nums, int ind)
{
    if (ind == nums.size())
        return NULL;
    ListNode *tmp = new ListNode(nums[ind]);
    tmp->next = buildList(nums, ind + 1);

    return tmp;
}

void _main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    nums = {1, 7, 5, 1, 9, 2, 5, 1};
    // TreeNode* root = buildTree(houses, 0);
    ListNode *head = buildList(nums, 0);

    Solution sol;

    cout << sol.sortList(head) << endl;
    sol.printList(head);
    // sol.printList(head);
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}