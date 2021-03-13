/*
* https://leetcode.com/problems/count-good-nodes-in-binary-tree/
* 1448. Count Good Nodes in Binary Tree
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
    int calculate(TreeNode *root, int val)
    {
        if (root == NULL)
            return 0;
        int x = (root->val >= val) ? 1 : 0;
        x += calculate(root->left, max(root->val, val));
        x += calculate(root->right, max(root->val, val));
        return x;
    }

    int goodNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return calculate(root, INT_MIN);
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
    nums = {2, -1, 9, -1, -1, 10, 8, -1, -1, -1, -1, -1, -1, 11};

    Solution sol;
    TreeNode *tree = buildTree(nums, 0);
    cout << sol.goodNodes(tree) << endl;
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