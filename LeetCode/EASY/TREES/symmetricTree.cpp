/*
* https://leetcode.com/problems/symmetric-tree/
* 101. Symmetric Tree
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
    bool areLeftAndRightSubtreesEqual(TreeNode *root1, TreeNode *root2)
    {
        if (root1 != root2)
            return false;
        return areLeftAndRightSubtreesEqual(root1->left, root2->right) && areLeftAndRightSubtreesEqual(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return areLeftAndRightSubtreesEqual(root, root);
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
    vector<int> nums = {3, 5, 1, 6, 2, 9, 8, -1, -1, 7, 4};
    nums = {1, 2, 2, 3, 4, 4, 3};
    nums = {1, 2, 2, -1, 3, -1, 3};
    Solution sol;
    TreeNode *tree = buildTree(nums, 0);

    bool res = sol.isSymmetric(tree);
    cout << res << endl;

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