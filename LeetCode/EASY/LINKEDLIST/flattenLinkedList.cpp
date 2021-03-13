/*
* Geeks for Geeks
* Add 1 to a number represented as linked list 
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

// Definition for singly-linked list.
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

class Solution
{
public:
    void printList(Node *prev)
    {
        while (prev != NULL)
        {
            cout << prev->data << " ";
            prev = prev->next;
        }
        cout << endl;
    }

    void swap(Node* first, Node* second){
        int tmp = first->data;
        first->data = second->data;
        second->data = tmp;
    }

    Node* flatList(Node* head){
        if(head == NULL) return NULL;

        Node* m = head;
        Node* t1 = head->next;
        Node* t2 = head;
        while(t2->bottom!=NULL){
            t2->next = t2->bottom;
            t2->bottom = NULL;
            t2 = t2->next;
        }
        t2->next = flatList(t1);
        
        return m;
    }
    
    Node* sortList(Node* head){
        bool swapped = false;
        do
        {
            swapped = false;
            Node *temp = head;
            while (temp != NULL && temp->next != NULL)
            {
                if (temp->data > temp->next->data)
                {
                    swap(temp, temp->next);
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);

        return head;
    }

    Node* nextToBottom(Node* head){
        if(head == NULL) return NULL;
        Node* tmp = head;
        Node* tmp2 = tmp->next;
        tmp->bottom = tmp2;
        tmp->next = NULL;
        tmp2 = nextToBottom(tmp2);

        return tmp;
    }

    Node* flattenList(Node* head){
        Node* t1 = flatList(head);
        Node* newNode = sortList(t1);
        Node* newNewNode = nextToBottom(newNode);
        return newNewNode;
    }

};

Node *buildList(vector<int> nums, int ind)
{
    if (ind == nums.size())
        return NULL;
    Node *tmp = new Node(nums[ind]);
    tmp->next = buildList(nums, ind + 1);

    // ListNode* tmp = new ListNode(nums[ind], buildList(nums, ind+1));

    return tmp;
}


// 5 -> 10 -> 19 -> 28
// |     |     |     | 
// 7     20    22   35
// |           |     | 
// 8          50    40
// |                 | 
// 30               45

void _main()
{
    // vector<int> nums = {1, 2, 3};
    // TreeNode* root = buildTree(houses, 0);
    // Node *head = buildList(nums, 0);
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(20);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    Solution sol;

    /* vector<int> result = sol.decode(encoded);
  for(int _r: result) 
    cout << _r << " ";
  cout << endl; */

    // sol.doQuery(functionCall, arr, inputs);
    Node* newHead = sol.flattenList(head);
    sol.printList(newHead);
    // cout << sol.addOne(head) << endl;
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}