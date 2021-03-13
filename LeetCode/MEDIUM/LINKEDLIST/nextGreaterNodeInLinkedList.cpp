/*
* https://leetcode.com/problems/next-greater-node-in-linked-list/
* 1019. Next Greater Node In Linked List 
* similar problems list: 
* https://leetcode.com/problems/next-greater-node-in-linked-list/discuss/267163/Java-O(n)-using-Stack-and-ArrayList-w-15-similar-problem-list.
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
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> res;
        ListNode *t1 = head;
        ListNode *t2 = head;
        int max = INT_MIN;
        while (t1 != NULL)
        {
            max = t1->val; //1,7,5,1,9,2,5,1
            t2 = t1->next;
            while (t2 != NULL)
            {
                if (t2->val > max)
                {
                    max = t2->val;
                    break;
                }
                t2 = t2->next;
            }
            max = (max == t1->val) ? 0 : max;
            res.push_back(max);
            t1 = t1->next;
            t2 = t1;
        }
        return res;
    }
};

ListNode *buildList(vector<int> nums, int ind)
{
    if (ind == nums.size())
        return NULL;
    ListNode *tmp = new ListNode(nums[ind]);
    tmp->next = buildList(nums, ind + 1);

    // ListNode* tmp = new ListNode(nums[ind], buildList(nums, ind+1));

    return tmp;
}

void _main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    nums = {1, 7, 5, 1, 9, 2, 5, 1};
    // TreeNode* root = buildTree(houses, 0);
    ListNode *head = buildList(nums, 0);

    Solution sol;

    /* vector<int> result = sol.decode(encoded);
  for(int _r: result) 
    cout << _r << " ";
  cout << endl; */

    // sol.doQuery(functionCall, arr, inputs);
    int k = 2;
    vector<int> res = sol.nextLargerNodes(head);
    for (int i : res)
        cout << i << " ";
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