/*
    *https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
    * 1022. Sum of Root To Leaf Binary Numbers
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
    vector<string> vec_str;
    void dfs(TreeNode *root, string path)
    {
        if (root == NULL)
            return;
        path += to_string(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            vec_str.push_back(path);
            return;
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }

    int binaryToDecimal(string s)
    {
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            sum = sum << 1;
            sum += (s[i] - '0');
        }

        return sum;
    }

    int sumRootToLeaf(TreeNode *root)
    {
        // Code here
        if (root == NULL)
            return 0;
        dfs(root, "");
        int res = 0;
        for (string st : vec_str)
            res += binaryToDecimal(st);

        return res;
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
    nums = {1, 0, 1, 0, 1, 0, 1};

    Solution sol;
    TreeNode *tree = buildTree(nums, 0);
    cout << sol.sumRootToLeaf(tree) << endl;
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