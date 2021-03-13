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
    map<int, int> m;
    vector<vector<int>> vec;
    void dfs(Node *root, int d, vector<int> v, int i = 0)
    {
        if (root == NULL)
            return;
        v.push_back(root->data);
        if (root->left == NULL && root->right == NULL)
        {
            vec.push_back(v);
            return;
        }

        dfs(root->left, d - 1, v, i);
        dfs(root->right, d + 1, v, i);
    }
    void reset()
    {
        m = {};
        // v = {};
    }

    void printVec(vector<int> vv, int tmp)
    {
        if (tmp == 0)
            cout << vv[0] << " ";
        else
            cout << vv[0] << " " << vv[vv.size() - 1] << " ";
    }

    void pathCounts(Node *root)
    {
        //Your code here
        if (root == NULL)
            return;
        vector<int> res;
        dfs(root, 0, res, 0);
        for (vector<int> a : vec)
        {
            int s = a.size();
            m[s]++;
        }
        for (auto i : m)
        {
            cout << i.first << " " << i.second << " $"
                 << " ";
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
    nums = {3, 2, 4};
    nums = {10, 20 ,30, 40,60};
    Solution sol;
    Node *tree = buildTree(nums, 0);
    // printTree(tree);
    sol.pathCounts(tree);
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