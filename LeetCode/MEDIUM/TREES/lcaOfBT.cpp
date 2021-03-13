/*
* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
* 236. Lowest Common Ancestor of a Binary Tree
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
    bool isPresent(TreeNode *root, TreeNode *node)
    {
        if (root == NULL)
            return false;
        if (root->val == node->val)
            return true;
        else
            return isPresent(root->left, node) || isPresent(root->right, node);
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL || root == p || root == q)
            return root;

        // bool left = isPresent(root->left, p);
        // bool right = isPresent(root->right, q);
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root;
        else if (left && !right)
            return left;
        else
            return right;
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
    nums = {3, 1, 4, 3, -1, 1, 5};
    nums = {9, -1, 1};
    nums = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    nums = {1, 2, 3};
    TreeNode *p = new TreeNode(5);
    TreeNode *q = new TreeNode(1);
    *p = 2, *q = 3;
    Solution sol;
    TreeNode *tree = buildTree(nums, 0);
    TreeNode *res = sol.lowestCommonAncestor(tree, p, q);
    cout << res->val << endl;
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