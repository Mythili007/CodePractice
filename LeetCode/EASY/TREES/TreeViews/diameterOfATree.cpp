/*
* DIAMETER A BINARY TREE - PRACTICE
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
    int left_max = INT_MAX;
    int right_max = INT_MIN;

    void dfs(TreeNode *root, int d)
    {
        if (root == NULL)
            return;

        if (d < left_max)
            left_max = d;
        if (d > right_max)
            right_max = d;

        dfs(root->left, d - 1);
        dfs(root->right, d + 1);
    }

    int diameterOfTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int d = 0;
        dfs(root, d);
        d = abs(right_max - left_max + 1);
        return d;
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
    /* 
                 1
              3     4
           0    5      7
                    8     9
     */
    // nums = {1, 2, 3};

    Solution sol;
    TreeNode *tree = buildTree(nums, 0);

    int res = sol.diameterOfTree(tree);
    cout << res << " ";
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