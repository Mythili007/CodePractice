/*
* https://leetcode.com/problems/univalued-binary-tree/
* 965. Univalued Binary Tree
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
    int val = 0;

    bool check(TreeNode *root)
    {
        if (root == NULL)
            return true;
        if (root->val != val)
            return false;
        return check(root->left) && check(root->right);
    }

    bool isUnivalTree(TreeNode *root)
    {
        if (root == NULL)
            return true;
        val = root->val;
        return check(root);
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
    vector<int> nums1 = {3, 5, 1, 6, 2, 9, 8, -1, -1, 7, 4};
    nums1 = {3, 9, 20, -1, -1, 15, 7};
    nums1 = {1, 3, 4, 0, 5, -1, 7, -1, -1, -1, -1, -1, -1, 8, 9};
    nums1 = {1, 1, 1};
    Solution sol;
    TreeNode *tree = buildTree(nums1, 0);
    // printTree(tree);
    bool res = sol.isUnivalTree(tree);
    cout << res << " ";

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