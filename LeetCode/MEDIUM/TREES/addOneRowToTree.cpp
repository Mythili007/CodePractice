/*
* https://leetcode.com/problems/add-one-row-to-tree/
* 623. Add One Row to Tree
* Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d. The root node is at depth 1.
* The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1, 
* create two tree nodes with value v as N's left subtree root and right subtree root. And N's original left subtree should be the left subtree of the new left subtree root, 
* its original right subtree should be the right subtree of the new right subtree root. If depth d is 1 that means there is no depth d-1 at all, 
* then create a tree node with value v as the new root of the whole original tree, and the original tree is the new root's left subtree.
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
    void dfs(TreeNode *root, int v, int currD, int d)
    {
        if (root == NULL)
            return;

        if (currD == d - 1)
        {
            if (root->left != NULL)
            {
                TreeNode *tmp = root->left;
                root->left = new TreeNode(v);
                root->left->left = tmp;
            }

            if (root->right != NULL)
            {
                TreeNode *tmp = root->right;
                root->right = new TreeNode(v);
                root->right->right = tmp;
            }
        }
        else
        {
            dfs(root->left, v, currD + 1, d);
            dfs(root->right, v, currD + 1, d);
        }
    }

    TreeNode *addOneRow(TreeNode *root, int v, int d)
    {
        if (root == NULL)
            return root;

        if (d == 1)
        {
            TreeNode *newNode = new TreeNode(v);
            newNode->left = root;
            return newNode;
        }

        int currDepth = 1;

        dfs(root, v, currDepth, d);
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
    nums1 = {1, 2, 3};

    Solution sol;
    TreeNode *tree = buildTree(nums1, 0);
    TreeNode *res = sol.addOneRow(tree, 2, 2);
    printTree(res);
    // cout << res << endl;
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