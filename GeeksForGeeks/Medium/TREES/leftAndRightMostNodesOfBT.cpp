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
    map<int, vector<int>> m;
    vector<int> v;
    void dfs(Node *root, int d)
    {
        if (root == NULL)
            return;
        if (m.find(d) == m.end())
            m[d] = {};
        m[d].push_back(root->data);
        dfs(root->left, d + 1);
        dfs(root->right, d + 1);
    }
    void reset()
    {
        m = {};
        v = {};
    }

    void printVec(vector<int> vv, int tmp)
    {
        if (tmp == 0)
            cout << vv[0] << " ";
        else
            cout << vv[0] << " " << vv[vv.size()-1] << " ";
    }

    void printCorner(Node *root)
    {

        // Your code goes here
        reset();
        if (root == NULL)
            return;
        dfs(root, 0);
        for (auto i : m)
        {
            if (i.first == 0)
                printVec(i.second, 0);
            else
                printVec(i.second, 1);
        }

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
    nums = {1, 2, 3, 4, 5, 6, 7};
    Solution sol;
    Node *tree = buildTree(nums, 0);
    // printTree(tree);
    sol.printCorner(tree);
    // for (int i : arr)
    //     cout << i << " ";
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