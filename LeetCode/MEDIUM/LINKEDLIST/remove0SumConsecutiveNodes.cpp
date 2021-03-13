/*
* https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
* 1171. Remove Zero Sum Consecutive Nodes from Linked List
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
    
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* tmp = head;
        ListNode* t1 = head;
        ListNode* prev = NULL;
        t1 = t1->next;
        while(tmp != NULL && t1 != NULL && t1->next != NULL){
            if(tmp->val == -(t1->val)){
                
            }
        }
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