/*
* https://leetcode.com/problems/range-sum-of-bst/
* 938. Range Sum of BST
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
    int sum = 0;
    //INORDER TRAVERSAL
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (root == NULL)
            return 0;

        rangeSumBST(root->left, low, high);
        if (root->val >= low && root->val <= high)
            sum += root->val;
        rangeSumBST(root->right, low, high);

        return sum;
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

TreeNode *buildTree(vector<int> nums, int ind)
{
    TreeNode *tmp = new TreeNode(nums[ind]); //10
    tmp->left = buildTree(nums, ind + 1);
    tmp->right = buildTree(nums, ind + 2);

    return tmp;
}

void _main()
{
    vector<int> nums = {10, 5, 15, 3, 7, 18};

    // TreeNode* root = buildTree(houses, 0);
    // TreeNode *root = buildTree(nums, 0);
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    // root->right->left = new TreeNode(nullptr);
    root->right->right = new TreeNode(18);
    // cout<<root->val<<endl;
    int low = 7;
    int high = 15;

    // printTree(root);
    cout << endl;
    Solution sol;
    int res = sol.rangeSumBST(root, low, high);
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