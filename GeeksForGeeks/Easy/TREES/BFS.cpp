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
    void bfs(Node *root)
    {
        queue<Node *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            Node *tmp = Q.front();
            cout << tmp->data << " ";
            if (tmp->left != NULL)
                Q.push(tmp->left);

            if (tmp->right != NULL)
                Q.push(tmp->right);

            Q.pop();
        }
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
    // nums = {10, 20, 30, 40, 60};

    Solution sol;
    Node *tree = buildTree(nums, 0);
    // printTree(tree);
    sol.bfs(tree);
    // int leaves = sol.countNonLeafNodes(tree);
    // cout << leaves << " ";
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