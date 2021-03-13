/*
* https://leetcode.com/problems/path-sum-ii/
* 113. Path Sum II
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
    vector<vector<int>> result;
    // vector<int> res;
    int sum = 0;
    void dfs(TreeNode *root, vector<int> res)
    {
        if (root == NULL)
            return;
        res.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            result.push_back(res);
            return;
        }
        dfs(root->left, res);
        dfs(root->right, res);
    }

    vector<vector<int>> validate(int targetSum)
    {
        vector<vector<int>> _vec;
        for (vector<int> i : result)
        {
            int sum = accumulate(i.begin(), i.end(), 0);
            cout<<sum<<endl;

            if (sum == targetSum)
                _vec.push_back(i);
        }
        return _vec;
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return {};
        // vector<int> res;
        vector<int> r;
        dfs(root, r);
        return validate(targetSum);
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
    nums = {1, 2, 3, -1, 5, -1, -1};
    nums = {5,4,8,11,-1,13,4,7,2,-1,-1,5,1};
    int targetSum = 22;
    Solution sol;
    TreeNode *tree = buildTree(nums, 0);

    vector<vector<int>> res = sol.pathSum(tree, targetSum);
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