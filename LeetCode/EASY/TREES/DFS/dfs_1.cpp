/*
* LEVEL ORDER TRAVERSAL USING DFS
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
    map<int, vector<int>> m;
    vector<vector<int>> v;

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

    void store()
    {
        for (auto i : m)
            v.push_back(i.second);
    }

    vector<vector<int>> levelOrderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};
        dfs(root, 0);
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
    vector<int> nums = {3, 9, 20, -101, -101, 15, 7};
    nums = {1, 3, 4, 0, 5, -1, 7, -1, -1, -1, -1, -1, -1, 8, 9};
    // nums = {1, 2, 3, -1, 5, -1, -1};

    Solution sol;
    TreeNode *tree = buildTree(nums, 0);

    vector<vector<int>> res = sol.levelOrderTraversal(tree);
    for (vector<int> i : res)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;
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