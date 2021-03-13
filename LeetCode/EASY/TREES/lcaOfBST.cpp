/*
* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
* 235. Lowest Common Ancestor of a Binary Search Tree
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
    map<TreeNode *, vector<int>> m;
    void traverse(TreeNode *root, vector<int> v)
    {
        if (root == NULL)
            return;
        v.push_back(root->val);
        if (m.find(root) == m.end())
            m[root] = {};

        if (root->left == NULL && root->right == NULL)
        {
            m[root] = v;
            return;
        }
        traverse(root->left, v);
        traverse(root->right, v);
    }

    void getAncestor(TreeNode *p, TreeNode *q)
    {
        vector<int> a = m[p];
        vector<int> b = m[q];

        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < b.size(); j++)
            {
                cout << "a[i]: " << a[i] << "   b[j]: " << b[j] << endl;
            }
        }
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        vector<int> v;
        traverse(root, v);
        getAncestor(p, q);
        cout << endl;
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
    vector<int> nums = {3, 9, 20, -101, -101, 15, 7};
    nums = {1, 2, 3, 4, 5, 6, 7};
    nums = {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
    TreeNode *p = new TreeNode(2);
    TreeNode *q = new TreeNode(8);

    Solution sol;
    TreeNode *tree = buildTree(nums, 0);
    TreeNode* res = sol.lowestCommonAncestor(tree, p, q);
    cout<<res<<endl;
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}