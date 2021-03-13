/*
* https://leetcode.com/problems/leaf-similar-trees/
* 872. Leaf-Similar Trees
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
    void leafSequence(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
            v.push_back(root->val);

        if (root->left)
            leafSequence(root->left, v);

        if (root->right)
            leafSequence(root->right, v);
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL || root2 == NULL)
            return false;
        vector<int> a;
        leafSequence(root1, a);
        vector<int> b;
        leafSequence(root2, b);
        return a == b;
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
    vector<int> nums2 = {3, 5, 1, 6, 7, 4, 2, -1, -1, -1, -1, -1, -1, 9, 8};

    Solution sol;
    TreeNode *tree1 = buildTree(nums1, 0);
    TreeNode *tree2 = buildTree(nums2, 0);

    cout << sol.leafSimilar(tree1, tree2) << endl;
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