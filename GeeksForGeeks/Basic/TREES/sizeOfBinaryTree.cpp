/*
* https://leetcode.com/problems/maximum-depth-of-binary-tree/
* 104. Maximum Depth of Binary Tree
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
    int getSize(Node *node)
    {
        stack<Node *> st;
        Node *curr = node;
        vector<int> arr;
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
            while (curr == NULL && !st.empty())
            {
                curr = st.top();
                st.pop();
                arr.push_back(curr->data);
                curr = curr->right;
            }
            if (curr == NULL && st.empty())
                break;
        }
        return arr.size();
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

void _main()
{
    vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
    // nums = {3, 4, 2};

    Solution sol;
    Node *tree = buildTree(nums, 0);
    // printTree(tree);
    int leaves = sol.getSize(tree);
    cout << leaves << " ";
    cout << endl;
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}