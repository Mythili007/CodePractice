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
    int height = 0;
    // vector<int> v;
    vector<vector<int>> res;
    void traverse(TreeNode *root, int stem)
    {
        if (root == NULL)
            return;
        height = max(height, stem);

        traverse(root->left, stem + 1);
        traverse(root->right, stem + 1);
    }

    void printVector()
    {
        for (vector<int> i : res)
        {
            for (int j : i)
                cout << j << " ";
            cout << endl;
        }
    }

    int maxDepth(TreeNode *root) // depth means nodes, height means stems
    {
        traverse(root, 0, {});
        printVector();
        return height;
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
    cout << sol.maxDepth(tree) << endl;
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