/*
*
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

/**
 * Definition for a binary tree node.
 */
struct Node
{
    int data;
    Node *left;
    Node *right;

    /* Node(int data)
    {
        data = data;
        left = right = NULL;
    } */
};

Node *createNode(int val)
{
    Node *tmp = new Node;
    tmp->data = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

class Solution
{
public:
    vector<int> v;
    
    vector<int> leftView(Node *root)
    {
        // Your code here
        if (root == NULL)
            return {0};
        v.push_back(root->data);
        if (root->left)
        {
            leftView(root->left);
            if (!root->left->left && root->left->right)
                leftView(root->left->right);
        }

        return v;
    }
};

void printTree(Node *root)
{
    if (root == NULL)
        return;
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

Node *buildTree(vector<int> arr, int index)
{
    if (arr.size() <= index || arr[index] == -1)
        return NULL;

    Node *node = createNode(arr[index]);
    node->left = buildTree(arr, 2 * index + 1);
    node->right = buildTree(arr, 2 * index + 2);

    return node;
}

int _main(vector<int> nums)
{
    Solution sol;
    Node *tree = buildTree(nums, 0);
    // printTree(tree);
    vector<int> arr = sol.leftView(tree);
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

int main()
{

    int t = 1;
    cin >> t;
    vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
    nums = {1, 2, 3, 4, 5, 6, 7, -1, 8};
    nums = {10, 20, 30, 40, 60};
    nums = {1,2,-1,3,-1,-1,-1,4};
    nums = {2, 2, 13, 7, 10, 1, 10, 5, 2, -1, 14, 5, 11, 5, 5, 13};
    while (t-- > 0){
        
       return _main(nums);

    }

    return 0;
}