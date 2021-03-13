/*
* https://leetcode.com/problems/sum-root-to-leaf-numbers/
* 129. Sum Root to Leaf Numbers
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
    vector<vector<int>> vec;

    void dfs(TreeNode *root, vector<int> v)
    {
        if (root == NULL)
            return;
        cout << "root: " << root->val << endl;
        v.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            vec.push_back(v);
            return;
        }
        dfs(root->left, v);
        dfs(root->right, v);
    }

    //[[1,2],[1,3]]
    int addNum()
    {
        int sum = 0, s = 0;
        for (vector<int> i : vec)
        {
            int size = i.size() - 1;
            s = 0;
            for (int j : i)
            {
                s += (j * pow(10, size--));
                // size--;
            }
            sum += s;
        }
        return sum;
    }

    int sumNumbers(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        vector<int> vv;
        dfs(root, vv);
        return addNum();
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
    nums = {1, 2, 3, -1, 4, -1, 5};
    nums = {1, 2, 3};

    Solution sol;
    TreeNode *tree = buildTree(nums, 0);
    cout << sol.sumNumbers(tree) << endl;
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}