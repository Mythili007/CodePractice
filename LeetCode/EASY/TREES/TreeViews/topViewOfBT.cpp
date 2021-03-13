/*
* TOP VIEW OF A BINARY TREE
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
    vector<int> v;
    map<int, vector<int>> m;

    void dfs(TreeNode *root, int lvl)
    {
        if (root == NULL)
            return;

        if (m.find(lvl) == m.end())
            m[lvl] = {};

        m[lvl].push_back(root->val);
        dfs(root->left, lvl - 1);
        dfs(root->right, lvl + 1);
    }

    void store()
    {
        for (auto i : m)
        {
            v.push_back(i.second.front());
        }
    }

    vector<int> topView(TreeNode *root)
    {
        if (root == NULL)
            return {};
        int level = 0;
        dfs(root, level);
        store();
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
    nums1 = {3, 9, 20, -1, -1, 15, 7};
    nums1 = {1, 3, 4, 0, 5, -1, 7, -1, -1, -1, -1, -1, -1, 8, 9};
    nums1 = {1, 2, 3, -1, 4, 5, -1, 6, 7, 8};
    Solution sol;
    TreeNode *tree = buildTree(nums1, 0);
    // printTree(tree);
    vector<int> res = sol.topView(tree);
    for (int j : res)
        cout << j << " ";

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