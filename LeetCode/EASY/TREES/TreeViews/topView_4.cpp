/*
* RIGHT VIEW OF A BINARY TREE
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
    map<int, vector<int>> mp;
    vector<int> vec;

    void traverse(TreeNode *root, int lvl)
    {
        if (root == NULL)
            return;

        if (mp.find(lvl) == mp.end())
            mp[lvl] = {};
        mp[lvl].push_back(root->val);

        traverse(root->left, lvl - 1);
        traverse(root->right, lvl + 1);
    }

    void store()
    {
        for (auto i : mp)
            vec.push_back(i.second[0]);
    }

    vector<int> topView(TreeNode *root)
    {
        if (root == NULL)
            return {};

        traverse(root, 0);
        store();
        return vec;
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
    nums = {3, 5, 1, 6, 2, 9, 8};

    Solution sol;
    TreeNode *tree = buildTree(nums, 0);

    vector<int> res = sol.topView(tree);
    for (int i : res)
    {
        cout << i << " ";
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