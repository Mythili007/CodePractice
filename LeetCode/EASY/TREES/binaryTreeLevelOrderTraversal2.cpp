/*
* https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
* 107. Binary Tree Level Order Traversal II
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
    vector<vector<int>> v;
    map<int, vector<int>> m;
    void dfs(TreeNode *root, int level)
    {
        if (root == NULL)
            return;
        if (m.find(level) == m.end())
            m[level] = {};

        m[level].push_back(root->val);
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }

    void store_top_to_bottom()
    {
        for (auto i : m)
            v.push_back(i.second);
    }

    void store_bottom_to_top()
    {
        map<int, vector<int>>::reverse_iterator itr;
        for (itr = m.rbegin(); itr != m.rend(); itr++)
            v.push_back(itr->second);
    }

    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (root == NULL)
            return {};
        dfs(root, 0);
        store_bottom_to_top();
        return v;
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

    Solution sol;
    TreeNode *tree1 = buildTree(nums1, 0);

    vector<vector<int>> res = sol.levelOrderBottom(tree1);

    for (vector<int> i : res)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

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