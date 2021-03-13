/*
* https://leetcode.com/problems/invert-binary-tree/
* 226. Invert Binary Tree
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
    /* void traverse(TreeNode *root, TreeNode *newNode)
    {
        if (root == NULL || newNode == NULL)
            return;

        if (root->left)
            newNode->right = root->left;

        if (root->right)
            newNode->left = root->right;

        traverse(root->left, newNode->right);
        traverse(root->right, newNode->left);
        // return newNode;
    } */

    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        root->right = left;
        root->left = right;

        return root;
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
    // nums1 = {1, 3, 4, 0, 5, -1, 7, -1, -1, -1, -1, -1, -1, 8, 9};
    Solution sol;
    TreeNode *tree = buildTree(nums1, 0);
    printTree(tree);
    cout << endl;
    TreeNode *newNode = sol.invertTree(tree);
    printTree(newNode);
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