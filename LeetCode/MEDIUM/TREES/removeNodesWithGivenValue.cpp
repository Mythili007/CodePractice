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
    void traverse(TreeNode *root, int target)
    {
        if (root == NULL)
            return;
        if (root->left && root->left->val == target && !root->left->left && !root->left->right)
        {
            root->left = NULL;
            return;
        }
        else if (root->right && root->right->val == target && !root->right->left && !root->right->right)
        {
            root->right = NULL;
            return;
        }

        traverse(root->left, target);
        traverse(root->right, target);
    }

    bool isLeafNode(TreeNode *root)
    {
        if (!root->left && !root->right)
            return true;
        else
            return false;
    }

    bool isTargetPresent(TreeNode *root, int target)
    {
        if (root == NULL)
            return false;
        if (root->val == target && isLeafNode(root))
            return true;
        else
            return isTargetPresent(root->left, target) || isTargetPresent(root->right, target);
    }

    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        if (root == NULL)
            return root;

        if (root->left)
            root->left = removeLeafNodes(root->left, target);
        if (root->right)
            root->right = removeLeafNodes(root->right, target);

        return (root->left == root->right && root->val == target) ? NULL : root;
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
    nums = {1, 2, 3, 2, -1, 2, 4};
    nums = {1, 3, 3, 3, 2};
    nums = {1, 1, 1};
    Solution sol;
    TreeNode *tree = buildTree(nums, 0);
    int target = 1;
    TreeNode *node = sol.removeLeafNodes(tree, target);

    printTree(node);
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}