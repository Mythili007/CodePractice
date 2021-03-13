/*
    * https://leetcode.com/problems/subtree-of-another-tree/
    * 572. Subtree of Another Tree
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
    bool areSame(TreeNode *s, TreeNode *t)
    {
        if (s == NULL && t == NULL)
            return true;
        if (s == NULL || t == NULL)
            return false;

        if (s->val == t->val)
            return areSame(s->left, t->left) && areSame(s->right, t->right);
        else
            return false;
    }

    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (s == NULL && t == NULL)
            return true;
        if (s == NULL || t == NULL)
            return false;
        if (areSame(s, t))
            return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
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
    vector<int> s = {3, 4, 5, 1, 2};
    vector<int> t = {4, 1, 2};

    Solution sol;
    TreeNode *tree_s = buildTree(s, 0);
    TreeNode *tree_t = buildTree(t, 0);
    cout << sol.isSubtree(tree_s, tree_t) << endl;
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