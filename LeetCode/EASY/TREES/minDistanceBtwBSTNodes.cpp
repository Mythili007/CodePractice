/*
    * https://leetcode.com/problems/minimum-distance-between-bst-nodes/
    * 783. Minimum Distance Between BST Nodes
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
    vector<int> v;
    void dfs(TreeNode *root)
    {
        if (root == NULL)
            return;
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }

    int minDiff()
    {
        int val = INT_MAX;
        for (int i = 1; i < v.size(); i++)
        {
            val = min(val, abs(v[i - 1] - v[i]));
        }
        return val;
    }

    int minDiffInBST(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        dfs(root);
        return minDiff();
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
    nums = {1, 0, 1, 0, 1, 0, 1};

    Solution sol;
    TreeNode *tree = buildTree(nums, 0);
    cout << sol.minDiffInBST(tree) << endl;
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