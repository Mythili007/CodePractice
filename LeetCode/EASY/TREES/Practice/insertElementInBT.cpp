/*
* https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
* 671. Second Minimum Node In a Binary Tree
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
    void insertElement_recursive(TreeNode *root, int data, bool flag)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            root->left = new TreeNode(data);
            flag = true;
        }
        cout<<"flag: "<<flag<<endl;
        if(!flag)
        {
            insertElement_recursive(root->left, data, flag);
            insertElement_recursive(root->right, data, flag);
        }
    }

    TreeNode *insertElement(TreeNode *root, int data)
    {
        if (root == NULL)
            return new TreeNode(data);
        TreeNode *tmp = root;
        traverse(tmp, data, false);
        return root;
    }

   TreeNode *insertElement_iterative(TreeNode *root, int data)
    {
        if (root == NULL)
            return new TreeNode(data);
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *tmp = q.front();
            if (tmp->left)
                q.push(tmp->left);
            else {
                tmp->left = new TreeNode(data);
                break;
            }
            if (tmp->right)
                q.push(tmp->right);
             else{
                tmp->right = new TreeNode(data);
                break;
            }
            q.pop();
        }
        return false;
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
    nums = {1, 2, 2, 3, 4, 4, 3};
    nums = {1, 2, 2, -1, 3, -1, 3};
    nums = {1, 2, 3};
    Solution sol;
    TreeNode *tree = buildTree(nums, 0);

    TreeNode *res = sol.insertElement_recursive(tree, 6);
    printTree(res);
    // cout << res << endl;

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