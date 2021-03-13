/*
* https://leetcode.com/problems/find-mode-in-binary-search-tree/
* 501. Find Mode in Binary Search Tree
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
    map<int, int> m;
    vector<int> v;
    void inOrder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inOrder(root->left);
        m[root->val]++;
        inOrder(root->right);
    }

    void store()
    {
        int maxx = INT_MIN;
        for (auto i : m)
            maxx = max(maxx, i.second);

        for (auto i : m)
        {
            if (maxx == i.second)
                v.push_back(i.first);
        }
    }

    vector<int> findMode(TreeNode *root)
    {
        if (root == NULL)
            return {};
        inOrder(root);
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
    vector<int> nums = {3, 5, 1, 6, 2, 9, 8, -1, -1, 7, 4};
    // nums = {1, 2, 3};
    nums = {1, 3, 4, 0, 4, -1, 7, -1, -1, -1, -1, -1, -1, 8, 9};

    Solution sol;
    TreeNode *tree = buildTree(nums, 0);

    vector<int> res = sol.findMode(tree);
    for (int i : res)
        cout << i << " ";
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