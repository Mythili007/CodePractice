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

    void swap(ListNode* first, ListNode* second){
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }

    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* t1 = head;
        while(t1 != NULL && t1->next != NULL){
            swap(t1, t1->next);
            t1 = t1->next->next;
        }
        // t1 = (t1->next && t1->next->next) ? t1->next->next : NULL;
        // swapPairs(t1->next->next); 
        return head;
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
    // TreeNode* root = buildTree(houses, 0);
    ListNode *head = buildList(nums, 0);

    Solution sol;

    /* vector<int> result = sol.decode(encoded);
  for(int _r: result) 
    cout << _r << " ";
  cout << endl; */

    // sol.doQuery(functionCall, arr, inputs);

    cout << sol.swapPairs(head) << endl;
    sol.printList(head);
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}