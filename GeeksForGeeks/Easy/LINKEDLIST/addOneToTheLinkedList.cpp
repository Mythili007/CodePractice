/*
* Geeks for Geeks
* Add 1 to a number represented as linked list 
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

    ListNode *createRev(ListNode *ori)
    {
        list<int> ll;
        ll.push_back(10);
        
        if (ori == NULL)
            return ori;
        ListNode *head2 = new ListNode(ori->val);
        ListNode *t2 = head2, *t1 = ori;
        t1 = t1->next;
        while (t1 != NULL)
        {
            ListNode *tmp = new ListNode(t1->val);
            tmp->next = t2;
            t2 = tmp;
            t1 = t1->next;
        }
        head2 = t2;
        return head2;
    }
    ListNode *helper(ListNode *head)
    {
        int carry = 1, sum = 0;
        ListNode *tmp = head, *tmp1;
        while (tmp != NULL)
        {
            sum = carry + (tmp->val);
            carry = (sum >= 10) ? 1 : 0;
            sum = sum % 10;
            tmp->val = sum;
            tmp1 = tmp;
            tmp = tmp->next;
        }
        if(carry > 0)
            tmp1->next = new ListNode(carry);
        return head;
    }

    ListNode *addOne(ListNode *head)
    {
        // Your Code here
        // return head of list after adding one
        head = createRev(head);
        head = helper(head);
        return createRev(head);
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
    vector<int> nums = {1, 2, 3};
    // TreeNode* root = buildTree(houses, 0);
    ListNode *head = buildList(nums, 0);

    Solution sol;

    /* vector<int> result = sol.decode(encoded);
  for(int _r: result) 
    cout << _r << " ";
  cout << endl; */

    // sol.doQuery(functionCall, arr, inputs);

    cout << sol.addOne(head) << endl;
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}