/*
* https://leetcode.com/problems/binary-tree-paths/
* 257. Binary Tree Paths
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<string> v;
    map<int, vector<int>> m;
    int left = INT_MAX;
    int right = INT_MIN;

    void dfs(TreeNode *root, vector<string> &res, string t)
    {
        if (root->left == NULL && root->right == NULL)
        {
            res.push_back(t);
            return;
        }

        if (root->left)
            dfs(root->left, res, t + "->" + to_string(root->left->val));

        if (root->right)
            dfs(root->right, res, t + "->" + to_string(root->right->val));
    }
    /* string makeStringFromVector(vector<int> &v)
    {
        string st;
        for (int i = 0; i < v.size(); i++)
        {
            st += to_string(v[i]);
            if (i < v.size() - 1)
                st += "->";
        }
        return st;
    } */

    /* void store()
    {
        for (auto i : m)
        {
            string st = makeStringFromVector(i.second);
            v.push_back(st);
        }
    } */

    /* void print(int v[])
    {
        int a = 5;
        for (int i = 0;i<a;i++)
            cout << v[i] << " ";
    } */

    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (root == NULL)
            return {};
        vector<string> res;
        dfs(root, res, to_string(root->val));
        return res;
    }
};

void printTree(TreeNode *root)
{
    if (root == NULL)
        return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

TreeNode *buildTree(vector<int> arr, int index)
{
    if (arr.size() <= index || arr[index] == -1)
        return NULL;

    TreeNode *node = new TreeNode(arr[index]);
    node->left = buildTree(arr, 2 * index + 1);
    node->right = buildTree(arr, 2 * index + 2);

    return node;
}

void _main()
{
    vector<int> nums = {3, 9, 20, -101, -101, 15, 7};
    nums = {1, 2, 3, -1, 5, -1, -1};

    Solution sol;
    TreeNode *tree = buildTree(nums, 0);

    vector<string> res = sol.binaryTreePaths(tree);
    for (string i : res)
        cout << i << " ";
    cout << endl;
    // printTree(tree);
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}