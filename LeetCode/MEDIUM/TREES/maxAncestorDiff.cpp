/*
* https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
* 1026. Maximum Difference Between Node and Ancestor
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
    // vector<int> vec;
    vector<vector<int>> res;
    int maxDiff = 0;
    void traverse(TreeNode *root, int lvl, vector<int> vec)
    {
        if (root == NULL)
            return;
        /* vec.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            res.push_back(vec);
            return;
        } */
        maxDiff = max(maxDiff, abs(maxDiff-root->val));
        traverse(root->left, lvl - 1, vec);
        traverse(root->right, lvl + 1, vec);
    }

    /* void getDiff()
    {
        for (vector<int> i : res)
        {
            sort(i.begin(), i.end());
            maxDiff = max(maxDiff, abs(i[0] - i[i.size() - 1]));
        }
    } */

    int maxAncestorDiff(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        vector<int> v;
        traverse(root, 0, v);
        // getDiff();
        return maxDiff;
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
    nums = {8,3,10,1,6,-1,14,-1,-1,4,7,13};
    /* 
                     8
                3         10
            1       6           14
                4       7    13   
     */

    Solution sol;
    TreeNode *tree = buildTree(nums, 0);

    int _res = sol.maxAncestorDiff(tree);
    cout << _res << endl;
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}