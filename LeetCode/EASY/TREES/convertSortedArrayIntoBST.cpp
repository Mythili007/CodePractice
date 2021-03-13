/*
    * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
    * 653. Two Sum IV - Input is a BST
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
    /* TreeNode *buildBST(vector<int>& arr, int left, int right)
    {
        if (left < right)
            return NULL;
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(arr[mid]);
        root->left = buildBST(arr, left, mid - 1);
        root->right = buildBST(arr, mid + 1, right);
        return root;
    } */
};

void printTree(TreeNode *root)
{
    if (root == NULL)
        return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

TreeNode *buildBST(vector<int> arr, int left, int right)
{
    if (left < right)
        return NULL;
    
    int mid = left + (right - left) / 2;
    
    TreeNode *root = new TreeNode(arr[mid]);
    root->left = buildBST(arr, left, mid - 1);
    root->right = buildBST(arr, mid + 1, right);

    return root;
}

void _main()
{
    vector<int> nums = {3, 9, 7, 15, 20};

    Solution sol;
    TreeNode *tree = buildBST(nums, 0, (nums.size() - 1));
    // cout << tree->val << endl;
    printTree(tree);
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}