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
    vector<int> postOrder(Node *root)
    {
        // Your code here
        if (root == NULL)
            return {0};
        vector<int> arr;
        stack<Node *> st;
        Node *curr = root;

        while (curr != NULL || !st.empty())
        {
            //if curr is not null then push to stack
            if (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                Node *tmp = st.top()->right;
                if (tmp == NULL)
                {
                    tmp = st.top();
                    st.pop();
                    arr.push_back(tmp->data);
                    while (!st.empty() && tmp == st.top()->right)
                    {
                        tmp = st.top();
                        st.pop();
                        arr.push_back(tmp->data);
                    }
                }
                else
                {
                    curr = tmp;
                }
            }
        }
        return arr;
    }
};

void printTree(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printTree(root->left);
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
    nums = {1, 4, -1, 4, 2};
    nums = {1, 10, 39, 5};
    Solution sol;
    Node *tree = buildTree(nums, 0);
    // printTree(tree);
    vector<int> arr = sol.postOrder(tree);
    for (int i : arr)
        cout << i << " ";
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