/*
* https://leetcode.com/problems/minimum-depth-of-binary-tree/
* 111. Minimum Depth of Binary Tree
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
    vector<vector<int>> res;
    vector<int> v;
    int min_val = INT_MAX;
    void dfs(TreeNode *root, int cnt)
    {
        if (root == NULL)
            return;
        cnt++;
        if (root->left == NULL && root->right == NULL)
        {
            min_val = min(min_val, cnt);
            return;
        }
        dfs(root->left, cnt);
        dfs(root->right, cnt);
    }

    /* int getMinDepth()
    {
        int min_val = INT_MAX;
        for (vector<int> i : res)
        {
            int s = i.size();
            min_val = min(min_val, s);
        }
        return min_val;
    } */

    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        dfs(root, 0);
        return min_val;
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
    nums = {1, 2, 3, 4, 5};
    nums = {3, 9, 20, -1, -1, 15, 7};
    Solution sol;
    TreeNode *tree = buildTree(nums, 0);

    cout << sol.minDepth(tree) << endl;
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