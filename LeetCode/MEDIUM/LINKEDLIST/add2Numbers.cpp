/*
* https://leetcode.com/problems/add-two-numbers/
* 2. Add Two Numbers
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
    ListNode *addNumsWithCarry(ListNode *l1, ListNode *l2, int carry)
    {
        int sum = 0;
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        if(t1 == NULL && t2 == NULL && carry == 0)
            return NULL;
        
        if(t1 == NULL && t2 == NULL && carry != 0)
            return new ListNode(carry);

        int data1 = (t1 == NULL) ? 0 : t1->val;
        int data2 = (t2 == NULL) ? 0 : t2->val;
        
        sum = data1 + data2 + carry;
        carry = sum/10;
        sum = sum%10;
        
        ListNode* newNode = new ListNode(sum);

        ListNode* t1_next = t1 ? t1->next : NULL;
        ListNode* t2_next = t2 ? t2->next : NULL;

        newNode->next = addNumsWithCarry(t1->next, t2->next, carry);;

        return newNode;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* newHead = addNumsWithCarry(l1, l2, carry);
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