/*
    * https://leetcode.com/problems/search-in-a-binary-search-tree/
    * 700. Search in a Binary Search Tree
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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == NULL)
            return NULL;
        if (root->val == val)
            return root;
        else
        {
            if (val > root->val)
                return searchBST(root->right, val);
            else
                return searchBST(root->left, val);
        }
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

/* TreeNode *buildBST(vector<int> arr, int left, int right)
{
    if (left < right)
        return NULL;
    
    int mid = left + (right - left) / 2;
    
    TreeNode *root = new TreeNode(arr[mid]);
    root->left = buildBST(arr, left, mid - 1);
    root->right = buildBST(arr, mid + 1, right);

    return root;
} */

TreeNode *buildTree(vector<int> nums, int ind)
{
    TreeNode *tmp = new TreeNode(nums[ind]); //10
    tmp->left = buildTree(nums, ind + 1);
    tmp->right = buildTree(nums, ind + 2);

    return tmp;
}

void _main()
{
    vector<int> nums = {3, 9, 7, 15, 20};

    Solution sol;
    TreeNode *tree = buildTree(nums, 0);
    int val = 2;
    // cout << tree->val << endl;
    TreeNode *res = sol.searchBST(tree, val);
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