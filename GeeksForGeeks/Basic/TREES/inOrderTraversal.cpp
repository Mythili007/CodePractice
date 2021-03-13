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
    vector<int> inOrder(Node *root)
    {
        // Your code here
        if (root == NULL)
            return {0};
        vector<int> arr;
        stack<Node *> st;
        Node *curr = root;
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
            while (!st.empty() && curr == NULL)
            {
                curr = st.top();
                st.pop();
                arr.push_back(curr->data);
                curr = curr->right;
            }
            if (curr == NULL && st.empty())
                break;
        }

        return arr;
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
    nums = {1, 10, 39, 5};

    Solution sol;
    Node *tree = buildTree(nums, 0);
    // printTree(tree);
    vector<int> arr = sol.inOrder(tree);
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